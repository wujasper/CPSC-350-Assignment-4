/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include "doublylist.cpp"

// queue class using doubly linked list
template <class T>
class Queue {
private:
    DoublyList<T> *list;

public:
    Queue ();
    ~Queue();
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    void sort();
    unsigned int getSize();
};

// default constructor
template <class T>
Queue<T>::Queue() {
    list = new DoublyList<T>();
}
// default destructor
template <class T>
Queue<T>::~Queue() {
    delete list;
}
// push to the queue using list->append
template <class T>
void Queue<T>::push(T data) {
    list->append(data);
}
// peek the queue using list->peekHead
template <class T>
T Queue<T>::peek() {
    return list->peekHead();
}
// pop the queue using list->remove
template <class T>
T Queue<T>::pop() {

    T data = list->peekHead();
    list->remove(data);
    return data;
}
// sort the queue using list->sort
template <class T>
void Queue<T>::sort() {
    return list->sort();
}
// check if queue is empty using list->isEmpty
template <class T>
bool Queue<T>::isEmpty() {
    return list->isEmpty();
}
// get queue size using list->getSize
template <class T>
unsigned int Queue<T>::getSize() {
    return list->getSize();
}
