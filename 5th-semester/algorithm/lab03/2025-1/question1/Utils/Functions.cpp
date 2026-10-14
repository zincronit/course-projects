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

void push(struct Stack& stack, const struct Position& position)
{
    Node* newNode = new Node{position, stack.top};
    stack.top = newNode;
}

struct Position& pop(Stack& stack)
{
    if (isStackEmpty(stack))
    {
        struct Position pos{-1, -1};
        return pos;
    }
    Node* temp = stack.top;
    struct Position temp_position = temp->position;
    stack.top = stack.top->next;
    delete temp;
    return temp_position;
}

struct Position& top(const Stack& stack)
{
    if (isStackEmpty(stack))
    {
        struct Position pos{-1, -1};
        return pos;
    }
    return stack.top->position;
}

void finding_way(int tablero[][M], struct Position& position)
{
    struct Stack stack;
    initStack(stack);
    push(stack, {0, 0});
    tablero[0][0] = 1;
    while (not isStackEmpty(stack))
    {
        struct Position pos = top(stack);
        if (pos.row == N - 1 and pos.column == M - 1) break;
        if (pos.column + 1 < M and tablero[pos.row][pos.column + 1] == 0)
        {
            push(stack, {pos.row, pos.column + 1});
            tablero[pos.row][pos.column + 1] = 1;
        } else if (pos.row + 1 < N and tablero[pos.row + 1][pos.column] == 0)
        {
            push(stack, {pos.row + 1, pos.column});
            tablero[pos.row + 1][pos.column] = 1;
        } else
        {
            tablero[pos.row][pos.column] = 2;
            pop(stack);
        }
    }
}
