//
// Created by zincronit on 9/3/26.
//

#include "overloads.hpp"

void operator >>(std::ifstream& fin, struct Course& course)
{
    // INF263,Algoritmia,3.75,35030611,INGA_FLORES_CESAR_ADOLFO
    char code[TEXT_LENGTH]{};
    int professor_code;
    fin.getline(code, TEXT_LENGTH, ',');
    if (fin.eof()) return;
    course.code = allocate_string(code);
    course.name = read_string(fin);
    course.credits = read_double(fin);
    professor_code = read_int(fin);
    course.professor = read_string(fin, '\n');
}

void operator >>(std::ifstream& fin, struct Student& student)
{
    // 202111260,GORDILLO/CASTRO/RONAL,P
    student.code = read_int(fin);
    if (fin.eof()) return;
    student.name = read_string(fin);
    fin.get(student.type);
    fin.get();
}

bool operator >(struct Student& student, int code)
{
    if (student.code == code) return true;
    return false;
}

bool operator >(struct Course& course, char* code)
{
    if (std::strcmp(code, course.code) == 0) return true;
    return false;
}

void operator +=(struct Course& course, struct Student& student)
{
    if (student.type == 'P')
    {
        course.in_person_students[course.in_person_count] = assign_student(student);
        course.in_person_count++;
    } else if (student.type == 'S')
    {
        course.hybrid_students[course.hybrid_count] = assign_student(student);
        course.hybrid_count++;
    } else if (student.type == 'V')
    {
        course.online_students[course.online_count] = assign_student(student);
        course.online_count++;
    }
}

int operator <=(struct Student* students, struct Student& student)
{
    for (int i = 0; students[i].code != 0; i++)
    {
        if (students[i] > student.code) return i;
    }
    return NOT_FOUND;
}

int operator >=(struct Course* courses, struct Course& course)
{
    for (int i = 0; courses[i].code != nullptr; i++)
    {
        if (courses[i] > course.code) return i;
    }
    return NOT_FOUND;
}

void operator ++(struct Course& course, int)
{
    int student_count = course.in_person_count + course.hybrid_count + course.online_count;
    double in_person_percentage = (double) course.in_person_count / student_count;
    in_person_percentage > 0.5
        ? course.final_type = allocate_string("La clase se dictara en el aula")
        : course.final_type = allocate_string("La clase sera 100% virual");
}

void operator <<(std::ofstream& fout, struct Course& course)
{
    print_text(fout, course.code, 15);
    fout << course.name << std::endl;
    fout << course.professor << std::endl;
    print_text(fout, "Alumnos presenciales: ", 30);
    fout << course.in_person_count << std::endl;
    print_text(fout, "Alumnos semiprecenciales: ", 30);
    fout << course.hybrid_count << std::endl;
    print_text(fout, "Alumnos virtuales: ", 30);
    fout << course.online_count << std::endl;
    fout << course.final_type << std::endl;
}
