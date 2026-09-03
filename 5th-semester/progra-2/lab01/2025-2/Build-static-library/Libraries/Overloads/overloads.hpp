//
// Created by zincronit on 9/3/26.
//

#ifndef BUILD_STATIC_LIBRARY_OVERLOADS_HPP
#define BUILD_STATIC_LIBRARY_OVERLOADS_HPP

#include "../Utils/AuxiliaryFunctions.hpp"


void operator >>(std::ifstream& fin, struct Course& course);
void operator >>(std::ifstream& fin, struct Student& student);
bool operator >(struct Student& student, int code);
bool operator >(struct Course& course , char* code);
void operator +=(struct Course& course , struct Student& student);
int operator <=(struct Student* students, struct Student& student);
int operator >=(struct Course* courses, struct Course& course);
void operator ++(struct Course& course , int);
void operator <<(std::ofstream& fout, struct Course& course);



#endif //BUILD_STATIC_LIBRARY_OVERLOADS_HPP
