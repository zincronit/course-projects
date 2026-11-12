//
// Created by zincronit on 11/11/26.
//

#include "SearchBinaryTree.hpp"


SearchBinaryTree::SearchBinaryTree() { root = nullptr; }
SearchBinaryTree::~SearchBinaryTree() { destroy(); }

void SearchBinaryTree::insert(const class Attention* appointment)
{
    insert_sort(root, appointment);
}

void SearchBinaryTree::print(std::ofstream& output,const int type) const
{
    print_tree(root, output, type);
}

void SearchBinaryTree::destroy()
{
    delete_node(root);
}

void SearchBinaryTree::insert_sort(class TreeNode*& current, const class Attention* attention)
{
    if (current == nullptr)
    {
        class TreeNode* new_node = new TreeNode(attention);
        current = new_node;
        return;
    }
    if (current->appointment->get_key() > attention->get_key())
        insert_sort(current->left, attention);
    else
        insert_sort(current->right, attention);
}

void SearchBinaryTree::print_tree(TreeNode* current, std::ofstream& output, const int type) const
{
    if (current == nullptr) return;
    print_tree(current->left, output, type);
    if (type == current->appointment->get_key() / 10000)
        current->appointment->print(output);
    print_tree(current->right, output, type);
}

void SearchBinaryTree::delete_node(class TreeNode*& current)
{
    if (current == nullptr) return;
    delete_node(current->left);
    delete_node(current->right);
    delete current->appointment;
    delete current;
    current = nullptr;
}
