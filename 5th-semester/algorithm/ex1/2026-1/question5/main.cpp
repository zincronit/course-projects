//
// Created by zincronit on 10/15/26.
//

#include <iostream>

struct Node
{
    int data;
    Node* next;
};

struct Queue
{
public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    void enqueue(int data)
    {
        struct Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        if (is_empty())
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }

    int top()
    {
        if (is_empty())
        {
            return -1;
        }
        return head->data;
    }

    void dequeue()
    {
        struct Node* temp = head;
        head = head->next;
        delete temp;
    }

private:
    Node* head;
    Node* tail;
};


void print_binaries(int number)
{
    struct Queue queue;
    queue.enqueue(1);
    bool flag = false;
    for (int i = 0; i < number; i++)
    {
        int binary = queue.top();
        queue.dequeue();
        queue.enqueue(binary * 10 + 0);
        queue.enqueue(binary * 10 + 1);
        if (flag) std::cout << ", ";
        std::cout << binary ;
        flag = true;
    }
}

int main()
{
    int number = 10;
    print_binaries(number);
    return 0;
}
