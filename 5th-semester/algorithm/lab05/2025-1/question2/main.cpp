//
// Created by zincronit on 11/26/26.
//

#include <stack>

struct TreeNode
{
    int id;
    TreeNode *left, *right;
    TreeNode(int value) : id(value), right(nullptr), left(nullptr) {};
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
        if (node->id > value) insert_node(node->left, value);
        else if (node->id < value) insert_node(node->right, value);
    }

    void remove_single_children()
    {
        delete_leftovers(root);
    }

    bool is_leaf(TreeNode* node)
    {
        return node != nullptr and node->left == nullptr and node->right == nullptr;
    }

    void delete_leftovers(TreeNode* node)
    {
        if (node == nullptr) return;
        std::stack<TreeNode *> stack;
        TreeNode* current = node;
        TreeNode* last_visited = nullptr;
        while (not stack.empty() or current != nullptr)
        {
            if (current != nullptr)
            {
                stack.push(current);
                current = current->left;
            } else
            {
                TreeNode* aux = stack.top();
                if (aux->right != nullptr and last_visited != aux->right) current = aux->right;
                else
                {
                    // usamos disyuncion fuerte (XOR)
                    if ((aux->right == nullptr) != (aux->left == nullptr))
                    {
                        TreeNode*& only_child = aux->left == nullptr ? aux->right : aux->left;
                        if (is_leaf(only_child))
                        {
                            delete only_child;
                            only_child = nullptr;
                        }
                    }
                    last_visited = aux;
                    stack.pop();
                }
            }
        }
    }
};

int main()
{
    Tree tree;
    int codes[] = {100, 50, 150, 25, 75, 125, 175, 30, 200, 28};
    for (const int code : codes) tree.insert(code);
    tree.remove_single_children();
    return 0;
}
