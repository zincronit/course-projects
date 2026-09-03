//
// Created by zincronit on 9/3/26.
//

#include "Libraries/Overloads/overloads.hpp"

int main()
{
    std::ifstream input, fin;
    std::ofstream fout;
    struct Student students[100]{};
    struct Course courses[10]{};

    open_input_file(fin, "../Files/Data/students.csv");
    open_input_file(input, "../Files/Data/courses.csv");
    open_output_file(fout, "../Files/Reports/report.txt");
    for (int i = 0; i < 100; i++)
    {
        fin >> students[i];
    }
    for (int i = 0; i < 7; i++)
    {
        input >> courses[i];
        std::cout << courses[i].code << std::endl;
    }
    char code[10] = "INF246";
    std::cout << (students[5] > 202113758) << std::endl;
    std::cout << (courses[5] > code) << std::endl;
    courses[0].in_person_students = new Student[5]{};
    courses[0] += students[0];
    std::cout << (students <= students[5]) << std::endl;
    std::cout << (courses >= courses[0]) << std::endl;
    courses[0] ++;
    std::cout << courses[0].final_type << std::endl;
    fout << courses[0];
    return 0;
}
