#pragma once
#include <string>
#include <vector>
#include <utility>

namespace PropertiesVerb
{
    class FilePropertySheetPresenter
    {
    public:
        static void Show(const std::wstring& serializedValueSet);

    private:
        static std::vector<std::pair<std::wstring, std::wstring>> Deserialize(const std::wstring& serializedValueSet);
    };
}
