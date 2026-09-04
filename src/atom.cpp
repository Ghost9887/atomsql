#include "atomsql/atom.h"
#include "atomsql/debugger.h"
#include <optional>
#include <filesystem>
#include <print>

class Atom::AtomImpl
{
public:
    AtomImpl() :
        mDbFolderPath(std::nullopt) {}

    ~AtomImpl() = default;
    
    bool SetDatabaseFolder(const std::string& dbFolderPath)
    {
        mDbFolderPath = dbFolderPath;
        if (std::filesystem::exists(mDbFolderPath.value()))
        {
            Debugger::PrintInfo(
                std::format("Successfully located database folder: '{}'", dbFolderPath));
            return true;
        }
        else
        {
            Debugger::PrintError(
                std::format("Failed to locate database folder: '{}'", dbFolderPath)); 
            return false;
        }
    }

public:
    std::optional<std::filesystem::path> mDbFolderPath;
};

Atom::Atom() :
    mImpl(std::make_unique<AtomImpl>()) {}

Atom::~Atom() = default;

[[nodiscard]]bool Atom::SetDatabaseFolder(const std::string& dbFolderPath)
{
    return mImpl->SetDatabaseFolder(dbFolderPath);
}
