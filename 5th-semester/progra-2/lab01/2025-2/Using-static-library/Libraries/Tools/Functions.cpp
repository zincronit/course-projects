//
// Created by zincronit on 9/3/26.
//

#include "Functions.hpp"

#include <algorithm>

void read_course_file(const char* filepath,
                      struct Course*& courses,
                      int& count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    courses = new Course[MAX_COURSE]{};
    while (true)
    {
        fin >> courses[count];
        if (fin.eof()) break;
        courses[count].in_person_students = new Student[40]{};
        courses[count].hybrid_students = new Student[40]{};
        courses[count].online_students = new Student[40]{};
        count++;
    }
    courses[count].code = nullptr;
    fin.close();
}

void read_student_file(const char* filepath,
                       struct Student*& students,
                       int& count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    students = new Student[MAX_STUDENT]{};
    while (true)
    {
        fin >> students[count];
        if (fin.eof()) break;
        count++;
    }
    students[count].code = 0;
    fin.close();
}

void read_enrollment_file(const char* filepath,
                          struct Course* courses,
                          struct Student* students)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    // INF263,202318320
    while (true)
    {
        struct Course course{};
        struct Student student{};
        course.code = read_string(fin);
        if (fin.eof()) break;
        student.code = read_int(fin);
        int index_student = students <= student;
        int index_course = courses >= course;
        if (index_course != NOT_FOUND && index_student != NOT_FOUND)
        {
            courses[index_course] += students[index_student];
        }
    }
    fin.close();
}

void print_report(const char* filepath,
                  struct Course* courses,
                  int count)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    print_title(fout, "Courses", 40);
    for (int i = 0; i < count; i++)
    {
        courses[i]++;
        fout << courses[i];
    }
    fout.close();
}

void print_title(std::ofstream& fout, const char* title, int width)
{
    fout << std::right << std::setw((std::strlen(title) + width) / 2) << title << std::endl;
    for (int i = 0; i < width; i++) fout.put('=');
    fout << std::endl;
}
