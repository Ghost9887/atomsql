#include "atomsql/atom.h"
#include "atomsql/debugger.h"
#include <optional>
#include <filesystem>
#include <fstream>
#include <print>

class Atom::AtomImpl
{
public:
    AtomImpl() :
        mDbFolderPath(std::nullopt) {}

    ~AtomImpl() = default;
    
    bool SetDatabaseFolder(const std::string& dbFolderPath)
    {
        
        if (std::filesystem::exists(dbFolderPath))
        {
            Debugger::PrintInfo(
                std::format("Successfully located database folder: '{}'", dbFolderPath));

            mDbFolderPath = dbFolderPath;
            return true;
        }
        else
        {
            Debugger::PrintError(
                std::format("Failed to locate database folder: '{}'", dbFolderPath)); 
            return false;
        }
    }

    bool InitializeDatabase()
    {
        if (mDbFolderPath.has_value())
        {
            const std::filesystem::path expectedMainPath = 
                mDbFolderPath.value().generic_string() + "/main.atom";

            if (std::filesystem::exists(expectedMainPath))
            {
                Debugger::PrintInfo("Successfully loaded existing database");
                return true;
            }else
            {
                std::ofstream mainFile;
                mainFile.open(expectedMainPath);
                if (!mainFile.is_open())
                {
                    Debugger::PrintError("Failed to create main database file");
                    return false;
                }else
                {
                    mainFile.close();
                    Debugger::PrintInfo("Successfully created new database");
                    return true;
                }
            }
        }else
        {
            Debugger::PrintError(
                "Cannot initialize database without specifing the database folder first");
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

[[nodiscard]]bool Atom::InitializeDatabase()
{
    return mImpl->InitializeDatabase();
}
