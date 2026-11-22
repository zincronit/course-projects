//
// Created by zincronit on 11/21/26.
//
#include <iostream>

struct TreeNode
{

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

struct Tree
{
    TreeNode* root;

    Tree() { root = nullptr; }
    bool is_empty() const { return root == nullptr; }

    void insert(const int data)
    {
        append_node(root, data);
    }

    void append_node(TreeNode*& current, const int data)
    {
        if (current == nullptr)
        {
            current = new TreeNode(data);
            return;
        }
        if (data < current->data)
            append_node(current->left, data);
        else if (data > current->data)
            append_node(current->right, data);
        else
            std::cout << "Warring: the data has already been added" << std::endl;
    }

    void destroy()
    {
        destroy_nodes(root);
    }

    void destroy_nodes(TreeNode*& current)
    {
        if (current == nullptr) return;
        destroy_nodes(current->left);
        destroy_nodes(current->right);
        delete current;
        current = nullptr;
    }

    void print() const
    {
        if (is_empty())
        {
            std::cout << "tree is empty" << std::endl;
            return;
        }
        print_recursive(root);
        std::cout << std::endl;
    }
    void print_recursive(TreeNode* current) const
    {
        if (current == nullptr) return;
        print_recursive(current->left);
        std::cout << current->data << " ";
        print_recursive(current->right);
    }

    int compare(const int a, const int b) const
    {
        return a > b ? 1 : a < b ? -1 : 0 ;
    }

    bool search_recursive(const TreeNode* current, int data) const
    {
        if (current == nullptr) return false;
        switch (compare(current->data, data))
        {
            case 1: return search_recursive(current->left, data);
            case -1: return search_recursive(current->right , data);
            case 0 : return true;;
        }
    }

    bool has_element(const int data) const
    {
        return search_recursive(root, data);
    }

    void replace_node(const int value)
    {
        delete_node(root, value);
    }

    void delete_node(TreeNode*& current, const int data)
    {
        if (current == nullptr) return;
        if (current->data > data)
            delete_node(current->left,data);
        else if (current->data < data)
            delete_node(current->right, data);
        else
        {
            if (current->left == nullptr and current->right == nullptr)
            {
                delete current;
                current = nullptr;
            }
            else if (current->left == nullptr)
            {
                TreeNode* temp = current;
                current = current->right;
                delete temp;
            }
            else if (current->right == nullptr)
            {
                TreeNode* temp = current;
                current = current->left;
                delete temp;
            }
            else
            {
                TreeNode* successor = find_min(current->right);
                current->data = successor->data;
                delete_node(current->right, successor->data);
            }
        }
    }

    TreeNode* find_min(TreeNode* current)
    {
        while (current and current->right != nullptr)
            current = current->right;
        return current;
    }
};

int main()
{
    Tree tree;
    for (int i = 0 ; i < 10 ; i++) tree.insert(i);
    tree.print();
    tree.replace_node(0);
    tree.print();
    tree.destroy();
    tree.print();
    return 0;
}
