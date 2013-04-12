#include <iostream>

#include "quick_find.h"

int main()
{   
    QuickFind temp(10);
    cout << "Is 1 and 9 connected: " << temp.Connected(1, 9) << endl;
    temp.Union(1,9);
    cout << "Is 1 and 9 connected: " << temp.Connected(1, 9) << endl;
    temp.Union(1,9);
    cout << "Is 1 and 2 connected: " << temp.Connected(1, 2) << endl;
    temp.Union(2,9);
    cout << "Is 1 and 2 connected: " << temp.Connected(1, 2) << endl;

    return 0;
}
