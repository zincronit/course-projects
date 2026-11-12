//
// Created by zincronit on 11/12/26.
//

#ifndef GEMNINI_EXERCISE_TREENODE_HPP
#define GEMNINI_EXERCISE_TREENODE_HPP

#include "TreeNode.hpp"
#include "../Sale.hpp"
class TreeNode
{
public:
    TreeNode();
    ~TreeNode();
    friend class SearchBinaryTree;
private:
    class Sale sale;
    class TreeNode* left;
    class TreeNode* right;
};


#endif //GEMNINI_EXERCISE_TREENODE_HPP
