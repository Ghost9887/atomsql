#include "atomsql/atom.h"
#include "atomsql/debugger.h"
#include "atomsql/atom_engine.h"
#include <optional>
#include <filesystem>
#include <fstream>
#include <print>

class Atom::AtomImpl
{
public:
    AtomImpl() :
        mDbFolderPath(std::nullopt), mStorageEngine(std::make_unique<AtomEngine>()) {}

    ~AtomImpl() = default;
    
    bool Initialize(const std::string& dbFolderPath)
    {
        if(!SetDatabaseFolder(dbFolderPath)) return false;

        const std::filesystem::path expectedMainPath = 
            std::format("{}/{}", mDbFolderPath.value().generic_string(), "main.atom");

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
    }    
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
public:
    std::optional<std::filesystem::path> mDbFolderPath;
    std::unique_ptr<StorageEngine> mStorageEngine;
};

Atom::Atom() :
    mImpl(std::make_unique<AtomImpl>()) {}

Atom::~Atom() = default;

[[nodiscard]]bool Atom::Initialize(const std::string& dbFolderPath)
{
    return mImpl->Initialize(dbFolderPath);
}
