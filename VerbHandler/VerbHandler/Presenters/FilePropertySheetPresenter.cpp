#include "pch.h"
#include "FilePropertySheetPresenter.h"
#include "RecycleBinItemGeneralPageView.h"
#include <map>
#include <strsafe.h>
#include <windows.h>

namespace PropertiesVerb
{
    std::vector<std::pair<std::wstring, std::wstring>> FilePropertySheetPresenter::Deserialize(const std::wstring& serializedValueSet)
    {
        std::vector<std::pair<std::wstring, std::wstring>> entries;
        size_t pos = 0;

        while (pos < serializedValueSet.size())
        {
            size_t lineEnd = serializedValueSet.find(L'\n', pos);
            if (lineEnd == std::wstring::npos)
            {
                lineEnd = serializedValueSet.size();
            }

            std::wstring line = serializedValueSet.substr(pos, lineEnd - pos);
            if (!line.empty() && line.back() == L'\r')
            {
                line.pop_back();
            }

            size_t sep = line.find(L'=');
            if (sep != std::wstring::npos)
            {
                std::wstring key = line.substr(0, sep);
                std::wstring value = line.substr(sep + 1);
                entries.push_back({ key, value });
            }

            pos = lineEnd + 1;
        }

        return entries;
    }

    std::map<std::wstring, std::wstring> FilePropertySheetPresenter::DeserializePageEntries(const std::wstring& data)
    {
        std::map<std::wstring, std::wstring> result;
        size_t pos = 0;

        while (pos < data.size())
        {
            size_t semiPos = data.find(L';', pos);
            if (semiPos == std::wstring::npos)
            {
                semiPos = data.size();
            }

            std::wstring token = data.substr(pos, semiPos - pos);
            size_t sep = token.find(L'=');
            if (sep != std::wstring::npos)
            {
                std::wstring key = token.substr(0, sep);
                std::wstring value = token.substr(sep + 1);
                result[key] = value;
            }

            pos = semiPos + 1;
        }

        return result;
    }

    void FilePropertySheetPresenter::Show(const std::wstring& serializedValueSet)
    {
        auto allEntries = Deserialize(serializedValueSet);

        std::map<std::wstring, std::wstring> topLevelMap;
        for (const auto& entry : allEntries)
        {
            topLevelMap[entry.first] = entry.second;
        }

        std::wstring fileName;
        auto itName = topLevelMap.find(L"PropertySheetTitle");
        if (itName != topLevelMap.end())
        {
            fileName = itName->second;
        }

        std::map<std::wstring, std::wstring> pageEntryMap;
        auto itPage = topLevelMap.find(L"PageData");
        if (itPage != topLevelMap.end())
        {
            pageEntryMap = DeserializePageEntries(itPage->second);
        }

        std::wstring pageKind;
        auto itKind = pageEntryMap.find(L"FilePropertySheetPageKind");
        if (itKind != pageEntryMap.end())
        {
            pageKind = itKind->second;
        }

		std::wstring szMessage = fileName + L" Properties\n\n";
        if (pageKind == L"RecycleBinItemGeneral")
        {
            RecycleBinItemGeneralPageView view;
            szMessage += view.GetContent(pageEntryMap);
        }

        MessageBoxW(nullptr, szMessage.c_str(), L"Properties", MB_OK);
    }
}
