#include <iostream>
#include <fstream>

using namespace std;

class FileIo {

public:
    ifstream readStream;
    ofstream writeStream;

    FileIo();
    ~FileIo();

    bool openFileForRead(string fileName);
    bool openFileForWrite(string fileName);
    void closeFiles();
};
