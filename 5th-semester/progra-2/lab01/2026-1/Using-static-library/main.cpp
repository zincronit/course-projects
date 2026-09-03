//
// Created by zincronit on 9/3/26.
//

#include "Libraries/Tools/Functions.hpp"

int main()
{
    struct System system{};

    read_pet_file(
        "../Files/Data/pets.csv",
        system.pets,
        system.pet_count
    );
    read_veterinary_file(
        "../Files/Data/veterinaries.csv",
        system.veterinaries,
        system.veterinary_count
    );
    read_attention_file(
        "../Files/Data/attentions.csv",
        system.attentions,
        system.attention_count
    );
    print_pet_report(
        "../Files/Reports/pet_report.txt",
        system.pets,
        system.pet_count
    );
    print_pet_attention(
        "../Files/Reports/attention_report.txt",
        system.pets,
        system.pet_count,
        system.attentions,
        system.attention_count
    );

    return 0;
}
