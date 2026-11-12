//
// Created by zincronit on 11/11/26.
//

#ifndef BST_EXERCISE_SEARCHBINARYTREE_HPP
#define BST_EXERCISE_SEARCHBINARYTREE_HPP

#include "TreeNode.hpp"
class SearchBinaryTree
{
public:
    SearchBinaryTree();
    ~SearchBinaryTree();

    void insert(const class Attention* );
    void print(std::ofstream& , const int) const;
    void destroy();
private:
    class TreeNode* root;
    void insert_sort(class TreeNode*& , const class Attention* );
    void print_tree(TreeNode* , std::ofstream& ,const int ) const;
    void delete_node(class TreeNode*& );

};


#endif //BST_EXERCISE_SEARCHBINARYTREE_HPP
