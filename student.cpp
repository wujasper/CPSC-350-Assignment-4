/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include "student.h"

// default constructor to set default variables
Student::Student() {
    tick = 0;
    processTime = 0;
    waitTime = 0;
}
// constructor to initialize the student's tick and time needed for the student
Student::Student(int tick, int processTime) {
    this->tick = tick;
    this->processTime = processTime;
    waitTime = 0;
}
// set the student wait time
void Student::setWaitTime(int waitTime) {
    this->waitTime = waitTime;
}
// get the time needed for the the student
int Student::getProcessTime() {
    return processTime;
}
// get the time tick
int Student::getTick() {
    return tick;
}
// return student wait time
int Student::getWaitTime() {
    return waitTime;
}
// overload operator for the doubly linked list
bool Student::operator==(const Student &a) {
    return (a.tick == tick && a.processTime == processTime && a.waitTime == waitTime);
}
// overload operator for the doubly linked list
bool Student::operator!=(const Student &a) {
    return (a.tick != tick || a.processTime != processTime || a.waitTime != waitTime);
}
// overload operator for the doubly linked list
bool Student::operator>(const Student &a) {
    return (waitTime > a.waitTime);
}
// overload operator for the doubly linked list
bool Student::operator<(const Student &a) {
    return (waitTime < a.waitTime);
}
