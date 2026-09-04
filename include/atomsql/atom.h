#ifndef ATOM_H
#define ATOM_H

#include <memory>
#include <string>

class Atom
{
public:
    Atom();
    ~Atom();

    void SetDatabaseFolder(const std::string& dbFolderPath);
    void InitializeDatabase();
private:
    class AtomImpl;
    std::unique_ptr<AtomImpl> mImpl;
};

#endif
