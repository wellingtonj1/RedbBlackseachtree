#ifndef TREETEST_H
#define TREETEST_H
#include "tree.h"
#include <iomanip>

class Treetest
{
private:
    tree *objeto;
public:
    Treetest();
    void Testtree();
    Item* criaitem();
};

#endif // TREETEST_H
