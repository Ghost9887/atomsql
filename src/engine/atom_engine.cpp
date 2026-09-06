#include "atomsql/atom_engine.h"

class AtomEngine::AtomEngineImpl
{
public:
    AtomEngineImpl() = default;
    ~AtomEngineImpl() = default;
};

AtomEngine::AtomEngine() :
    mImpl(std::make_unique<AtomEngineImpl>()) {}

AtomEngine::~AtomEngine() = default;
