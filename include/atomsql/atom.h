#ifndef ATOM_H
#define ATOM_H

#include <memory>
#include <string>

class Atom
{
public:
    Atom();
    ~Atom();

    [[nodiscard]]bool SetDatabaseFolder(const std::string& dbFolderPath);
    [[nodiscard]]bool InitializeDatabase();
private:
    class AtomImpl;
    std::unique_ptr<AtomImpl> mImpl;
};

#endif
