#ifndef QUICK_FIND_H
#define QUICK_FIND_H
using namespace std;

class QuickFind
{
    private:
        int *id_;
        int size_;

    public:
        QuickFind(int size);
        ~QuickFind();
        bool Connected(int left, int right);
        void Union(int left, int right);
};

#endif //QUICK_FIND_H 
