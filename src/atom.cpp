#include "atomsql/atom.h"
#include "atomsql/debugger.h"
#include "atomsql/storage_engine.h"
#include <optional>
#include <filesystem>
#include <fstream>
#include <print>

class Atom::AtomImpl
{
public:
    AtomImpl() :
        mDatabaseFolderPath(std::nullopt),
        mSelectedDatabasePath(std::nullopt),
        mStorageEngine(std::make_unique<StorageEngine>()) {}

    ~AtomImpl() = default;

    bool Initialize(const std::string& dbFolderPath)
    {
        if (std::filesystem::exists(dbFolderPath))
        {
            Debugger::PrintInfo(
                std::format("Successfully located database folder: '{}'", dbFolderPath));

            mDatabaseFolderPath = dbFolderPath;
            
            if (!std::filesystem::exists(std::format("{}/{}", dbFolderPath, "main.atom")))
            {
                std::ofstream file;
                file.open(std::format("{}/{}", dbFolderPath, "main.atom"));
                if (!file.is_open())
                {
                    Debugger::PrintError("Failed to create main database file");
                    return false;
                }else Debugger::PrintInfo("Successfully created main database file");
                file.close();
            }
            return true;
        }
        else
        {
            Debugger::PrintError(
                std::format("Failed to locate database folder: '{}'", dbFolderPath)); 
            return false;
        }
    }

    bool CreateDatabase(const std::string& databaseName)
    {
        if (!mDatabaseFolderPath.has_value())
        {
            Debugger::PrintError("Database folder must first be intialized");
            return false;
        }

        const std::filesystem::path databasePath =
            std::format("{}/{}", mDatabaseFolderPath.value().generic_string(), databaseName);
        if (std::filesystem::exists(databasePath))
        {
            Debugger::PrintInfo(
                    std::format("Database '{}' already exists", databaseName));
            return true;
        }
        
        if(!std::filesystem::create_directory(databasePath))
        {
            Debugger::PrintError("Failed to create directory for new database");
            return false;
        }else Debugger::PrintInfo(
            std::format("Successfully created new database '{}'", databaseName));

        return true;
    }

    bool SelectDatabase(const std::string& databaseName) 
    {
        const std::filesystem::path databasePath =
            std::format("{}/{}", mDatabaseFolderPath.value().generic_string(), databaseName);

        if (!std::filesystem::exists(databasePath))
        {
            Debugger::PrintError(
                    std::format("Failed to find database '{}'", databaseName));
            return false;
        }
        mSelectedDatabasePath = databasePath;
        Debugger::PrintInfo(
            std::format("Successfully selected '{}' database", databaseName));

        return true;
    }
    
public:
    std::optional<std::filesystem::path> mDatabaseFolderPath;
    std::optional<std::filesystem::path> mSelectedDatabasePath;
    std::unique_ptr<StorageEngine> mStorageEngine;
};

Atom::Atom() :
    mImpl(std::make_unique<AtomImpl>()) {}

Atom::~Atom() = default;

[[nodiscard]]bool Atom::Initialize(const std::string& dbFolderPath)
{
    return mImpl->Initialize(dbFolderPath);
}

[[nodiscard]]bool Atom::CreateDatabase(const std::string& databaseName)
{
    return mImpl->CreateDatabase(databaseName);
}

[[nodiscard]]bool Atom::SelectDatabase(const std::string& databaseName)
{
    return mImpl->SelectDatabase(databaseName);
}
