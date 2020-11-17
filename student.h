/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include <iostream>

using namespace std;

// student class contains time needed for the student and wait time before
// the student is serviced at the window
class Student {
private:
    int tick;
    int processTime;
    int waitTime;

public:
    Student();
    ~Student() {};
    Student(int tick, int processTime);
    void setWaitTime(int waitTime);
    int getProcessTime();
    int getTick();
    int getWaitTime();
    bool operator==(const Student &a);
    bool operator!=(const Student &a);
    bool operator>(const Student &a);
    bool operator<(const Student &a);
};
