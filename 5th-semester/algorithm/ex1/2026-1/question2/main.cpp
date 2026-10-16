//
// Created by zincronit on 10/15/26.
//


#include <iostream>
#include <cstring>


int find_word(
    const char* text,
    const char* word,
    int text_index = 0,
    int word_index = 0,
    bool is_valid_word = true)
{
    if (text[text_index] == '\0')
    {
        if (word[word_index] == '\0' and is_valid_word)
        {
            return 1;
        }
        return 0;
    }

    if (text[text_index] == ' ')
    {
        if (is_valid_word and word[word_index] == '\0')
        {
            return 1 + find_word(text, word, text_index + 1, 0, true);
        }
        return find_word(text, word, text_index + 1, 0, true);
    }

    if (is_valid_word and text[text_index] == word[word_index])
    {
        return find_word(text, word, text_index + 1, word_index + 1, true);
    }

    return find_word(text, word, text_index + 1, 0, false);
}

int word_count(
    const char* text,
    const char* word,
    int text_index = 0,
    int word_index = 0)
{
    if (text[text_index] == '\0')
    {
        if (word[word_index] == '\0')
        {
            return 1;
        }
        return 0;
    }
    if (word[word_index] == '\0')
    {
        return 1 + word_count(text, word, text_index, 0);
    }
    if (text[text_index] == word[word_index])
    {
        return word_count(text, word, text_index + 1, word_index + 1);
    }
    return word_count(text, word, text_index + 1, 0);
}

int main()
{
    const char* text = "hola holahola holaholahola ";
    const char* word = "hola";
    // int number_of_words = find_word(text, word);
    int number_of_words = word_count(text, word);
    std::cout << number_of_words << std::endl;
    return 0;
}
