#ifndef GRADE_H
#define GRADE_H

#include <list>
#include "student_info.h"

double grade(double mid_term, double final, double median);
double grade(double mid_term, double final, const std::list<double>& hw);
double grade(const StudentInfo& student);

#endif //GRADE_H
