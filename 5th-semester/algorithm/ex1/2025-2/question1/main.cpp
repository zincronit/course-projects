//
// Created by zincronit on 10/14/26.
//

#include <iostream>
#include <cmath>


#define N 2

struct Alert
{
    int code;
    int priority;
    int start_hour;
    int duration;
};

void clear_gene(int* gene, int size)
{
    for (int i = 0; i < size; i++) gene[i] = 0;
}

void initialize_gene(int* gene, int status)
{
    int i = 0, number;
    while (status > 0)
    {
        number = status % N;
        status /= N;
        gene[i] = number;
        i++;
    }
}

void print_gene(int* gene, int size, struct Alert* alerts)
{
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (gene[i] == 0) continue;
        if (flag)
        {
            std::cout << " | ";
        }
        std::cout << alerts[i].code << " P" << alerts[i].priority;
        flag = true;
    }
    std::cout << std::endl;
}

bool is_valid_combination(int* gene,
                          struct Alert* alerts,
                          int size,
                          int status,
                          int target_P1,
                          int target_P2,
                          int target_P3)
{
    int count_P1 = 0, count_P2 = 0, count_P3 = 0;
    int schedule[24]{};
    for (int i = 0; i < size; i++)
    {
        if (gene[i] == 0) continue;
        if (alerts[i].priority == 1) count_P1++;
        else if (alerts[i].priority == 2) count_P2++;
        else if (alerts[i].priority == 3) count_P3++;

        int total_time = alerts[i].duration;
        if (alerts[i].priority == 1) total_time++;

        int start = alerts[i].start_hour;
        int end = start + total_time;

        if (start < 8 || end > 17) return false;

        for (int h = start; h < end; h++)
        {
            if (h == 13) return false;
            if (schedule[h] != 0) return false;
            schedule[h] = 1;
        }
    }
    return count_P1 == target_P1 && count_P2 == target_P2 && count_P3 == target_P3;
}

int main()
{
    struct Alert alerts[] = {
        {1801, 2, 8, 1},
        {1802, 1, 8, 1},
        {1803, 1, 9, 1},
        {1804, 3, 9, 3},
        {1805, 1, 10, 1},
        {1806, 1, 11, 1},
        {1807, 3, 12, 1},
        {1808, 1, 14, 1},
        {1809, 2, 14, 2},
        {1810, 3, 14, 1},
        {1811, 2, 15, 1},
        {1812, 3, 16, 1},
        {1813, 2, 16, 2}
    };
    int size = sizeof(alerts) / sizeof(alerts[0]);
    int gene[size];
    int number_combinations = static_cast<int>(pow(N, size));

    int P1 = 1, P2 = 2, P3 = 3;

    for (int i = 0; i < number_combinations; i++)
    {
        clear_gene(gene, size);
        initialize_gene(gene, i);
        if (is_valid_combination(gene, alerts, size, i, P1, P2, P3))
            print_gene(gene, size, alerts);
    }
    return 0;
}
