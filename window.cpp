/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include "window.h"

// default constructor to initialize variables
Window::Window() {
    processTime = 0;
    idleTime = 0;
}
// set process time for the student in service
void Window::setProcessTime(int time) {
    processTime = time;
}
// time update for the student process time and idle time
// if servicing the student then update the process time otherwise
// update the idle time
void Window::updateTime() {
    if (processTime > 0) {
        processTime--;
    } else {
        idleTime++;
    }
}
// get current process time for the student
int Window::getProcessTime() {
    return processTime;
}
// get the longest window idle time
int Window::getIdleTime() {
    return idleTime;
}
// overload operator for sorting
bool Window::operator>(const Window &a) {
    return (idleTime > a.idleTime);
}
// overload operator for sorting
bool Window::operator<(const Window &a) {
    return (idleTime < a.idleTime);
}
