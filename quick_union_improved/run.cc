#include <iostream>
#include <fstream>
#include <string>

#include "quick_union_improved.h"

using namespace std;

int main()
{   
    string file_name = "test.log";
    ifstream in_file(file_name.c_str());

    if (!in_file)
    {
        cout << "Error opening " << file_name << endl;
        return 0;
    }
    
    int count = 0, i = 0, j = 0;

    /* Read from test.log and populate Quick Union DS */
    in_file >> count;
    QuickUnionImproved temp(count);
    while (in_file >> i >> j) temp.Union(i, j);

    cout << "Is 1 and 2 connected: " << temp.Connected(1, 2) << endl;

    return 0;
}
