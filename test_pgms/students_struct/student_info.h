#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

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
std::vector<StudentInfo> extract_failed(std::vector<StudentInfo>& sl);
std::vector<StudentInfo> extract_failed_iter(std::vector<StudentInfo>& sl);

#endif //STUDENT_INFO_H
