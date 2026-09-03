//
// Created by zincronit on 9/3/26.
//

#ifndef BUILD_STATIC_LIBRARY_COURSE_HPP
#define BUILD_STATIC_LIBRARY_COURSE_HPP

#include "Student.hpp"

struct Course
{
    char* code;
    char* name;
    double credits;
    char* professor;
    struct Student* in_person_students;
    struct Student* hybrid_students;
    struct Student* online_students;
    int in_person_count;
    int hybrid_count;
    int online_count;
    char* final_type;
};

#endif //BUILD_STATIC_LIBRARY_COURSE_HPP
