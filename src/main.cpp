#include "atomsql/atom.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv)
{
    Atom atom;
    atom.SetDatabaseFolder("../data");
    atom.InitializeDatabase();

    return 0;
}
