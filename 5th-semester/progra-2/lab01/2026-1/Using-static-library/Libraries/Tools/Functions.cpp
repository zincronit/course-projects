//
// Created by zincronit on 9/3/26.
//

#include "Functions.hpp"

void read_pet_file(const char* filepath, struct Pet*& pets, int& count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    pets = new struct Pet[MAX_PET]{};
    while (true)
    {
        fin >> pets[count];
        if (fin.eof()) break;
        count++;
    }
    fin.close();
}

void read_veterinary_file(const char* filepath, struct Veterinary*& veterinaries, int& count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    veterinaries = new struct Veterinary[MAX_VETERINARY]{};
    while (true)
    {
        fin >> veterinaries[count];
        if (fin.eof()) break;
        count++;
    }
    fin.close();
}

void read_attention_file(const char* filepath, struct Attention*& attentions, int& count)
{
    std::ifstream fin;
    open_input_file(fin, filepath);
    attentions = new struct Attention[MAX_ATTENTION]{};
    int attention_count = 0;
    bool is_first_reading = true;
    while (true)
    {
        struct Attention attention{};
        fin >> attention;
        if (fin.eof()) break;
        if (is_first_reading)
        {
            is_first_reading = false;
            assign_attention(attentions[count], attention);
            count++;
            continue;
        }
        if (attention == attentions[count])
        {
            std::cout << "Horario del veterinario ID: " << attention.veterinary_id;
            std::cout << " el " << attention.date;
            std::cout << " a las " << attention.hour << ':' << attention.minute << std::endl;
            attention_count++;
            continue;
        }
        count++;
        assign_attention(attentions[count], attention);
    }
    std::cout << attention_count << " ATENCIONES SIN PROGRAMAR " << std::endl;
}

void assign_attention(struct Attention& a, struct Attention& b)
{
    a.id = b.id;
    a.pet_id = b.pet_id;
    a.veterinary_id = b.veterinary_id;
    a.date = b.date;
    a.type = allocate_string(b.type);
    a.hour = b.hour;
    a.minute = b.minute;
    a.status = allocate_string(b.status);
}

char* allocate_string(const char* str)
{
    char* string = new char[std::strlen(str) + 1];
    std::strcpy(string, str);
    return string;
}


void print_pet_report(const char* filepath, struct Pet* pets, int count)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    print_title(fout, "MASCOTAS QUE DEBEN SER ESTERILIZADAS", LINE_WIDTH);
    for (int i = 0; i < count; i++)
    {
        if (pets[i] <= 20251010) fout << pets[i];
    }
    fout.close();
}

void print_pet_attention(const char* filepath,
                         struct Pet* pets,
                         int pet_count,
                         struct Attention* attentions,
                         int attention_count)
{
    std::ofstream fout;
    open_output_file(fout, filepath);
    int attention_number = 0;
    print_title(fout, "LISTADO DE MASCOTAS Y SUS ATENCIONES", LINE_WIDTH);
    for (int i = 0; i < pet_count; i++)
    {
        fout << pets[i];
        bool has_attention = false;
        for (int j = 0; j < attention_count; j++)
        {
            if (attentions[j].pet_id == pets[i].id)
            {
                attentions[j].id = 1002 + attention_number;
                fout << attentions[j];
                has_attention = true;
                attention_number++;
            }
        }
        if (not has_attention) fout << "No tiene atencion registrada" << std::endl;
    }
    fout << "TOTAL: " << pet_count << " mascotas, " << attention_number << "atenciones";
    fout.close();
}

void print_line(std::ofstream& fout, int width, char character)
{
    for (int i = 0; i < width; i++) fout.put(character);
    fout << std::endl;
}

void print_title(std::ofstream& fout, const char* title, int width)
{
    print_line(fout, width, '=');
    fout << std::right << std::setw((std::strlen(title) + width) / 2) << title << std::endl;
    print_line(fout, width, '=');
}
