#ifndef ATOM_H
#define ATOM_H

#include <memory>
#include <string>

class Atom
{
public:
    Atom();
    ~Atom();

    [[nodiscard]]bool Initialize(const std::string& dbFolderPath);
private:
    class AtomImpl;
    std::unique_ptr<AtomImpl> mImpl;
};

#endif
