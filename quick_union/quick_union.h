#ifndef QUICK_UNION_H
#define QUICK_UNION_H
class QuickUnion {
    private:
        int *id_;
        int root(int elem);

    public:
        QuickUnion(int size);
        ~QuickUnion();
        bool Connected(int left, int right);
        void Union(int left, int right);
};

#endif //QUICKUNION_H
