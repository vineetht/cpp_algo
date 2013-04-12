#include "quick_find.h"

QuickFind::QuickFind(int size)
{
    size_ = size;
    id_ = new int[size];
    for (int i = 0; i < size; i++) id_[i] = i;
}

QuickFind::~QuickFind()
{
    delete [] id_;
}

bool QuickFind::Connected(int left, int right)
{
    return id_[left] == id_[right];
}

void QuickFind::Union(int left, int right)
{
    int qleft = id_[left];
    int qright = id_[right];

    for (int i = 0; i< size_; i++)
    {
        if (id_[i] == qleft) id_[i] = qright; 
    }
}
