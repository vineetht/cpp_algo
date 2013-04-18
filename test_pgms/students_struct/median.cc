#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::domain_error;

double median(vector<double> hw)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = hw.size();
    if (0 == size)
        throw domain_error("Median of an empty list!");

    sort(hw.begin(), hw.end());
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (hw[mid - 1] + hw[mid]) / 2 : hw[mid];
}
