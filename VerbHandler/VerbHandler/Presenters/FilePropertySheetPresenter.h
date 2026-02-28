#pragma once
#include <string>
#include <vector>
#include <utility>
#include <map>

namespace PropertiesVerb
{
    class FilePropertySheetPresenter
    {
    public:
        static void Show(const std::wstring& serializedValueSet);

    private:

        static std::vector<std::pair<std::wstring, std::wstring>> Deserialize(const std::wstring& serializedValueSet);
        static std::map<std::wstring, std::wstring> DeserializePageEntries(const std::wstring& data);
    };
}
