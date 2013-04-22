#include <list>
#include <vector>
#include <iostream>
#include <stdexcept>

#include "student_info.h"
#include "grade.h"

using std::list;
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

list<StudentInfo> extract_failed(list<StudentInfo>& sl)
{
    list<StudentInfo> fail_list;
    list<StudentInfo>::size_type size = 0;

    list<StudentInfo>::iterator it = sl.begin();
    while (it != sl.end()) {
        if (grade(*it) < 60) {
            fail_list.push_back(*it);
            it = sl.erase(it);
        } else
            it++;
    }

    return fail_list;
}

list<StudentInfo> extract_failed_iter(list<StudentInfo>& sl)
{
    list<StudentInfo> fail_list;
    list<StudentInfo>::iterator it = sl.begin();

    while (it != sl.end()) {
        if (grade(*it) < 60) {
            fail_list.push_back(*it);
            it = sl.erase(it);
        }
        else
            it++;
    }

    return fail_list;
}
