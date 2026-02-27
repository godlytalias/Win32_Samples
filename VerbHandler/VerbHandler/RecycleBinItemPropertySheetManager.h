#pragma once
#include "FilePropertySheetManager.h"

namespace PropertiesVerb
{
    class RecycleBinItemPropertySheetManager : public FilePropertySheetManager
    {
    public:
        explicit RecycleBinItemPropertySheetManager(IShellItem* psi);

        std::wstring PropertySheetType() const override;
        void PopulateValueSet() override;

    protected:
        void GetDisplayOrder(std::vector<std::wstring>& order) const override;

    private:
        void PopulateOrigin();
        void PopulateDeletedDate();
    };
}
