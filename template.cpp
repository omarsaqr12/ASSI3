#include "template.h"
#include <iostream>
using namespace std;
template <class T>
queue<T>::queue(int size)
{
    arr = new T[size];// we create a dynammuc array of size size
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
template <class T>
void queue<T>::pop()
{
    if (isEmpty())// we check whther we can pop or not
    {
        cout << "Underflow"<<"\n";
    }
    else
 	{
    front = (front + 1) % capacity;
    count--;
	}
}
template <class T>
void queue<T>::push(T item)
{
    if (isFull())// we check whether we can push or not
    {
        cout << "Overflow"<<"\n";
    }
 	else
 	{
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
	}
}
template <class T>
T queue<T>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
    }
    else
    	return arr[front];
}
template <class T>
int queue<T>::size() {
    return count;
}
template <class T>
bool queue<T>::isEmpty() {
    return (size() == 0);
}
template <class T>
bool queue<T>::isFull() {
    return (size() == capacity);
}
