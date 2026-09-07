#include "atomsql/page.h"
#include <array>

struct PageHeader 
{  
    PageHeader(std::uint32_t id, std::uint32_t pageSize) :
        id(id), pageSize(pageSize) {}

    std::array<char, 4> identifier = { 'P', 'A', 'G', 'E' };
    std::uint32_t id;
    std::uint32_t pageSize;
};

class Page::PageImpl
{
public:
    PageImpl(const std::uint32_t size) :
        mPageHeader({0, size}) {}
    ~PageImpl() = default;
public:
    PageHeader mPageHeader;
};

Page::Page(const std::uint32_t size) :
    mImpl(std::make_unique<PageImpl>(size)) {}

Page::~Page() = default;
