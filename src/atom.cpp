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
    
    void SetDatabaseFolder(const std::string& dbFolderPath)
    {
        
        if (std::filesystem::exists(dbFolderPath))
        {
            Debugger::PrintInfo(
                std::format("Successfully located database folder: '{}'", dbFolderPath));

            mDbFolderPath = dbFolderPath;
        }
        else
        {
            Debugger::PrintError(
                std::format("Failed to locate database folder: '{}'", dbFolderPath)); 
        }
    }

    void InitializeDatabase()
    {
        if (mDbFolderPath.has_value())
        {
            const std::filesystem::path expectedMainPath = 
                mDbFolderPath.value().generic_string() + "/main.atom";

            if (std::filesystem::exists(expectedMainPath))
            {
                Debugger::PrintInfo("Successfully loaded existing database");
            }else
            {
                std::ofstream mainFile;
                mainFile.open(expectedMainPath);
                if (!mainFile.is_open())
                {
                    Debugger::PrintError("Failed to create main database file");
                }else
                {
                    mainFile.close();
                    Debugger::PrintInfo("Successfully created new database");
                }
            }
        }else
        {
            Debugger::PrintError(
                "Cannot initialize database without specifing the database folder first");
        }
    }
public:
    std::optional<std::filesystem::path> mDbFolderPath;
};

Atom::Atom() :
    mImpl(std::make_unique<AtomImpl>()) {}

Atom::~Atom() = default;

void Atom::SetDatabaseFolder(const std::string& dbFolderPath)
{
    return mImpl->SetDatabaseFolder(dbFolderPath);
}

void Atom::InitializeDatabase()
{
    mImpl->InitializeDatabase();
}
