#include "atomsql/page_manager.h"
#include "atomsql/page.h"
#include <vector>

class PageManager::PageManagerImpl
{
public:
    PageManagerImpl(const int pageSize) :
        mPageSize(pageSize), mPages() {}
    ~PageManagerImpl() = default;
private:
    const int mPageSize;
    std::vector<std::unique_ptr<Page>> mPages;
};

PageManager::PageManager() :
    mImpl(std::make_unique<PageManagerImpl>(4096)) {}

PageManager::~PageManager() = default;
