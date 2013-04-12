#include "quick_union.h"

QuickUnion::QuickUnion(int size)
{
    id_ = new int[size];
    for (int i = 0; i < size; i++) id_[i] = i;
}

QuickUnion::~QuickUnion()
{
    delete [] id_;
}

int QuickUnion::root(int elem)
{
    while(elem != id_[elem]) elem = id_[elem];

    return elem;
}

bool QuickUnion::Connected(int left, int right)
{
    return root(left) == root(right);
}

void QuickUnion::Union(int left, int right)
{
    int qleft = root(left);
    int qright = root(right);

    id_[qleft] = qright;
}
