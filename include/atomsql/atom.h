#ifndef ATOM_H
#define ATOM_H

#include <memory>
#include <string>

class StorageEngine;

class Atom
{
public:
    Atom();
    ~Atom();
    
    [[nodiscard]]bool Initialize(const std::string& dbFolderPath);
    [[nodiscard]]bool CreateDatabase(const std::string& databaseName);
    [[nodiscard]]bool SelectDatabase(const std::string& databaseName);
private:
    class AtomImpl;
    std::unique_ptr<AtomImpl> mImpl;
};

#endif
