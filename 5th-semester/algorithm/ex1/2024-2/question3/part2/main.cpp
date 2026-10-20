//
// Created by zincronit on 10/16/26.
//

#include <iostream>
#include <cmath>

int get_digit_number(int number)
{
    int digit_count = 0;
    while (number > 0)
    {
        number /= 10;
        digit_count++;
    }
    return digit_count;
}


int count_digit_frequency(int number, int target_digit)
{
    int count = 0;
    while (number > 0)
    {
        int digit = number % 10;
        if (digit == target_digit) count++;
        number /= 10;
    }
    return count;
}

bool has_same_digits(int number, int candidate1, int candidate2)
{
    for (int i = 0; i < 10; i++)
    {
        if (not(count_digit_frequency(number, i) ==
                count_digit_frequency(candidate1, i) +
                count_digit_frequency(candidate2, i)))
        {
            return false;
        }
    }
    return true;
}

bool is_vampire(int number)
{
    int digit_number = get_digit_number(number);
    if (digit_number == 0 or digit_number % 2 != 0) return false;
    int new_digit_number = digit_number / 2;
    int min_limit = static_cast<int>(std::pow(10, new_digit_number - 1));
    int max_limit = static_cast<int>(std::pow(10, new_digit_number));

    for (int i = min_limit; i < max_limit; i++)
    {
        int candidate_number = number / i;
        if (get_digit_number(candidate_number) == new_digit_number)
        {
            if (has_same_digits(number, candidate_number, i))
                return true;
        }
    }
    return false;
}


int main()
{
    // std::cout << get_digit_number(045) << std::endl;
    int testCases[] = {1260, 136948, 1234, 1261};

    for (int num: testCases)
    {
        if (is_vampire(num))
        {
            std::cout << num << " es un numero vampiro." << std::endl;
        } else
        {
            std::cout << num << " NO es un numero vampiro." << std::endl;
        }
    }
    return 0;
}
