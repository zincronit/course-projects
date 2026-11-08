//
// Created by zincronit on 11/7/26.
//

#include "CareManager.hpp"

CareManager::CareManager()
{
    attentions = nullptr;
    count = 0;
    capacity = 0;
}

CareManager::~CareManager() { delete[] attentions; }
int CareManager::get_count() const { return count; }
void CareManager::set_count(const int count) { this->count = count; }
int CareManager::get_capacity() const { return capacity; }
void CareManager::set_capacity(const int capacity) { this->capacity = capacity; }

void CareManager::append_attention_capacity()
{
    capacity += INCREASE;
    class Attention** aux = new Attention *[capacity]{};
    if (capacity == INCREASE)
    {
        attentions = aux;
        return;
    }
    for (int i = 0; i < count; i++)
        aux[i] = attentions[i];
    delete[] attentions;
    attentions = aux;
}

void CareManager::append_attention(class Attention* attention)
{
    if (attention == nullptr) return;
    if (count >= capacity - 1)
        append_attention_capacity();
    attentions[count] = attention;
    count++;
}

class Attention* CareManager::allocate_attention_memory(const char type)
{
    class Attention* attention = nullptr;
    switch (type)
    {
        case '1':
            attention = new class Emergency;
            break;
        case '2':
            attention = new class Urgency;
            break;
        case '3':
            attention = new class NotUrgent;
            break;
        default:
            std::cout << "Invalid type" << std::endl;
            break;
    }
    return attention;
}

void CareManager::load_attentions(const std::string& filepath, const int hour)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    char type;
    while (true)
    {
        input.get(type);
        if (input.eof()) break;
        input.ignore();
        class Attention* attention = allocate_attention_memory(type);
        attention->read(input, hour);
        append_attention(attention);
    }
    input.close();
}

void CareManager::process_day(const std::string& date)
{
    std::string base_path = Utils::generate_filepath(date);
    for (int i = 0; i < 24; i++)
    {
        std::string filename;
        filename += static_cast<char>('0' + i / 10);
        filename += static_cast<char>('0' + i % 10);
        filename += ".csv";
        load_attentions(base_path + filename, i);
    }
}

void CareManager::generate_report(const std::string& filepath) const
{
    std::ofstream output;
    Utils::open_output_file(output, filepath);
    int width = LINE_WIDTH / COLUMNS;
    for (int k = 0; k < 24; k++)
    {
        Utils::print_line(output);
        std::string hour;
        hour += static_cast<char>('0' + k / 10);
        hour += static_cast<char>('0' + k % 10);
        output << "HORA: " + hour + ":00\n";
        Utils::print_line(output);
        Utils::print_line(output, '-');
        output << "EMERGENICIAS\n";
        Utils::print_line(output, '-');
        std::string headers[] = {"CODIGO", "NOMBRES", "DESCRIPCION", "RCP?", "NO_PULSO"};
        for (int i = 0; i < 5; i++) Utils::print_text(output, headers[i], width);
        output << std::endl;
        //
        for (int i = 0; i < count; i++)
        {
            if (attentions[i]->get_priority() == 1 and attentions[i]->get_hour() == k)
                attentions[i]->print(output);
        }
        //
        Utils::print_line(output ,'-');
        output << "URGENCIAS\n";
        Utils::print_line(output , '-');
        std::string headers2[] = {"CODIGO", "NOMBRES", "DESCRIPCION", "ZONA_LESION", "RX?"};
        for (int i = 0; i < 5; i++) Utils::print_text(output, headers[i], width);
        output << std::endl;
        for (int i = 0; i < count; i++)
        {
            if (attentions[i]->get_priority() == 2 and attentions[i]->get_hour() == k)
                attentions[i]->print(output);
        }
        //
        Utils::print_line(output, '-');
        output << "NO URGENCIAS\n";
        Utils::print_line(output , '-');
        std::string headers3[] = {"CODIGO", "NOMBRES", "DESCRIPCION", "ESPECIALIDAD"};
        for (int i = 0; i < 4; i++) Utils::print_text(output, headers[i], width);
        output << std::endl;
        //
        for (int i = 0; i < count; i++)
        {
            if (attentions[i]->get_priority() == 3 and attentions[i]->get_hour() == k)
                attentions[i]->print(output);
        }
    }
}
