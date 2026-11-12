//
// Created by zincronit on 11/11/26.
//

#include "AttentionManager.hpp"

void AttentionManager::load_attentions(const std::string& filepath)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    while (true)
    {
        class Attention* attention = nullptr;
        switch (input.peek())
        {
            case '1':
                attention = new Emergency();
                break;
            case '2':
                attention = new Urgency();
                break;
            case '3':
                attention = new NonUrgency();
                break;
            default:
                std::cout << "end of file" << std::endl;
        }
        if (input.eof()) break;
        attention->read(input);
        tree.insert(attention);
    }
}

void AttentionManager::print_attentions(const std::string& filepath) const
{
    std::ofstream output;
    Utils::open_output_file(output, filepath);
    Utils::print_title(output);
    print_emergency(output);
    print_urgency(output);
    print_non_urgency(output);
}

void AttentionManager::print_emergency(std::ofstream& output) const
{
    output << "EMERGENCIAS\n";
    const std::string headers[] = {
        "PRIORIDAD", "CODIGO", "PACIENTE", "DESCRIPCION", "RCP", "NO PULSO"
    };
    for (int i = 0 ; i < sizeof(headers)/sizeof(headers[0]); i++)
        Utils::print_text(output , headers[i] , WIDTH);
    output << std::endl;
    tree.print(output, 1);
    Utils::print_line(output);
}

void AttentionManager::print_urgency(std::ofstream& output) const
{
    output << "URGENCIAS\n";
    const std::string headers[] = {
        "PRIORIDAD", "CODIGO", "PACIENTE", "DESCRIPCION", "ZONA LESION", "NO RX"
    };
    for (int i = 0 ; i < sizeof(headers)/sizeof(headers[0]); i++)
        Utils::print_text(output , headers[i] , WIDTH);
    output << std::endl;
    tree.print(output, 2);
    Utils::print_line(output);
}
void AttentionManager::print_non_urgency(std::ofstream& output) const
{
    output << "NO URGENCIAS\n";
    const std::string headers[] = {
        "PRIORIDAD", "CODIGO", "PACIENTE", "DESCRIPCION", "ESPECIALIDAD", "PROGRAMADA"
    };
    for (int i = 0 ; i < sizeof(headers)/sizeof(headers[0]); i++)
        Utils::print_text(output , headers[i] , WIDTH);
    output << std::endl;
    tree.print(output, 3);
    Utils::print_line(output);
}
