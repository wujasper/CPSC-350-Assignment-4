/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include <iostream>

using namespace std;

// window class contains idle time and longest idle time, also contains
// the process time needed for the student in service
class Window {
private:
    int processTime;
    int idleTime;

public:
    Window();
    ~Window() {};
    void setProcessTime(int time);
    void updateTime();
    int getProcessTime();
    int getIdleTime();
    bool operator>(const Window &a);
    bool operator<(const Window &a);
};
