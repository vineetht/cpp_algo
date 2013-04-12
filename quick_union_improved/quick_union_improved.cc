#include "quick_union_improved.h"

QuickUnionImproved::QuickUnionImproved(int size)
{
    id_ = new int[size];
    size_ = new int[size];
    for (int i = 0; i < size; i++) id_[i] = i;
    for (int i = 0; i < size; i++) size_[i] = i;
}

QuickUnionImproved::~QuickUnionImproved()
{
    delete [] id_;
    delete [] size_;
}

int QuickUnionImproved::root(int elem)
{
    while(elem != id_[elem]) elem = id_[elem];

    return elem;
}

bool QuickUnionImproved::Connected(int left, int right)
{
    return root(left) == root(right);
}

void QuickUnionImproved::Union(int left, int right)
{
    int qleft = root(left);
    int qright = root(right);

    if (size_[qleft] < size_[qright]) {
        id_[qleft] = qright;
        size_[qright] += size_[qleft];
    }
    else {
        id_[qright] = qleft;
        size_[qleft] += size_[qright];
    }
}
