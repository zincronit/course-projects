//
// Created by zincronit on 11/27/26.
//
#include <print>
#include <algorithm>

struct Node
{
    int data;
    int height;
    int size;
    Node *left, *right;
    Node(int data) : data(data), height(1), size(1), left(nullptr), right(nullptr) {}

    static int get_height(Node* node)
    {
        if (node == nullptr) return 0;
        return node->height;
    }

    void update()
    {
        const int left_height = get_height(left);
        const int right_height = get_height(right);
        height = std::max(left_height, right_height) + 1;

        const int left_size = get_size(left);
        const int right_size = get_size(right);
        size = left_size + right_size + 1;
    }

    int get_balance_factor() const
    {
        return get_height(left) - get_height(right);
    }

    static int get_size(Node* node)
    {
        if (node == nullptr) return 0;
        return node->size;
    }
};

struct Tree
{
    Node* root;
    Tree() : root(nullptr) {}

    void rotate_right(Node*& z)
    {
        Node* y = z->left;
        z->left = y->right;
        y->right = z;
        z->update();
        y->update();
        z = y;
    }

    void rotate_left(Node*& z)
    {
        Node* y = z->right;
        z->right = y->left;
        y->left = z;
        z->update();
        y->update();
        z = y;
    }

    void insert(int data)
    {
        auto insert_node = [this, data](this auto&& self, Node*& node) -> void
        {
            if (node == nullptr)
            {
                node = new Node(data);
                return;
            }
            if (node->data > data) self(node->left);
            else if (node->data < data) self(node->right);
            else return;

            node->update();
            int bf = node->get_balance_factor();

            if (bf > 1)
            {
                if (node->left->get_balance_factor() < 0)
                    rotate_left(node->left);
                rotate_right(node);
            }
            else if (bf < -1)
            {
                if (node->right->get_balance_factor() > 0)
                    rotate_right(node->right);
                rotate_left(node);
            }
        };
        insert_node(root);
    }

    void delete_node(int value)
    {
        if (root == nullptr) return;
        auto delete_and_update = [this](this auto&& self, Node*& node, int value)-> void
        {
            if (node == nullptr) return;
            if (node->data > value) self(node->left, value);
            else if (node->data < value) self(node->right, value);
            else
            {
                // hace algo
                if (node->left == nullptr or node->right == nullptr)
                {
                    Node* temp = node;
                    node = node->left != nullptr ? node->left : node->right;
                    delete temp;
                }
                else
                {
                    Node* aux = node->right;
                    while (aux->left != nullptr) aux = aux->left;
                    node->data = aux->data;
                    self(node->right, node->data);
                }
            }
            if (node == nullptr) return;
            node->update();
            int bf = node->get_balance_factor();
            if (bf > 1)
            {
                if (node->left->get_balance_factor() < 0)
                    rotate_left(node->left);
                rotate_right(node);
            }
            else if (bf < -1)
            {
                if (node->right->get_balance_factor() > 0)
                    rotate_right(node->right);
                rotate_left(node);
            }
        };
        delete_and_update(root, value);
    }

    [[nodiscard]] int kth_smallest(int k) const
    {
        if (root == nullptr or Node::get_size(root) < k or k < 1) return -1;
        auto find_kth = [](this auto&& self, const Node* node, int k)-> int
        {
            int left_size = Node::get_size(node->left);
            if (k == left_size + 1) return node->data;
            if (k <= left_size) return self(node->left, k);
            return self(node->right, k - (left_size + 1));
        };
        return find_kth(root, k);
    }

    [[nodiscard]] int get_median() const
    {
        if (root == nullptr) return -1;
        if (Node::get_size(root) % 2 != 0)
        {
            int n = (Node::get_size(root) + 1) / 2;
            return kth_smallest(n);
        }
        else
        {
            int n = Node::get_size(root) / 2;
            return (kth_smallest(n) + kth_smallest(n + 1)) / 2;
        }
    }
};

int main()
{
    Tree tree;
    for (int x: {10, 20, 30, 40, 50}) tree.insert(x);
    std::print("tercer menor: {}\n", tree.kth_smallest(3));
    // std::println("tercer menor: {}", tree.kth_smallest(3));

    return 0;
}
