#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack {
public:
    void push(int value);
    void pop();
    void clear();
    void display() const;
    int size() const;
    void stackMenu();

private:
    std::vector<int> stack;
};

#endif // STACK_H