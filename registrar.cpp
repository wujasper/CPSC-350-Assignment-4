/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include "registrar.h"

// default constructor to initialize variables and pointers for array and queues
RegistrarOffice::RegistrarOffice() {
    totalWindows = 0;
    waitQueue = new Queue<Student>;
    processedQueue = new Queue<Student>;
}
// destructor to delete the queues and array
RegistrarOffice::~RegistrarOffice() {
    if (windows != NULL) {
        delete [] windows;
    }

    delete waitQueue;
    delete processedQueue;
}
// setup the simulation data from the file
void RegistrarOffice::setupFromFile(ifstream &readStream) {
    string line;
    int tick;
    int numOfStudents;
    int lineType = 0;

    // read from the file to initialize windows and push the tick and student
    // information into the student wait queue
    while (getline(readStream, line)) {
        switch (lineType) {
            // process the window information
            case 0:
                totalWindows = stoi(line);
                windows = new Window[totalWindows];
                lineType++;
                break;
            // get the time tick
            case 1:
                tick = stoi(line);
                lineType++;
                break;
            // get number of students for this time tick
            case 2:
                numOfStudents = stoi(line);
                lineType++;
                break;
            // get student information and push into student wait queue
            case 3:
                Student *student = new Student(tick, stoi(line));
                waitQueue->push(*student);
                numOfStudents--;
                if (numOfStudents == 0) {
                   lineType = 1;
                }
        }
    }
}
// simulation
void RegistrarOffice::simulate() {
    int simTick = 0;
    bool windowsAllIdle = false;

    // loop till all students are serviced and windows are all idle
    while (!waitQueue->isEmpty() || !windowsAllIdle) {
        // find the idle window and assign the waiting student to service
        for (int i = 0; i < totalWindows; ++i) {
            // check if window is idle and if there is student waiting
            if (windows[i].getProcessTime() == 0 && !waitQueue->isEmpty()) {
                // only service the student if the simulation time tick
                // passes the student's arrival time tick
                if (waitQueue->peek().getTick() <= simTick) {
                    // pop the student from the waiting queue
                    Student student = waitQueue->pop();
                    // assign the student to the first idle window found
                    windows[i].setProcessTime(student.getProcessTime());
                    // update the student wait time by the difference of
                    // simulation time tick and student's arrival time tick
                    student.setWaitTime(simTick - student.getTick());
                    // push the student into student processed queue
                    processedQueue->push(student);
                }
            }
            // update window process and idle time
            windows[i].updateTime();
        }
        // check if windows are all idle. this is to continue to count
        // the window idle time if other windows are still busy
        windowsAllIdle = true;
        for (int i = 0; i < totalWindows; ++i) {
            windowsAllIdle &= (windows[i].getProcessTime() == 0);
        }
        // advance simulation time tick
        simTick++;
    }
}
// insertion sort for the windows array
void RegistrarOffice::sortWindows() {
    Window temp;

    for (int i = 0; i < totalWindows; ++i) {
        for (int j = i + 1; j < totalWindows; ++j) {
            if (windows[i].getIdleTime() > windows[j].getIdleTime()) {
                temp = windows[i];
                windows[i] = windows[j];
                windows[j] = temp;
            }
        }
    }
}
// print metrics
void RegistrarOffice::printMetrics() {
    printStudentMetrics();
    printWindowMetrics();
}
// print student metrics
void RegistrarOffice::printStudentMetrics() {
    // sort the processed student queue
    processedQueue->sort();
    int size = processedQueue->getSize();
    int *waitTimes = new int[size];

    // retrieve student wait time and store into array
    int idx = 0;
    while (!processedQueue->isEmpty()) {
        int time = processedQueue->pop().getWaitTime();
        if (time != 0) {
            waitTimes[idx++] = time;
        }
    }
    cout << "The mean student wait time : " << computeMean(waitTimes, idx) << endl;
    cout << "The median student wait time : " << computeMedian(waitTimes, idx) << endl;
    if (idx == 0) {
        cout << "The longest student wait time : 0" << endl;
    } else {
        cout << "The longest student wait time : " << waitTimes[idx - 1] << endl;
    }
    cout << "The number of students waiting over 10 minutes : " << countMark(waitTimes, idx, 10) << endl;
}
// print window metrics
void RegistrarOffice::printWindowMetrics() {
    // sort the windows
    sortWindows();
    int *idleTimes = new int[totalWindows];

    // retrieve window idle time and store into array
    int idx = 0;
    for (int i = 0; i < totalWindows; ++i) {
        idleTimes[idx++] = windows[i].getIdleTime();
    }
    cout << "The mean window idle time : " << computeMean(idleTimes, idx) << endl;
    if (idx == 0) {
        cout << "The longest window idle time : 0" << endl;
    } else {
        cout << "The longest window idle time : " << idleTimes[idx - 1] << endl;
    }
    cout << "The number of windows idle over 5 minutes : " << countMark(idleTimes, idx, 5) << endl;
}
// compute mean value
double RegistrarOffice::computeMean(int *times, int size) {
    int sum = 0;

    if (size == 0) {
      return 0;
    }
    for (int i = 0; i < size; ++i) {
        sum += times[i];
    }
    return (double)sum / (double)size;
}
// count for time exceeds the marker
double RegistrarOffice::countMark(int *times, int size, int mark) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (times[i] > mark) {
            count++;
        }
    }
    return count;
}
// compute the median value
double RegistrarOffice::computeMedian(int *times, int size) {

    if (size % 2 != 0) {
        return (double)times[size / 2];
    }
    return (double)(times[(size - 1) / 2] + times[size / 2]) / 2.0;
}
