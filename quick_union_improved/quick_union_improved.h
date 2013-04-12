#ifndef QUICK_UNION_H
#define QUICK_UNION_H

class QuickUnionImproved
{
    private:
        int *id_;
        int *size_;

    public:
        QuickUnionImproved(int size);
        ~QuickUnionImproved();
        int root(int elem);
        bool Connected(int left, int right);
        void Union(int left, int right);
};

#endif //QUICK_UNION_H
