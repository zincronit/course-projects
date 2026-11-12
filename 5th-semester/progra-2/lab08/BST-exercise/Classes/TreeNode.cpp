//
// Created by zincronit on 11/11/26.
//

#include "TreeNode.hpp"

TreeNode::TreeNode()
{
    appointment = nullptr;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(const class Attention* attention)
{
    left = nullptr;
    right = nullptr;
    appointment = attention->clone();
}

TreeNode::~TreeNode()
{
    std::cout << "hello, I using this" << std::endl;
}
