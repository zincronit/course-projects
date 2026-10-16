//
// Created by zincronit on 10/15/26.
//

#include <iostream>

struct Data
{
    int id;
    bool is_active;
};

struct Node
{
    struct Data data;
    struct Node* next;
    struct Node* skip_next;
};

struct List
{
public:
    List()
    {
        head = nullptr;
        size = 0;
    }

    bool is_empty() const
    {
        return head == nullptr;
    }

    void insert_back(const struct Data data)
    {
        struct Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        new_node->skip_next = nullptr;
        if (is_empty())
        {
            head = new_node;
            new_node->next = head;
        } else
        {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = new_node;
            new_node->next = head;
        }
        size++;
    }

    void update_skip_next()
    {
        if (is_empty()) return;
        Node* current = head;
        do
        {
            current->skip_next = current->next->next;
            current = current->next;
        } while (current != head);
    }

    void desactivate_node(int id)
    {
        struct Node* current = head;
        if (is_empty()) return;
        do
        {
            if (current->data.id == id)
            {
                current->data.is_active = false;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void auto_healing()
    {
        Node* new_head = head;
        do
        {
            if (new_head->data.is_active) break;
            new_head = new_head->next;
        } while (new_head != head);
        if (not new_head->data.is_active)
        {
            Node* current = head;
            Node* start = head;
            do
            {
                Node* dead = current;
                current = current->next;
                delete dead;
            } while (current != start);
            head = nullptr;
            size = 0;
            return;
        }
        head = new_head;

        Node* current = head;
        int active_count = 0;
        do
        {
            while (not current->next->data.is_active)
            {
                struct Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            active_count++;
            current = current->next;
        } while (current != head);

        size = active_count;
        update_skip_next();
    }

    void print()
    {
        if (is_empty())
        {
            std::cout << "Anillo vacio" << std::endl;
            return;
        }

        std::cout << "Anillo (" << size << " nodos):" << std::endl;
        Node* current = head;
        do
        {
            std::cout << "Nodo " << current->data.id << " ["
                      << (current->data.is_active ? "ACTIVO" : "CAIDO ") << "] ";
            if (current->next)
                std::cout << "siguiente=" << current->next->data.id << " ";
            if (current->skip_next)
                std::cout << "skip_next=" << current->skip_next->data.id;
            std::cout << std::endl;

            current = current->next;
        } while (current != head);
    }

private:
    struct Node* head;
    int size;
};


int main()
{
    int N = 5;
    struct List ring;

    // a. Crear 5 nodos con id múltiplo de 10
    for (int i = 1; i <= N; i++)
    {
        ring.insert_back({i * 10, true});
    }
    ring.update_skip_next();

    // b. Imprimir estado inicial
    std::cout << "=== Estado inicial ===" << std::endl;
    ring.print();
    std::cout << std::endl;

    // c. Desactivar nodos 20 y 30
    std::cout << ">>> Nodo 20 cae <<<" << std::endl;
    ring.desactivate_node(20);
    std::cout << ">>> Nodo 30 cae <<<" << std::endl;
    ring.desactivate_node(30);
    std::cout << std::endl;

    // d. Imprimir estado antes de auto_healing
    std::cout << "=== Estado antes de auto_healing ===" << std::endl;
    ring.print();
    std::cout << std::endl;

    // e. Aplicar auto_healing e imprimir resultado final
    ring.auto_healing();
    std::cout << "=== Estado despues de auto_healing ===" << std::endl;
    ring.print();
}
