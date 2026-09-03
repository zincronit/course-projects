//
// Created by zincronit on 9/3/26.
//

#include "Libraries/Tools/Functions.hpp"

int main()
{
    struct Course* courses;
    int course_count = 0;

    struct Student* students;
    int student_count = 0;

    read_course_file(
        "../Files/Data/courses.csv",
        courses,
        course_count
    );
    read_student_file(
        "../Files/Data/students.csv",
        students,
        student_count
    );
    read_enrollment_file(
        "../Files/Data/enrollment.csv",
        courses,
        students
    );
    print_report(
        "../Files/Reports/report.txt",
        courses,
        course_count
    );

    return 0;
}
