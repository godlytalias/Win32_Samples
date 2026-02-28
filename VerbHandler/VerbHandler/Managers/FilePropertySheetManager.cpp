#include "pch.h"
#include "FilePropertySheetManager.h"
#include "RecycleBinItemPropertySheetManager.h"
#include "../Presenters/FilePropertySheetPresenter.h"
#include <shlwapi.h>
#include <strsafe.h>
#include <propkey.h>
#include <propsys.h>
#include <knownfolders.h>
#include <shlobj.h>

namespace PropertiesVerb
{
    FilePropertySheetManager::FilePropertySheetManager(IShellItem* psi)
    {
        if (psi)
        {
            _psi = psi;
            psi->QueryInterface(IID_PPV_ARGS(&_psi2));
        }
    }

    std::unique_ptr<FilePropertySheetManager> FilePropertySheetManager::Create(IShellItem* psi)
    {
        if (psi && IsRecycleBinItem(psi))
        {
            return std::unique_ptr<FilePropertySheetManager>(new RecycleBinItemPropertySheetManager(psi));
        }
        return nullptr;
    }

    void FilePropertySheetManager::CreateAndShow(IShellItem* psi)
    {
        auto manager = Create(psi);
        if (manager)
        {
            manager->PopulateValueSet();
            std::wstring serialized = manager->SerializeValueSet();
            FilePropertySheetPresenter::Show(serialized);
        }
    }

    bool FilePropertySheetManager::IsRecycleBinItem(IShellItem* psi)
    {
        Microsoft::WRL::ComPtr<IShellItem> psiParent;
        if (FAILED(psi->GetParent(&psiParent)))
        {
            return false;
        }

        Microsoft::WRL::ComPtr<IShellItem> psiRecycleBin;
        if (FAILED(SHGetKnownFolderItem(FOLDERID_RecycleBinFolder, KF_FLAG_DEFAULT, nullptr, IID_PPV_ARGS(&psiRecycleBin))))
        {
            return false;
        }

        int order = 0;
        if (SUCCEEDED(psiParent->Compare(psiRecycleBin.Get(), SICHINT_CANONICAL, &order)))
        {
            return order == 0;
        }
        return false;
    }

    const std::map<std::wstring, std::wstring>& FilePropertySheetManager::GetValueSet() const
    {
        return _valueSet;
    }

    // Populates some of the generic file property values.
    void FilePropertySheetManager::PopulateValueSet()
    {
        PopulateFileName();
        PopulateFileType();
        PopulateFileSize();
        PopulateCreatedDate();
        PopulateAttributes();
        PopulateIconPath();
    }

    void FilePropertySheetManager::PopulateFileName()
    {
        if (!_psi)
        {
            return;
        }

        PWSTR pszName = nullptr;
        if (SUCCEEDED(_psi->GetDisplayName(SIGDN_NORMALDISPLAY, &pszName)))
        {
            _fileName = pszName;
            CoTaskMemFree(pszName);
        }
    }

    void FilePropertySheetManager::PopulateFileType()
    {
        if (!_psi2)
        {
            return;
        }

        PWSTR pszValue = nullptr;
        if (SUCCEEDED(_psi2->GetString(PKEY_ItemTypeText, &pszValue)))
        {
            _valueSet[L"FileType"] = pszValue;
            CoTaskMemFree(pszValue);
        }
    }

    void FilePropertySheetManager::PopulateFileSize()
    {
        if (!_psi2)
        {
            return;
        }

        ULONGLONG ullSize = 0;
        if (SUCCEEDED(_psi2->GetUInt64(PKEY_Size, &ullSize)))
        {
            WCHAR szSize[64];
            StrFormatByteSizeW(static_cast<LONGLONG>(ullSize), szSize, ARRAYSIZE(szSize));
            _valueSet[L"FileSize"] = szSize;
        }
    }

    void FilePropertySheetManager::PopulateCreatedDate()
    {
        if (!_psi2)
        {
            return;
        }

        FILETIME ft = {};
        if (SUCCEEDED(_psi2->GetFileTime(PKEY_DateCreated, &ft)))
        {
            _valueSet[L"CreatedDate"] = FormatFileTime(ft);
        }
    }

