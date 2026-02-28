#pragma once
#include "FilePropertySheetManager.h"

namespace PropertiesVerb
{
    class RecycleBinItemPropertySheetManager : public FilePropertySheetManager
    {
    public:
        explicit RecycleBinItemPropertySheetManager(IShellItem* psi);

        void PopulateValueSet() override;
        std::wstring SerializePageData(const std::map<std::wstring, std::wstring>& entries) const override;

    private:
        std::wstring SerializeGeneralPageData(const std::map<std::wstring, std::wstring>& entries) const;
        void PopulateOrigin();
        void PopulateDeletedDate();
    };
}
