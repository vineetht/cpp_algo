#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::vector;
//using std::sort;

int main()
{
    cout << "Enter mid term and final grades: " << endl;

    double mid_term, final;
    cin >> mid_term >> final;

    cout << "Enter homework grades followed by Ctrl-d" << endl;
    vector<double> homework;
    double x;

    while (cin >> x)
        homework.push_back(x);

    typedef vector<double>::size_type vect_sz;
    vect_sz size= homework.size();
    
    if (0 == size) {
        cout << "Homework grades expected !" << endl;
        return -1;
    }

    sort(homework.begin(), homework.end());
    vect_sz mid = size / 2;
    double median = size % 2 == 0 ? (homework[mid - 1] + homework[mid]) /2 : homework[mid];

    streamsize prev = cout.precision();
    cout << "The Grade is " << setprecision(3) 
         << 0.2 * mid_term + 0.4 * final + 0.4 * median 
         << setprecision(prev) << endl; 

    return 0;
}
