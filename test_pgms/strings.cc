#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

class DirectVar {
    public:
        typedef size_t my_type;
};

int main()
{
    //std::string temp("hello");
    const std::string temp = "Hello";
    const std::string temp2 = temp + " world" + "!";

    string name1, name2;

    cin >> name1 >> name2;
    cout << name1 << " " << name2 << endl;

    DirectVar::my_type var1 = 100;
    cout << var1 << endl;

    int i = 0;
    while (i < 10) {
        i += 1;
        cout << i << endl;
    }

    return 0;
}
