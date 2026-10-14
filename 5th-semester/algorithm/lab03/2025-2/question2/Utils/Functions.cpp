//
// Created by zincronit on 10/9/26.
//

#include "Functions.hpp"

void initStack(Stack& stack)
{
    stack.top = nullptr;
}

bool isStackEmpty(const Stack& stack)
{
    return stack.top == nullptr;
}

void push(Stack& stack, int value)
{
    Node* newNode = new Node{value, stack.top};
    stack.top = newNode;
}

int pop(Stack& stack)
{
    if (isStackEmpty(stack))
    {
        return -1;
    }
    Node* temp = stack.top;
    int value = temp->data;
    stack.top = stack.top->next;
    delete temp;
    return value;
}

int top(const Stack& stack)
{
    if (isStackEmpty(stack))
    {
        return -1;
    }
    return stack.top->data;
}

void initQueue(Queue& queue)
{
    queue.front = nullptr;
    queue.rear = nullptr;
}

bool isQueueEmpty(const Queue& queue)
{
    return queue.front == nullptr;
}

void enqueue(Queue& queue, int value)
{
    Node* newNode = new Node{value, nullptr};
    if (isQueueEmpty(queue))
    {
        queue.front = newNode;
        queue.rear = newNode;
    } else
    {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

int dequeue(Queue& queue)
{
    if (isQueueEmpty(queue))
    {
        return -1;
    }
    Node* temp = queue.front;
    int value = temp->data;
    queue.front = queue.front->next;
    if (queue.front == nullptr)
    {
        queue.rear = nullptr;
    }
    delete temp;
    return value;
}

int front(const Queue& queue)
{
    if (isQueueEmpty(queue))
    {
        return -1;
    }
    return queue.front->data;
}

bool has_insert_sort(struct Queue& queue1, struct Queue& queue2)
{
    struct Stack stack;
    initStack(stack);
    int current_element = 1;
    while (not isQueueEmpty(queue1))
    {
        if (current_element == front(queue1))
        {
            enqueue(queue2, dequeue(queue1));
            current_element++;
        } else if (not isStackEmpty(stack) and top(stack) == current_element)
        {
            enqueue(queue2, pop(stack));
            current_element++;
        } else
        {
            push(stack, dequeue(queue1));
        }
    }
    while (not isStackEmpty(stack))
    {
        if (top(stack) == current_element)
        {
            enqueue(queue2, pop(stack));
            current_element++;
        } else
        {
            return false;
        }
    }
    return true;
}
