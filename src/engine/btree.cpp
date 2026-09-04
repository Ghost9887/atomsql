#include "atomsql/btree.h"

class BTree::BTreeImpl
{
public:
    BTreeImpl() = default;
    ~BTreeImpl() = default;
};

BTree::BTree() :
    mImpl(std::make_unique<BTreeImpl>()) {}

BTree::~BTree() = default;

