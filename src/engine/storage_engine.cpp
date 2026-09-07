#include "atomsql/storage_engine.h"
#include "atomsql/page_manager.h"

class StorageEngine::StorageEngineImpl
{
public:
    StorageEngineImpl() :
         
        mPageManager(std::make_unique<PageManager>()) {}
    ~StorageEngineImpl() = default;
    
public:
    
    std::unique_ptr<PageManager> mPageManager;
};

StorageEngine::StorageEngine() :
    mImpl(std::make_unique<StorageEngineImpl>()) {}

StorageEngine::~StorageEngine() = default;


