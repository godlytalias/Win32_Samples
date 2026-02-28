#pragma once
#include <shobjidl_core.h>
#include <wrl/client.h>
#include <string>
#include <map>
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

        virtual void PopulateValueSet();
        std::wstring SerializeValueSet() const;
        virtual std::wstring SerializePageData(const std::map<std::wstring, std::wstring>& entries) const;

        const std::map<std::wstring, std::wstring>& GetValueSet() const;

    protected:
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
        std::wstring _fileName;
        std::map<std::wstring, std::wstring> _valueSet;
    };
}
