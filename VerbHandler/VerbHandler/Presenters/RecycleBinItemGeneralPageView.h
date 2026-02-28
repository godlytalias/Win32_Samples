#pragma once
#include <string>
#include <vector>
#include <map>
namespace PropertiesVerb
{
    class RecycleBinItemGeneralPageView
    {
    public:
        std::wstring GetContent(std::map<std::wstring, std::wstring> const& pageEntryMap) const;
    private:
        void GetDisplayOrder(std::vector<std::wstring>& order) const;
    };
}
