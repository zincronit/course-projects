//
// Created by zincronit on 11/22/26.
//

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

struct TreeNode
{
    int data;
    int height;
    TreeNode* left;
    TreeNode* right;

    // TreeNode(int x) : data(x), left(nullptr), right(nullptr){}
    TreeNode(int x)
    {
        data = x;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

struct Tree
{
    TreeNode* root;

    Tree() : root(nullptr) {};

    void insert(int value)
    {
        insert_recursive(root, value);
    }

    void insert_recursive(TreeNode*& current, int value)
    {
        if (current == nullptr)
        {
            current = new TreeNode(value);
            return;
        }
        if (current->data > value)
            insert_recursive(current->left, value);
        else if (current->data < value)
            insert_recursive(current->right, value);
    }

    void print_hierarchy(const TreeNode* current, std::string prefix, bool is_left_child) const
    {
        if (current == nullptr) return;
        print_hierarchy(current->right, prefix + (is_left_child ? "|   " : "    "), false);
        std::cout << prefix << (is_left_child ? "└── " : "┌── ");
        std::cout << current->data << std::endl;
        print_hierarchy(current->left, prefix + (is_left_child ? "    " : "|   "), true);
    }

    void print() const
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty\n";
            return;
        }
        print_hierarchy(root->right, "", false);
        std::cout << root->data << std::endl;
        print_hierarchy(root->left, "", true);
        std::cout << std::endl;
    }

    static int get_height(const TreeNode* node)
    {
        if (node == nullptr) return 0;
        return node->height;
    }

    static int get_balance_factor(const TreeNode* node)
    {
        if (node == nullptr) return 0;
        return get_height(node->left) - get_height(node->right);
    }

    static void update_height(TreeNode* node)
    {
        if (node == nullptr) return;
        const int left_h = get_height(node->left);
        const int right_h = get_height(node->right);
        node->height = std::max(left_h, right_h) + 1;
    }

    static TreeNode* rotate_right(TreeNode* z)
    {
        TreeNode* y = z->left;
        TreeNode* t3 = y->right;
        y->right = z;
        z->left = t3;
        update_height(z);
        update_height(y);
        return y;
    }

    static TreeNode* rotate_left(TreeNode* z)
    {
        TreeNode* y = z->right;
        TreeNode* t3 = y->left;
        y->left = z;
        z->right = t3;
        update_height(z);
        update_height(y);
        return y;
    }

    TreeNode* insert_node(TreeNode* node, int value)
    {
        if (node == nullptr) return new TreeNode(value);

        if (node->data > value)
            node->left = insert_node(node->left, value);
        else if (node->data < value)
            node->right = insert_node(node->right, value);
        else return node;

        update_height(node);
        int balance_factor = get_balance_factor(node);

        if (balance_factor > 1 and get_balance_factor(node->left) >= 0)
            return rotate_right(node);
        if (balance_factor < -1 and get_balance_factor(node->right) <= 0)
            return rotate_left(node);
        if (balance_factor > 1 and get_balance_factor(node->left) < 0)
        {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }
        if (balance_factor < -1 and get_balance_factor(node->right) > 0)
        {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }
        return node;
    }

    void balance_insert(int value)
    {
        root = insert_node(root, value);
    }
};


int main()
{
    Tree tree;
    // tree.insert(9);
    // tree.insert(4);
    // tree.insert(1);
    // tree.insert(6);
    // tree.insert(14);
    // tree.insert(11);
    // tree.insert(16);
    // tree.insert(19);
    // tree.insert(2);
    // tree.insert(15);
    for (int i = 0 ; i < 15 ; i++) tree.balance_insert(i);
    tree.print();
    return 0;
}
