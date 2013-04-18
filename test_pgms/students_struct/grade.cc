#include <vector>
#include "grade.h"
#include "median.h"
#include "student_info.h"

using std::vector;

double grade(double mid_term, double final, double median)
{
    return 0.2 * mid_term + 0.4 * final + 0.4 * median;
}

double grade(double mid_term, double final, const vector<double>& hw)
{
    return grade(mid_term, final, median(hw));
}

double grade(const StudentInfo& student)
{
    return grade(student.mid_term, student.final, student.hw);
}
