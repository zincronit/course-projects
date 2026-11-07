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
    class Attention** aux = new Attention *[capacity];
    if (capacity == INCREASE)
    {
        aux = attentions;
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

class Attention* CareManager::allocate_attention_memory(char type)
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
        filename += static_cast<char>('0' + (i / 10));
        filename += static_cast<char>('0' + (i % 10));
        filename += ".csv";
        load_attentions(base_path + filename, i);
    }
}
