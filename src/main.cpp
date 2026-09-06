#include "atomsql/atom.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv)
{
    Atom atom;
    if (!atom.Initialize("../data")) return 1;

    return 0;
}
