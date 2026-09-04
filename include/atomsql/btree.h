#ifndef BTREE_H
#define BTREE_H

#include <memory>

class BTree
{
public:
    BTree();
    ~BTree();
private:
    class BTreeImpl;
    std::unique_ptr<BTreeImpl> mImpl;
};

#endif
