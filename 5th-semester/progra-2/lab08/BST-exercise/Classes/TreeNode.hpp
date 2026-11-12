//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_TREENODE_HPP
#define BST_EXERCISE_TREENODE_HPP

#include "Attention.hpp"

class TreeNode
{
public:
    TreeNode();
    TreeNode(const class Attention* );
    ~TreeNode();
    friend class SearchBinaryTree;
private:
    class Attention* appointment;
    class TreeNode* left;
    class TreeNode* right;
};


#endif //BST_EXERCISE_TREENODE_HPP
