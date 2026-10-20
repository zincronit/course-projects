//
// RESOLUCION DE GEMINI PARA EL PORBLEMA 2 b DEL EX1 2024-2
//
#include <iostream>
struct Customer {
    int id;
    bool isVip;
    int arrivalTime;
    Customer* next;
};

struct PriorityQueue {
    Customer* head;
};

void queueInit(PriorityQueue& q) {
    q.head = nullptr;
}

bool queueIsEmpty(const PriorityQueue& q) {
    return q.head == nullptr;
}

// Inserción ordenada: los VIP van antes que los no VIP
void queuePush(PriorityQueue& q,
               int id,
               bool isVip,
               int arrivalTime) {
    Customer* newCustomer = new Customer{id, isVip, arrivalTime, nullptr};

    if (q.head == nullptr) {
        q.head = newCustomer;
        return;
    }

    // Si el nuevo es VIP y el primero en cola no lo es, se inserta al inicio
    if (isVip && !q.head->isVip) {
        newCustomer->next = q.head;
        q.head = newCustomer;
        return;
    }

    Customer* curr = q.head;
    // Avanzar hasta el ultimo nodo que coincida con la prioridad (VIP antes de no VIP)
    while (curr->next != nullptr && (curr->next->isVip || !isVip)) {
        curr = curr->next;
    }

    newCustomer->next = curr->next;
    curr->next = newCustomer;
}

Customer queuePop(PriorityQueue& q) {
    Customer temp = *q.head;
    Customer* toDelete = q.head;
    q.head = q.head->next;
    delete toDelete;
    return temp;
}

// Revisa si el VIP que está en el frente de la cola sobrepasó los 30s de espera
void checkVipTimeout(PriorityQueue& q,
                     int currentTime,
                     int& vipsTimedOut) {
    while (q.head != nullptr && q.head->isVip) {
        int waitTime = currentTime - q.head->arrivalTime;
        if (waitTime > 30) {
            Customer dropped = queuePop(q);
            vipsTimedOut++;
        } else {
            break;
        }
    }
}

void simulateBank() {
    PriorityQueue queue;
    queueInit(queue);

    int totalCustomers = 6;
    int nextCustomerIndex = 1;
    int currentTime = 0;
    int cashierFreeTime = 0;

    int vipsServed = 0;
    int vipsTimedOut = 0;

    while (nextCustomerIndex <= totalCustomers || !queueIsEmpty(queue)) {
        // Avanzar el tiempo según la llegada del siguiente cliente o liberación del cajero
        if (queueIsEmpty(queue) && currentTime < nextCustomerIndex * 15) {
            currentTime = nextCustomerIndex * 15;
        }

        // Registrar las llegadas de clientes hasta el tiempo actual
        while (nextCustomerIndex <= totalCustomers && (nextCustomerIndex * 15) <= currentTime) {
            int arrival = nextCustomerIndex * 15;
            bool isVip = (nextCustomerIndex % 2 == 0); // Clientes 2, 4 y 6 son VIP
            queuePush(queue, nextCustomerIndex, isVip, arrival);
            nextCustomerIndex++;
        }

        // Expulsar clientes VIP de la frente de la cola si esperaron más de 30s
        checkVipTimeout(queue, currentTime, vipsTimedOut);

        // Atender al siguiente cliente si el cajero se libera
        if (!queueIsEmpty(queue) && currentTime >= cashierFreeTime) {
            Customer current = queuePop(queue);

            int waitTime = currentTime - current.arrivalTime;

            // Verificar la condición de abandono VIP al momento exacto de ser llamado
            if (current.isVip && waitTime > 30) {
                vipsTimedOut++;
            } else {
                if (current.isVip) {
                    vipsServed++;
                }
                cashierFreeTime = currentTime + 20; // 20s de atención
            }
        }

        // Avanzar el reloj
        if (currentTime < cashierFreeTime) {
            currentTime = cashierFreeTime;
        } else {
            currentTime += 15;
        }
    }

    std::cout << "RESULTADOS DE LA SIMULACIÓN DEL DESPACHO DE ENTRADAS" << std::endl;
    std::cout << "Clientes VIP atendidos: " << vipsServed << std::endl;
    std::cout << "Clientes VIP no atendidos: " << vipsTimedOut << std::endl;
}

int main() {
    simulateBank();
    return 0;
}