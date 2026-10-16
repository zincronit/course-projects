//
// Created by zincronit on 10/14/26.
//

#include <iostream>
#define MAX_COLS 100

struct Stack
{
public:
    Stack()
    {
        top_index = -1;
    }

    void push(int val)
    {
        top_index++;
        data[top_index] = val;
    }

    void pop()
    {
        if (top_index >= 0)
        {
            top_index--;
        }
    }

    int top()
    {
        return data[top_index];
    }

    bool is_empty()
    {
        return top_index == -1;
    }

    void clear()
    {
        top_index = -1;
    }

private:
    int data[MAX_COLS];
    int top_index;
};

int main()
{
    Stack stack;

    return 0;
}
