#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::vector;
using std::streamsize;
using std::setprecision;
using std::domain_error;

istream& read_hw(istream& in, vector<double>& hw)
{
    double x;

    hw.clear();
    while (in >> x)
        hw.push_back(x);

    in.clear();

    return in;
}

double median(vector<double> vec)
{
    if (0 == vec.size())
        throw domain_error("Vector cannot be empty!");
    
    sort (vec.begin(), vec.end());

    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];
}

double grade(double mid_term, double final, double hw)
{
    return 0.2 * mid_term + 0.4 * final + 0.4 * hw;
}

double grade(double mid_term, double final, const vector<double>& vec_hw)
{
    if (0 == vec_hw.size())
        throw domain_error("Student has not done any homework!");

    return grade(mid_term, final, median(vec_hw));
}


int main()
{
    cout << "Enter mid term and final grades" << endl;

    double mid_term, final;
    cin >> mid_term >> final;

    cout << "Enter homework grades followed by Ctrl-d" << endl;
    vector<double> vec_hw;
    read_hw(cin, vec_hw);
    
    streamsize prev = cout.precision();
    cout << "Overall grade is " << setprecision(3) 
         << grade(mid_term, final, vec_hw) << setprecision(prev) << endl;

    return 0;
}
