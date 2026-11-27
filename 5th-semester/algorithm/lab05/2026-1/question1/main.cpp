//
// Created by zincronit on 11/22/26.
//

#include <iostream>
#include <queue>
#include <stack>

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

struct Tree
{
    TreeNode* root;
    Tree() : root(nullptr) {}
    void insert(int value) { insert_node(root, value); }

    void insert_node(TreeNode*& node, int value)
    {
        if (node == nullptr)
        {
            node = new TreeNode(value);
            return;
        }
        if (node->data > value) insert_node(node->left, value);
        else if (node->data < value) insert_node(node->right, value);
        else std::cout << "Can not insert same data" << std::endl;
    }

    void print() const
    {
        print_iterative(root);
    }

    void print_iterative(TreeNode* node) const
    {
        std::queue<TreeNode *> queue;
        std::stack<int> stack;
        queue.push(node);
        bool is_left_to_right = true;
        std::size_t level = 1;
        while (not queue.empty())
        {
            std::cout << "Level " << level << ": ";
            std::size_t size = queue.size();
            for (std::size_t i = 0; i < size; i++)
            {
                TreeNode* current = queue.front();
                queue.pop();
                if (is_left_to_right)
                    std::cout << current->data << " ";
                else
                    stack.push(current->data);

                if (current->left != nullptr) queue.push(current->left);
                if (current->right != nullptr) queue.push(current->right);
            }
            while (not stack.empty())
            {
                std::cout << stack.top() << " ";
                stack.pop();
            }
            std::cout << std::endl;
            level++;
            is_left_to_right = not is_left_to_right;
        }
    }
};


int main()
{
    Tree tree;
    tree.insert(9);
    tree.insert(4);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(11);
    tree.insert(16);
    tree.insert(19);
    tree.print();
    return 0;
}
