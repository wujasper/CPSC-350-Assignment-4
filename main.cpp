/*
  Full Name: Jasper Wu
  Student ID: 2339715
  Chapman email: jaswu@chapman.edu
  Course number and section: 350-01
  Assignment Number: 4
*/

#include <cstdlib>
#include <exception>
#include "fileio.h"
#include "registrar.h"

using namespace std;

int main(int argc, char** argv) {

    string line;
    int lineType;
    int tick;
    int numOfStudents;
    RegistrarOffice *registrarOffice;

    FileIo *files = new FileIo();

    // read the setup file
    if (argc != 2) {
        cout << "Missing file name" << endl;
        return -1;
    }
    if (!files->openFileForRead(argv[1])) {
        cout << "Cannot open " << argv[1] << endl;
        return -1;
    }

    // instantiate registrar office object
    registrarOffice = new RegistrarOffice();

    // read the file and setup the simulation data
    registrarOffice->setupFromFile(files->readStream);
    // run the simulation
    registrarOffice->simulate();
    // print the metrics
    registrarOffice->printMetrics();

    return 0;
}
