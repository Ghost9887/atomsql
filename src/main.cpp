#include "atomsql/atom.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv)
{
    Atom atom;
    if (!atom.SetDatabaseFolder("../data")) return 1;
    if (!atom.InitializeDatabase()) return 1;

    return 0;
}
