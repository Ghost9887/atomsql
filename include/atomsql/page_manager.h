#ifndef PAGE_MANAGER_H
#define PAGE_MANAGER_H

#include <memory>

class PageManager
{
public:
    PageManager();
    ~PageManager();
private:
    class PageManagerImpl;
    std::unique_ptr<PageManagerImpl> mImpl;
};

#endif
