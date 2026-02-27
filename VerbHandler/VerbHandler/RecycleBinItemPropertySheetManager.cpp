#include "pch.h"
#include "RecycleBinItemPropertySheetManager.h"
#include <propkey.h>
#include <propsys.h>

// {9B174B33-40FF-11D2-A27E-00C04FC30871} System.Recycle.DeletedFrom (PID 2)
static const PROPERTYKEY PKEY_Recycle_DeletedFrom =
    { { 0x9B174B33, 0x40FF, 0x11D2, { 0xA2, 0x7E, 0x00, 0xC0, 0x4F, 0xC3, 0x08, 0x71 } }, 2 };

// {9B174B33-40FF-11D2-A27E-00C04FC30871} System.Recycle.DateDeleted (PID 3)
static const PROPERTYKEY PKEY_Recycle_DateDeleted =
    { { 0x9B174B33, 0x40FF, 0x11D2, { 0xA2, 0x7E, 0x00, 0xC0, 0x4F, 0xC3, 0x08, 0x71 } }, 3 };

namespace PropertiesVerb
{
    RecycleBinItemPropertySheetManager::RecycleBinItemPropertySheetManager(IShellItem* psi)
        : FilePropertySheetManager(psi)
    {
    }

    std::wstring RecycleBinItemPropertySheetManager::PropertySheetType() const
    {
        return L"Recycle Bin Folder Item";
    }

    void RecycleBinItemPropertySheetManager::PopulateValueSet()
    {
        FilePropertySheetManager::PopulateValueSet();
        PopulateOrigin();
        PopulateDeletedDate();
    }

    void RecycleBinItemPropertySheetManager::GetDisplayOrder(std::vector<std::wstring>& order) const
    {
        order = {
            L"PropertySheet Type",
            L"FileName",
            L"FileType",
            L"Origin",
            L"FileSize",
            L"Deleted Date",
            L"CreatedDate",
            L"Attributes",
            L"IconPath",
        };
    }

    void RecycleBinItemPropertySheetManager::PopulateOrigin()
    {
        if (!_psi2)
        {
            return;
        }

        PWSTR pszValue = nullptr;
        if (SUCCEEDED(_psi2->GetString(PKEY_Recycle_DeletedFrom, &pszValue)))
        {
            _valueSet[L"Origin"] = pszValue;
            CoTaskMemFree(pszValue);
        }
    }

    void RecycleBinItemPropertySheetManager::PopulateDeletedDate()
    {
        if (!_psi2)
        {
            return;
        }

        FILETIME ft = {};
        if (SUCCEEDED(_psi2->GetFileTime(PKEY_Recycle_DateDeleted, &ft)))
        {
            _valueSet[L"Deleted Date"] = FormatFileTime(ft);
        }
    }
}
