#include <vector>
#include <iostream>
#include <stdexcept>

#include "student_info.h"
#include "grade.h"

using std::vector;
using std::domain_error;
using std::istream;
using std::endl;
using std::cout;

bool compare(const StudentInfo& left, const StudentInfo& right)
{
    return left.name < right.name;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    hw.clear();

    double x;
    while (in >> x)
        hw.push_back(x);

    in.clear();

    return in;
}

istream& read(istream& in, StudentInfo& s)
{
    in >> s.name >> s.mid_term >> s.final;

    // Check for end of student list, dont clear the istream status
    if (in)
        return read_hw(in, s.hw);
    else
        return in;
}

vector<StudentInfo> extract_failed(vector<StudentInfo>& sl)
{
    vector<StudentInfo> fail_list;
    vector<StudentInfo>::size_type size = 0;

    while (size != sl.size()) {
        if (grade(sl[size]) < 60) {
            fail_list.push_back(sl[size]);
            sl.erase(sl.begin() + size);
        } else
            size++;
    }

    return fail_list;
}

vector<StudentInfo> extract_failed_iter(vector<StudentInfo>& sl)
{
    vector<StudentInfo> fail_list;
    vector<StudentInfo>::iterator it = sl.begin();

    while (it != sl.end()) {
        if (grade(*it) < 60) {
            fail_list.push_back(*it);
            sl.erase(it);
        }
        else
            it++;
    }

    return fail_list;
}
