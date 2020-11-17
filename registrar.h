/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include <iostream>
#include <fstream>
#include "queue.cpp"
#include "student.h"
#include "window.h"

using namespace std;

// class for registrar office that can setup the data for simulation by reading
// from the file, simulation, and print the metrics
class RegistrarOffice {
private:
    Window *windows;
    Queue<Student> *waitQueue;
    Queue<Student> *processedQueue;
    int totalWindows;

    double computeMean(int *times, int size);
    double computeMedian(int *times, int size);
    double countMark(int *times, int size, int mark);
    void sortWindows();
    void printStudentMetrics();
    void printWindowMetrics();

public:
    RegistrarOffice();
    ~RegistrarOffice();
    void setupFromFile(ifstream &readStream);
    void simulate();
    void printMetrics();
};
