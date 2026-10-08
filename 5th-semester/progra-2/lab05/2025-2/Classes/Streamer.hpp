//
// Created by zincronit on 10/4/26.
//

#ifndef INC_2025_2_STREAMER_HPP
#define INC_2025_2_STREAMER_HPP

#include "../Utils.hpp"

class Streamer
{
public:

    Streamer();
    virtual ~Streamer();
    void get_account(char*) const;
    void set_account(const char*);
    long long get_total_time() const;
    void set_total_time(long long);
    float get_avg_viewers() const;
    void set_avg_viewers(float);
    int get_follower_count() const;
    void set_follower_count(int);
    void get_category(char*) const;
    void set_category(const char*);

    // methods
    bool read_streamer(std::ifstream& );
    void show_streamer(std::ostream& ) const ;
    void copy_streamer(const Streamer& );


private:
    char* account;
    long long total_time;
    float avg_viewers;
    int follower_count;
    char* category;
};


#endif //INC_2025_2_STREAMER_HPP
