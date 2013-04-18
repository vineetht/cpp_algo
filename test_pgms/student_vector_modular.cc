#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Instead of doing a 'using namespace std', do the following
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

    // To make sure that hw contains valid data when read_hw returns
    hw.clear();
    while (in >> x)
        hw.push_back(x);

    // So that cin could be used further, clearing the error state
    in.clear();

    return in;
}

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();

    // Dont proceed if the homework vector is empty
    if (0 == size)
        throw domain_error("Vector cannot be empty!");
    
    // Use sort to find the median, sort the list and find the middle one
    sort (vec.begin(), vec.end());
    vec_sz mid = size / 2;
    // If the list is even, find the avg of the middle ones
    return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];
}

double grade(double mid_term, double final, double hw)
{
    return 0.2 * mid_term + 0.4 * final + 0.4 * hw;
}

double grade(double mid_term, double final, const vector<double>& hw)
{
    if (0 == hw.size())
        throw domain_error("Student has not done any homework!");

    return grade(mid_term, final, median(hw));
}


int main()
{
    cout << "Enter mid term and final grades" << endl;

    double mid_term, final;
    cin >> mid_term >> final;

    cout << "Enter homework grades followed by Ctrl-d" << endl;
    vector<double> hw;
    read_hw(cin, hw);
   
    try {
        double final_grade = grade(mid_term, final, hw);
        streamsize prev = cout.precision();
        cout << "Overall grade is " << setprecision(3) << final_grade
             << setprecision(prev) << endl;
    } catch (domain_error) {
        cout << "Please enter your homework grades!" << endl;
        return -1;
    }

    return 0;
}
