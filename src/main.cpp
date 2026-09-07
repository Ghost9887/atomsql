#include "atomsql/atom.h"
#include "atomsql/storage_engine.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv)
{
    Atom atom;
    if (!atom.Initialize("../data")) return 1;
    if (!atom.CreateDatabase("test")) return 1;
    if (!atom.SelectDatabase("test")) return 1;

    return 0;
}
