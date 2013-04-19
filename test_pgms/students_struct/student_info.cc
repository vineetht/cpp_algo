#include <vector>
#include <iostream>
#include <stdexcept>

#include "student_info.h"
#include "grade.h"

using std::vector;
using std::domain_error;
using std::istream;

bool compare(const StudentInfo& left, const StudentInfo& right)
{
    return left.name < right.name;
}

istream& read_hw(std::istream& in, vector<double>& hw)
{
    hw.clear();

    double x;
    while (in >> x)
        hw.push_back(x);

    std::cout << "done reading hw, last one was " << hw.back() << std::endl;
    in.clear();

    return in;
}

istream& read(std::istream& in, StudentInfo& s)
{
    in >> s.name >> s.mid_term >> s.final;

    // Check for end of student list, dont clear the istream status
    if (in)
        return read_hw(in, s.hw);
    else
        return in;
}


