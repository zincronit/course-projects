//
// Created by zincronit on 10/15/26.
//

#include <iostream>

struct Data
{
    int code;
    int priority;
};

struct Node
{
    struct Data data;
    struct Node* next;
};

struct Queue
{
public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        priority = nullptr;
    }

    ~Queue()
    {
        while (!is_empty())
        {
            dequeue();
        }
    }

    bool is_empty() const
    {
        return front == nullptr;
    }

    void enqueue(const struct Data d)
    {
        struct Node* new_node = new Node;
        new_node->data = d;
        new_node->next = nullptr;
        if (is_empty())
        {
            front = new_node;
            rear = new_node;
            if (d.priority == 1) priority = new_node;
            return;
        }
        if (d.priority == 1)
        {
            if (priority == nullptr)
            {
                new_node->next = front;
                front = new_node;
                priority = new_node;
                return;
            }
            new_node->next = priority->next;
            priority->next = new_node;
            priority = new_node;
            if (priority->next == nullptr) rear = priority;
        } else
        {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue()
    {
        if (is_empty()) return;
        if (front == priority) priority = nullptr;
        struct Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    struct Data top() const
    {
        if (is_empty()) return {-1, -1};
        return front->data;
    }

    void attend(int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (is_empty()) return;
            struct Data data = top();
            std::cout << "Atendido " << data.code << " (P" << data.priority << ")" << std::endl;
            dequeue();
        }
    }

    void print() const
    {
        std::cout << "Estado: [P1:";
        struct Node* curr = front;

        bool first_p1 = true;
        while (curr != nullptr && curr->data.priority == 1)
        {
            if (!first_p1)
            {
                std::cout << ", ";
            }
            else
            {
                std::cout << " ";
            }
            std::cout << curr->data.code;
            first_p1 = false;
            curr = curr->next;
        }

        std::cout << "] [P2:";
        bool first_p2 = true;
        while (curr != nullptr)
        {
            if (!first_p2)
            {
                std::cout << ", ";
            }
            else
            {
                std::cout << " ";
            }
            std::cout << curr->data.code;
            first_p2 = false;
            curr = curr->next;
        }
        std::cout << "]" << std::endl;
    }

private:
    struct Node* front;
    struct Node* rear;
    struct Node* priority;
};

int main()
{

    // el algoritmo ya esta realizado, solo falta crear los archivos de texto para procesar las llamadas, pero eso
    // lo haces tu psss
    return 0;
}
