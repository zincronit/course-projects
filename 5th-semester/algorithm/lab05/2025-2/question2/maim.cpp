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


    TreeNode* find_malware(TreeNode* current)
    {
        // esta el la manera que se me hizo mas facil
        //
        // std::queue<TreeNode *> queue;
        // print_data(current->data);
        // if (current->data.is_malware) return current;
        // while (current != nullptr)
        // {
        //
        //     if (current->left != nullptr)
        //     {
        //         print_data(current->left->data);
        //         queue.push(current->left);
        //         if (current->left->data.is_malware) return current->left;
        //     }
        //
        //     if (current->right != nullptr)
        //     {
        //         print_data(current->right->data);
        //         queue.push(current->right);
        //         if (current->right->data.is_malware) return current->right;
        //     }
        //
        //     if (not queue.empty())
        //     {
        //         current = queue.front();
        //         queue.pop();
        //     }
        // }
        // return nullptr;

        // este es el metodo que pide el problema


        std::stack<TreeNode *> stack;
        print_data(current->data);
        if (current->data.is_malware) return current;
        while (current != nullptr)
        {
            if (current->right != nullptr) stack.push(current->right);
            if (current->left != nullptr)
            {
                print_data(current->left->data);
                if (current->left->data.is_malware) return current->left;
                current = current->left;
            } else
            {
                current = stack.top();
                stack.pop();
                print_data(current->data);
            }
        }
        return nullptr;
    }

    static void print_data(const Data data)
    {
        data.is_malware ? std::cout << "S" : std::cout << "N";
        std::cout << "-" << data.id << " ";
    }

    void destroy_nodes(TreeNode*& current)
    {
        if (root == nullptr) return;
        std::stack<TreeNode *> transversal_stack;
        std::stack<TreeNode *> delete_stack;
        transversal_stack.push(current);
        while (not transversal_stack.empty())
        {
            TreeNode* auxiliar = transversal_stack.top();
            transversal_stack.pop();
            delete_stack.push(auxiliar);
            if (auxiliar->left != nullptr) transversal_stack.push(auxiliar->left);
            if (auxiliar->right != nullptr) transversal_stack.push(auxiliar->right);
        }

        while (not delete_stack.empty())
        {
            print_data(delete_stack.top()->data);
            delete delete_stack.top();
            delete_stack.pop();
        }
        current = nullptr;
    };

    void delete_malware()
    {
        TreeNode* current = find_malware(root);
        std::cout << std::endl;
        destroy_nodes(current->left);
        destroy_nodes(current->right);
    }
};


int main()
{
    Tree red;
    red.insert({100, false});
    red.insert({50, false});
    red.insert({25, false});
    red.insert({75, false});
    red.insert({150, false});
    red.insert({125, true});
    red.insert({110, false});
    red.insert({105, false});
    red.insert({115, false});
    red.insert({140, false});
    red.insert({130, false});
    red.insert({175, false});
    red.insert({200, false});


    red.delete_malware();

    return 0;
}

