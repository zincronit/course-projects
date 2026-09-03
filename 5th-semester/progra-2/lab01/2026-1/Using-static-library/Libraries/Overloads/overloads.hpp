//
// Created by zincronit on 9/2/26.
//

#ifndef BUILD_STATIC_LIBRARY_OVERLOADS_HPP
#define BUILD_STATIC_LIBRARY_OVERLOADS_HPP

#include "../Utils/AuxiliaryFunctions.hpp"
#include "../Structs/Pet.hpp"
#include "../Structs/Veterinary.hpp"
#include "../Structs/Attention.hpp"
#include "../Structs/System.hpp"


void operator >>(std::ifstream& fin , struct Pet& pet);
void operator >>(std::ifstream& fin, struct Veterinary& veterinary);
void operator >>(std::ifstream& fin, struct Attention& attention);
bool operator ==(struct Attention& attention , struct Attention& attention2);
bool operator <=(struct Pet& pet, int date);
void operator <<(std::ofstream& fout, struct Pet& pet);
void operator <<(std::ofstream& fout, struct Attention& attention);


#endif //BUILD_STATIC_LIBRARY_OVERLOADS_HPP
