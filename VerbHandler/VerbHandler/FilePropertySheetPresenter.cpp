#include "pch.h"
#include "FilePropertySheetPresenter.h"
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

    void FilePropertySheetPresenter::Show(const std::wstring& serializedValueSet)
    {
        auto entries = Deserialize(serializedValueSet);

        WCHAR szMessage[4096] = {};

        for (const auto& entry : entries)
        {
            StringCchCatW(szMessage, ARRAYSIZE(szMessage), entry.first.c_str());
            StringCchCatW(szMessage, ARRAYSIZE(szMessage), L": ");
            StringCchCatW(szMessage, ARRAYSIZE(szMessage), entry.second.c_str());
            StringCchCatW(szMessage, ARRAYSIZE(szMessage), L"\r\n");
        }

        MessageBoxW(nullptr, szMessage, L"File Properties", MB_OK);
    }
}
