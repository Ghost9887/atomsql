#ifndef STORAGE_ENGINE_H 
#define STORAGE_ENGINE_H

#include <memory>

class StorageEngine
{
public:
    StorageEngine();
    ~StorageEngine();
private:
    class StorageEngineImpl;
    std::unique_ptr<StorageEngineImpl> mImpl;
};

#endif
