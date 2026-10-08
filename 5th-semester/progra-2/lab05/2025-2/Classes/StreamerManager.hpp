//
// Created by zincronit on 10/4/26.
//

#ifndef INC_2025_2_STREAMERMANAGER_HPP
#define INC_2025_2_STREAMERMANAGER_HPP

#include "Streamer.hpp"

class StreamerManager
{
public:
    StreamerManager();
    ~StreamerManager();
    void load_data();
    void show_menu();
    void copy_data(int );
    void show_view_data(std::ostream& );
    

private:
    Streamer* data;
    Streamer* data_view;
    int data_count;
    int data_view_count;
};


#endif //INC_2025_2_STREAMERMANAGER_HPP
