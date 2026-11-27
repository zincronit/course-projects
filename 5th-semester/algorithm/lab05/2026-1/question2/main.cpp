//
// Created by zincronit on 11/26/26.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct TreeNode
{
    std::string word;
    int frequency;
    TreeNode* left;
    TreeNode* right;
    TreeNode(std::string new_word) : word(new_word), frequency(1), left(nullptr), right(nullptr) {}
};

struct Tree
{
    TreeNode* root;
    Tree() : root(nullptr) {};

    void insert(const std::string& word)
    {
        insert_node(root, word);
    }

    void insert_node(TreeNode*& node, const std::string& word)
    {
        if (node == nullptr)
        {
            node = new TreeNode(word);
            return;
        }
        if (node->word.compare(word) > 0) insert_node(node->left, word);
        else if (node->word.compare(word) < 0) insert_node(node->right, word);
        else node->frequency++;
    }

    void print()
    {
        print_node(root);
    }

    void print_node(TreeNode* node)
    {
        if (node == nullptr) return;
        print_node(node->left);

        std::cout << std::setw(8) << node->word << "|  " << node->frequency << std::endl;
        print_node(node->right);
    }
};

struct Letter
{
    char letter;
    Tree tree;
};

// int binary_search(struct Letter* array, const int left, const int right, const char letter)
// {
//     if (left > right) return -1;
//     const int mid = (left + right) / 2;
//     if (array[mid].letter == letter) return mid;
//     if (array[mid].letter > letter)
//         return binary_search(array, left, mid - 1, letter);
//     if (array[mid].letter < letter)
//         return binary_search(array, mid + 1, right, letter);
// }

void read_file(const std::string& filename, struct Letter* letters)
{
    std::ifstream input(filename);
    if (not input.is_open())
    {
        std::cout << "Could not open " << filename << std::endl;
        exit(1);
    }
    while (true)
    {
        std::string word;
        input >> word;
        if (input.eof()) break;
        // int index = binary_search(letters, 0, 25, word[0]);
        int index = word[0] - 'a';
        if (index == -1)
        {
            std::cout << "ta mal" << std::endl;
            continue;
        }
        letters[index].tree.insert(word);
    }
    input.close();
}

int main()
{
    struct Letter letters[26]{};
    for (std::size_t i = 0; i < 26; ++i)
    {
        letters[i].letter = 'a' + i;
        // std::cout << letters[i].letter << std::endl;
    }
    read_file("../Data.txt", letters);

    for (std::size_t i = 0; i < 26; ++i)
    {
        std::cout << letters[i].letter << ": \n";
        letters[i].tree.print();
        std::cout << std::endl;
    }
    return 0;
}
