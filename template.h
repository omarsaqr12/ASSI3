#ifndef ASSI3_TEMPLATE_H
#define ASSI3_TEMPLATE_H

template <class T>
class queue {
    T* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    explicit queue(int size = 15);
    ~queue();
    queue(const queue&) = delete;
    queue& operator=(const queue&) = delete;
    void pop();
    void push(T);
    T peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#endif
