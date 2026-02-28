#include "pch.h"
#include "RecycleBinItemGeneralPageView.h"

namespace PropertiesVerb
{
    void RecycleBinItemGeneralPageView::GetDisplayOrder(std::vector<std::wstring>& order) const
    {
        order = {
            L"FileType",
            L"Origin",
            L"FileSize",
            L"Deleted Date",
            L"CreatedDate",
            L"Attributes",
            L"IconPath",
        };
    }

    std::wstring RecycleBinItemGeneralPageView::GetContent(std::map<std::wstring, std::wstring> const& pageEntryMap) const
    {
        std::vector<std::wstring> displayOrder;
        GetDisplayOrder(displayOrder);
		std::wstring szMessage = L"";
		szMessage += L"Recycle Bin Item General Page Properties:\n\n";
        for (const auto& key : displayOrder)
        {
            auto it = pageEntryMap.find(key);
            if (it != pageEntryMap.end())
            {
                szMessage += key + L": " + it->second + L"\n";
            }
        }
        return szMessage;
    }
}
