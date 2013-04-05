#include <iostream>

#include "QuickFindUF.h"

int main()
{   
    QuickFindUF temp(10);
    cout << "Is 1 and 9 connected: " << temp.Connected(1, 9) << endl;
    temp.Union(1,9);
    cout << "Is 1 and 9 connected: " << temp.Connected(1, 9) << endl;
    temp.Union(1,9);
    cout << "Is 1 and 2 connected: " << temp.Connected(1, 2) << endl;
    temp.Union(2,9);
    cout << "Is 1 and 2 connected: " << temp.Connected(1, 2) << endl;

    return 0;
}
