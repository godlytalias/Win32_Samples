#pragma once
#include <shobjidl_core.h>
#include <wrl/client.h>
#include <string>
#include <map>
#include <vector>
#include <memory>

namespace PropertiesVerb
{
    class FilePropertySheetManager
    {
    public:
        explicit FilePropertySheetManager(IShellItem* psi);
        virtual ~FilePropertySheetManager() = default;

        static std::unique_ptr<FilePropertySheetManager> Create(IShellItem* psi);
        static void CreateAndShow(IShellItem* psi);

        virtual std::wstring PropertySheetType() const;

        virtual void PopulateValueSet();
        void ShowPropertySheet() const;

        const std::map<std::wstring, std::wstring>& GetValueSet() const;

    protected:
        virtual void GetDisplayOrder(std::vector<std::wstring>& order) const;

        void PopulateFileName();
        void PopulateFileType();
        void PopulateFileSize();
        void PopulateCreatedDate();
        void PopulateAttributes();
        void PopulateIconPath();
        static std::wstring FormatFileTime(const FILETIME& ft);
        static bool IsRecycleBinItem(IShellItem* psi);

        Microsoft::WRL::ComPtr<IShellItem> _psi;
        Microsoft::WRL::ComPtr<IShellItem2> _psi2;
        std::map<std::wstring, std::wstring> _valueSet;
    };
}
