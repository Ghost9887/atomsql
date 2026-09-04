#include "atomsql/atom.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv)
{
    Atom atom;
    bool res = atom.SetDatabaseFolder("../data");
    if (!res) return 1;

    return 0;
}