    void FilePropertySheetManager::PopulateAttributes()
    {
        if (!_psi2)
        {
            return;
        }

        ULONG dwAttributes = 0;
        if (FAILED(_psi2->GetUInt32(PKEY_FileAttributes, &dwAttributes)))
        {
            return;
        }

        struct { ULONG flag; PCWSTR name; } attrs[] =
        {
            { FILE_ATTRIBUTE_READONLY,   L"READONLY" },
            { FILE_ATTRIBUTE_ARCHIVE,    L"ARCHIVE" },
            { FILE_ATTRIBUTE_HIDDEN,     L"HIDDEN" },
            { FILE_ATTRIBUTE_COMPRESSED, L"COMPRESSED" },
            { FILE_ATTRIBUTE_ENCRYPTED,  L"ENCRYPTED" },
        };

        std::wstring result;
        for (const auto& attr : attrs)
        {
            if (dwAttributes & attr.flag)
            {
                if (!result.empty())
                {
                    result += L", ";
                }
                result += attr.name;
            }
        }

        _valueSet[L"Attributes"] = result.empty() ? L"(none)" : result;
    }

    void FilePropertySheetManager::PopulateIconPath()
    {
        if (!_psi)
        {
            return;
        }

        Microsoft::WRL::ComPtr<IPersistIDList> pPersist;
        if (FAILED(_psi->QueryInterface(IID_PPV_ARGS(&pPersist))))
        {
            return;
        }

        PIDLIST_ABSOLUTE pidlFull = nullptr;
        if (FAILED(pPersist->GetIDList(&pidlFull)) || !pidlFull)
        {
            return;
        }

        Microsoft::WRL::ComPtr<IShellFolder> pParentFolder;
        PCUITEMID_CHILD pidlChild = nullptr;
        HRESULT hr = SHBindToParent(pidlFull, IID_PPV_ARGS(&pParentFolder), &pidlChild);
        if (SUCCEEDED(hr))
        {
            Microsoft::WRL::ComPtr<IExtractIconW> pExtractIcon;
            hr = pParentFolder->GetUIObjectOf(nullptr, 1, &pidlChild, IID_IExtractIconW, nullptr,
                reinterpret_cast<void**>(pExtractIcon.GetAddressOf()));
            if (SUCCEEDED(hr))
            {
                WCHAR szIconFile[MAX_PATH] = {};
                int iIndex = 0;
                UINT uFlags = 0;
                if (SUCCEEDED(pExtractIcon->GetIconLocation(0, szIconFile, ARRAYSIZE(szIconFile), &iIndex, &uFlags)))
                {
                    WCHAR szEntry[MAX_PATH + 16];
                    StringCchPrintfW(szEntry, ARRAYSIZE(szEntry), L"%s,%d", szIconFile, iIndex);
                    _valueSet[L"IconPath"] = szEntry;
                }
            }
        }

        CoTaskMemFree(pidlFull);
    }

    std::wstring FilePropertySheetManager::FormatFileTime(const FILETIME& ft)
    {
        SYSTEMTIME st = {};
        FileTimeToSystemTime(&ft, &st);
        WCHAR szDate[128];
        GetDateFormatW(LOCALE_USER_DEFAULT, DATE_SHORTDATE, &st, nullptr, szDate, ARRAYSIZE(szDate));
        WCHAR szTime[128];
        GetTimeFormatW(LOCALE_USER_DEFAULT, 0, &st, nullptr, szTime, ARRAYSIZE(szTime));
        return std::wstring(szDate) + L" " + szTime;
    }

    std::wstring FilePropertySheetManager::SerializePageData(const std::map<std::wstring, std::wstring>& entries) const
    {
        std::wstring result;

        for (const auto& entry : entries)
        {
            result += entry.first;
            result += L'=';
            result += entry.second;
            result += L";";
        }

        if (!result.empty())
        {
            result.pop_back();
        }

        return result;
    }

    std::wstring FilePropertySheetManager::SerializeValueSet() const
    {
        std::wstring result;

        result += L"PropertySheetTitle";
        result += L'=';
        result += _fileName;
        result += L"\r\n";

        result += L"PageData";
        result += L'=';
        result += SerializePageData(_valueSet);
        result += L"\r\n";

        return result;
    }
}
