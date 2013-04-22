#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <list>
#include <vector>
#include <iostream>

struct StudentInfo {
    std::string name;
    double mid_term;
    double final;
    std::vector<double> hw;
};

bool compare(const StudentInfo& left, const StudentInfo& right);
std::istream& read(std::istream& in, StudentInfo& student);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::list<StudentInfo> extract_failed(std::list<StudentInfo>& sl);
std::list<StudentInfo> extract_failed_iter(std::list<StudentInfo>& sl);

#endif //STUDENT_INFO_H
