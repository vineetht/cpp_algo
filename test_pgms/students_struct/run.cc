#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

#include "student_info.h"
#include "grade.h"
#include "median.h"

using std::cin;
using std::cout;
using std::setprecision;
using std::streamsize;
using std::vector;
using std::endl;
using std::domain_error;

int main()
{
    cout << "Enter name, mid_term, final, homework grades followed by Ctrl-d" << endl;
    vector<StudentInfo> student_list;
    StudentInfo student;

    while (read(cin, student))
        student_list.push_back(student);

    //sort the student vector
    sort(student_list.begin(), student_list.end(), compare);
    streamsize prev = cout.precision();

    for(vector<StudentInfo>::size_type i = 0; 
        i < student_list.size(); i++) {
        double final_grade = grade(student_list[i]);
        cout << student_list[i].name << " scored " << setprecision(3) 
             << final_grade << setprecision(prev) << endl;
    }
    
    return 0;
}

