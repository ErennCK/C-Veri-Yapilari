#ifndef QUEUE_H
#define QUEUE_H

#include <deque>

class Queue {
public:
    void enqueue(int value);
    void dequeue();
    void clear();
    void display() const;
    int size() const;
    void queueMenu();

private:
    std::deque<int> queue;
};

#endif // QUEUE_H