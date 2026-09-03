//
// Created by zincronit on 9/2/26.
//

#ifndef BUILD_STATIC_LIBRARY_ATTENTION_HPP
#define BUILD_STATIC_LIBRARY_ATTENTION_HPP

// enum AttentionType
// {
//     Vaccination,
//     Sterilization,
//     Control
// };

struct Attention
{
    int id;
    int pet_id;
    int veterinary_id;
    int date;
    char* type;
    int hour;
    int minute;
    char* status;
};

#endif //BUILD_STATIC_LIBRARY_ATTENTION_HPP
