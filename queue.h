/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include "dblist.cpp"

template <class T>
class Queue: public virtual DoublyList<T> {

public:
     void push(T data);
     T pop();
     T peek();
};
