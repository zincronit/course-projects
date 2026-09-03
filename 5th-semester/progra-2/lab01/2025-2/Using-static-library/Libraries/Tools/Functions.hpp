//
// Created by zincronit on 9/3/26.
//

#ifndef USING_STATIC_LIBRARY_FUNCTIONS_HPP
#define USING_STATIC_LIBRARY_FUNCTIONS_HPP

#include "../Overloads/overloads.hpp"

void read_course_file(const char* filepath,
                      struct Course*& courses,
                      int& count);

void read_student_file(const char* filepath,
                       struct Student*& students,
                       int& count);

void read_enrollment_file(const char* filepath,
                          struct Course* courses,
                          struct Student* students);


void print_report(const char* filepath,
                  struct Course* courses,
                  int count);

void print_title(std::ofstream& fout, const char* title, int width);


#endif //USING_STATIC_LIBRARY_FUNCTIONS_HPP
