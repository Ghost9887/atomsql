#ifndef PAGE_H
#define PAGE_H

#include <memory>
#include <cstdint>

class Page
{
public:
    Page(const std::uint32_t size);
    ~Page();
private:
    class PageImpl;
    std::unique_ptr<PageImpl> mImpl;
};

#endif
