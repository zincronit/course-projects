//
// Created by zincronit on 10/4/26.
//

#include "Streamer.hpp"

#include <cstring>

Streamer::Streamer()
{
    account = nullptr;
    total_time = 0;
    avg_viewers = 0.0;
    follower_count = 0;
    category = nullptr;
}

Streamer::~Streamer()
{
    delete[] account;
    delete[] category;
}

void Streamer::get_account(char* dest_account) const
{
    if (this->account == nullptr)
    {
        dest_account[0] = '\0';
        return;
    }
    std::strcpy(dest_account, this->account);
}

void Streamer::set_account(const char* account_)
{
    delete[] this->account;
    this->account = new char[std::strlen(account_) + 1];
    std::strcpy(this->account, account_);
}

long long Streamer::get_total_time() const
{
    return this->total_time;
}

void Streamer::set_total_time(long long total_time_)
{
    this->total_time = total_time_;
}

float Streamer::get_avg_viewers() const
{
    return this->avg_viewers;
}

void Streamer::set_avg_viewers(float avg_viewers_)
{
    this->avg_viewers = avg_viewers_;
}

int Streamer::get_follower_count() const
{
    return this->follower_count;
}

void Streamer::set_follower_count(int follower_count_)
{
    this->follower_count = follower_count_;
}

void Streamer::get_category(char* category_) const
{
    if (this->category == nullptr)
    {
        category_[0] = '\0';
        return;
    }
    std::strcpy(category_, this->category);
}

void Streamer::set_category(const char* category_)
{
    delete[] this->category;
    this->category = new char[std::strlen(category_) + 1];
    std::strcpy(this->category, category_);
}

bool Streamer::read_streamer(std::ifstream& fin)
{
    char buffer[TEXT_LENGTH], character;
    fin.getline(buffer, TEXT_LENGTH, ',');
    if (fin.eof()) return false;
    fin >> account >> character;
    fin >> total_time >> character;
    fin >> avg_viewers >> character;
    fin >> follower_count >> character;
    fin >> category >> character;
    return true;
}

void Streamer::show_streamer(std::ostream& out) const
{
    int width = LINE_WIDTH / COLUMNS;
    out << std::left;
    out << std::setw(width) << account;
    out << std::setw(width) << total_time;
    out << std::setw(width) << avg_viewers;
    out << std::setw(width) << follower_count;
    out << category;
}

void Streamer::copy_streamer(const Streamer& streamer)
{
    char temp_account[TEXT_LENGTH]{}, temp_category[TEXT_LENGTH]{};
    streamer.get_account(temp_account);
    get_account(temp_account);
    total_time = streamer.get_total_time();
    avg_viewers = streamer.get_avg_viewers();
    follower_count = streamer.get_follower_count();
    streamer.get_category(temp_category);
    get_category(temp_category);
}
