//
// Created by zincronit on 10/4/26.
//

#include "StreamerManager.hpp"

StreamerManager::StreamerManager()
{
    data = nullptr;
    data_view = nullptr;
    data_count = 0;
    data_view_count = 0;
}

StreamerManager::~StreamerManager()
{
    delete [] data;
    delete [] data_view;
}

void StreamerManager::load_data()
{
    std::ifstream fin;
    fin.open("../Data/streamers.csv", std::ios::in);
    if (not fin.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        std::exit(1);
    }
    Streamer streamers[MAX_STREAMER];
    while (true)
    {
        streamers[data_count].read_streamer(fin);
        if (fin.eof()) break;
        data_count++;
    }
    data = new Streamer[data_count]{};
    for (int i = 0; i < data_count; i++)
        data[i].copy_streamer(streamers[i]);
    fin.close();
}

const char *menu =
        "1) Cargar datos\n"
        "2) Mostrar Reporte\n"
        "    1) Reporte Top10 streamers por número de seguidores\n"
        "    2) Reporte Bottom10 streamers por tiempo total transmitido\n"
        "    3) Reporte Top5 categoría con mayor promedio de espectadores\n"
        "    4) Reporte de Categoría\n"
        "    5) Reporte de Influencia\n"
        "3) Generar Reporte\n"
        "    1) Reporte Top10 streamers por número de seguidores\n"
        "    2) Reporte Bottom10 streamers por tiempo total transmitido\n"
        "    3) Reporte Top5 categoría con mayor promedio de espectadores\n"
        "    4) Reporte de Categoría\n"
        "    5) Reporte de Influencia\n"
        "4) Generar todos los reportes\n"
        "5) Terminar\n";

void StreamerManager::show_menu()
{
    bool is_runnig = true;
    char option1 , option2;
    while (is_runnig)
    {
        std::cout << menu << std::endl;
        std::cin >> option1;
        switch (option1)
        {
            case '1':
                load_data();
                break;
            case '2':
                std::cin >> option2;
                
        }
    }
}

void StreamerManager::copy_data(int) {}
void StreamerManager::show_view_data(std::ostream&) {}
