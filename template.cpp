#include "template.h"

#include <stdexcept>

template <class T>
queue<T>::queue(int size) : arr(nullptr), capacity(size), front(0), rear(-1), count(0) {
    if (size <= 0) throw std::invalid_argument("Queue capacity must be positive");
    arr = new T[size];
}

template <class T>
queue<T>::~queue() { delete[] arr; }

template <class T>
void queue<T>::pop() {
    if (isEmpty()) throw std::underflow_error("Cannot pop empty queue");
    front = (front + 1) % capacity;
    --count;
}

template <class T>
void queue<T>::push(T item) {
    if (isFull()) throw std::overflow_error("Cannot push full queue");
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    ++count;
}

template <class T>
T queue<T>::peek() {
    if (isEmpty()) throw std::underflow_error("Cannot peek empty queue");
    return arr[front];
}

template <class T>
int queue<T>::size() { return count; }

template <class T>
bool queue<T>::isEmpty() { return count == 0; }

template <class T>
bool queue<T>::isFull() { return count == capacity; }
