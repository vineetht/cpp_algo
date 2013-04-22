#include <iostream>
#include <list>
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
using std::list;
using std::endl;
using std::domain_error;
using std::getline;
using std::advance;

int main()
{
    cout << "Enter name, mid_term, final, homework grades followed by Ctrl-d" << endl;
    list<StudentInfo> student_list;
    StudentInfo student;

    //sort the student list
    //sort(student_list.begin(), student_list.end(), compare);
    student_list.sort(compare);
    streamsize prev = cout.precision();
    while (read(cin, student)){
        student_list.push_back(student);
    }

    {
        list<StudentInfo>::iterator it = student_list.begin();
        std::advance(it, 2);
        cout << "Third elm is " << (*it).name << endl;
    }

    list<StudentInfo> failed_list;
    failed_list = extract_failed_iter(student_list);

    cout << endl << endl << "Students passed: " << endl;
    for(list<StudentInfo>::const_iterator it = student_list.begin();
        it != student_list.end(); it++) {
        double final_grade = grade(*it);
        cout << (*it).name << " " << setprecision(3) << final_grade 
             << setprecision(prev) << endl;
    }

    cout << endl << "Students failed: " << endl;
    for(list<StudentInfo>::const_iterator it = failed_list.begin();
        it != failed_list.end(); it++) {
        double final_grade = grade(*it);
        cout << (*it).name << " " << setprecision(3) << final_grade 
             << setprecision(prev) << endl;
    }
    
    return 0;
}

