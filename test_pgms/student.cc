#include <iostream>
#include <iomanip>
#include <ios>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;

int main()
{
    cout << "Enter mid and final grades" << endl;

    double final, mid;
    cin >> mid >> final;

    cout << "Enter all homework grades, space separated, "
            "followed by <Ctrl d>" << endl;

    int count = 0;
    double sum = 0, x;
    while (cin >> x) {
        count ++;
        sum += x;
    }

    streamsize prev = cout.precision();
    cout << setprecision(3) << "Final grade is " 
         << 0.2 * mid + 0.4 * final + 0.4 * sum / count 
         << setprecision(prev) << endl;

    return 0;
}
