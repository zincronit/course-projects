//
// Created by zincronit on 26/11/26.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

struct Node
{
    int data;
    Node *left, *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {};
};

struct Tree
{
    Node* root;
    int max_value;
    Tree() : root(nullptr), max_value(-1) {};

    void insert(int value)
    {
        insert_node(root, value, max_value);
    }

    void insert_node(Node*& node, int value, int& max_data)
    {
        if (node == nullptr)
        {
            node = new Node(value);
            max_data = std::max(max_data, value);
            return;
        }
        if (node->data == value) value += max_data;
        if (node->data > value) insert_node(node->left, value, max_data);
        if (node->data < value) insert_node(node->right, value, max_data);
    }

    Node* vector_to_bst(std::vector<Node *>& array, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        array[mid]->left = vector_to_bst(array, left, mid - 1);
        array[mid]->right = vector_to_bst(array, mid + 1, right);
        return array[mid];
    }

    void balance()
    {
        if (root == nullptr) return;
        std::vector<Node *> array;
        store_nodes(root, array);
        root = vector_to_bst(array, 0, array.size() - 1);
    }

    void store_nodes(Node* node, std::vector<Node *>& array)
    {
        if (node == nullptr) return;
        store_nodes(node->left, array);
        array.push_back(node);
        store_nodes(node->right, array);
    }

    bool is_bst() const
    {
        if (root == nullptr) return true;
        auto validate = [](this auto&& self, const Node* node, int minor, int major)-> bool
        {
            if (node == nullptr) return true;
            if (node->data <= minor or node->data >= major) return false;
            return self(node->left, minor, node->data) and self(node->right, node->data, major);
        };
        return validate(root, INT_MIN, INT_MAX);
    }
};

void sum_trees(Tree& a, Tree& b)
{
    if (b.root == nullptr) return;
    std::queue<Node *> queue1, queue2;
    auto sync_nodes = [&](Node*& target, Node*& source)
    {
        if (source == nullptr) return;
        if (target == nullptr) target = new Node(0);
        target->data += source->data;
        queue1.push(target);
        queue2.push(source);
    };
    sync_nodes(a.root, b.root);
    while (not queue1.empty() and not queue2.empty())
    {
        Node* temp1 = queue1.front();
        Node* temp2 = queue2.front();
        queue1.pop();
        queue2.pop();
        if (temp2->left != nullptr)
            sync_nodes(temp1->left, temp2->left);
        if (temp2->right != nullptr)
            sync_nodes(temp1->right, temp2->right);
    }
}

void sum_trees_recursive(Tree& a,const Tree& b)
{
    if (b.root == nullptr) return;
    auto sync_nodes = [](this auto&& self, Node*& node1, Node* node2)-> void
    {
        if (node2 == nullptr) return;
        if (node1 == nullptr) node1 = new Node(0);
        node1->data += node2->data;
        self(node1->left, node2->left);
        self(node1->right, node2->right);
    };
    sync_nodes(a.root, b.root);
}

int main() {}
