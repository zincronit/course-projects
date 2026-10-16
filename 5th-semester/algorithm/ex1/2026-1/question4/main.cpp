//
// Created by zincronit on 10/15/26.
//

#include <cstring>
#include <iostream>

struct Node
{
    char id;
    struct Node* next;
};

struct Stack
{
public:
    Stack()
    {
        head = nullptr;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    void push(char id)
    {
        struct Node* new_node = new Node;
        new_node->id = id;
        new_node->next = nullptr;
        if (is_empty())
        {
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }

    char top()
    {
        if (is_empty())
        {
            return '-';
        }
        return head->id;
    }

    void pop()
    {
        if (is_empty()) return;
        struct Node* temp = head;
        head = head->next;
        delete temp;
    }

private:
    struct Node* head;
};


bool is_valid_input(struct Stack& stack, const char* input)
{
    int length = std::strlen(input);
    // if (input[0] >= 'a' && input[0] <= 'z') return false;
    for (int i = 0; i < length; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
            stack.push(input[i]);
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            if (stack.is_empty() or stack.top() != static_cast<char>(input[i] - 32))
                return false;
            stack.pop();
        }
    }
    return stack.is_empty();
}


int main()
{
    // std::cout << static_cast<char>('a' - 32) << std::endl;
    struct Stack stack;
    const char* input = "ABbaCcAa";
    is_valid_input(stack, input) ? std::cout << "secuencia valida" : std::cout << "secuencia invalida";
    return 0;
}
