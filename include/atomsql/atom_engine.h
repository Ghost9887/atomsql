#ifndef ATOM_ENGINE_H
#define ATOM_ENGINE_H

#include <memory>
#include "storage_engine.h"

class AtomEngine : public StorageEngine
{
public:
    AtomEngine();
    ~AtomEngine();
private:
    class AtomEngineImpl;
    std::unique_ptr<AtomEngineImpl> mImpl;
};

#endif
