//
// Created by zincronit on 11/22/26.
//

#include <iostream>
#include <stack>
#include <queue>

struct Data
{
    int id;
    bool is_malware;
};

struct TreeNode
{
    struct Data data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(struct Data data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct Tree
{
    TreeNode* root;

    Tree() { root = nullptr; }
    bool is_empty() const { return root == nullptr; }

    void insert(const struct Data data)
    {
        append_node(root, data);
    }

    void append_node(TreeNode*& current, const Data data)
    {
        if (current == nullptr)
        {
            current = new TreeNode(data);
            return;
        }
        if (data.id < current->data.id)
            append_node(current->left, data);
        else if (data.id > current->data.id)
            append_node(current->right, data);
        else
            std::cout << "Warring: the data has already been added" << std::endl;
    }

    static int compare(const int a, const int b)
    {
        return a > b ? 1 : a < b ? -1 : 0;
    }

    TreeNode* find_node(TreeNode* current, const struct Data data) const
    {
        if (current == nullptr) return nullptr;
        switch (compare(current->data.id, data.id))
        {
            case 1: return find_node(current->left, data);
            case -1: return find_node(current->right, data);
            case 0: return current;
        }
    }

    void print_by_level() const
    {
        amplitude(root);
    }

    void amplitude(TreeNode* current) const
    {
        std::queue<Data> queue;
        current->data.is_malware ? std::cout << "S" : std::cout << "N";
        std::cout << "-" << current->data.id << " ";
        while (current != nullptr)
        {
            if (current->left != nullptr)
                queue.push(current->left->data);
            if (current->right != nullptr)
                queue.push(current->right->data);

            if (not queue.empty())
            {
                current = find_node(root, queue.front());
                current->data.is_malware ? std::cout << "S" : std::cout << "N";
                std::cout << "-" << current->data.id << " ";
                queue.pop();
            } else current = nullptr;
        }
        std::cout << std::endl;
    }

    static void print_data(const Data data)
    {
        data.is_malware ? std::cout << "S" : std::cout << "N";
        std::cout << "-" << data.id << " ";
    }


};


int main()
{
    Tree tree;


    return 0;
}
