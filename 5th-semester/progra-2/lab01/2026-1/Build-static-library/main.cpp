//
// Created by zincronit on 9/2/26.
//

#include "Libraries/Overloads/overloads.hpp"

int main()
{
    std::ifstream petFile, vetFile, attFile;
    std::ofstream output, fout;

    struct Pet pets[15]{};
    struct Veterinary veterinaries[8]{};
    struct Attention attentions[12]{};

    open_input_file(petFile, "../Files/Data/pets.csv");
    open_input_file(vetFile, "../Files/Data/veterinaries.csv");
    open_input_file(attFile, "../Files/Data/attentions.csv");

    open_output_file(fout , "../Files/Reports/pets.txt");
    open_output_file(output , "../Files/Reports/attentions.txt");
    for (int i = 0; i < 15 ; i++)
    {
        petFile >> pets[i];
        fout << pets[i];
    }
    for (int i = 0; i < 9 ; i++)
    {
        vetFile >> veterinaries[i];
    }
    for (int i = 0; i < 13 ; i++)
    {
        attFile >> attentions[i];
        output << attentions[i];
    }
    std::cout << (pets[2] <= 20250407) << std::endl;
    std::cout << (attentions[8] == attentions[5]) << std::endl;

    return 0;
}