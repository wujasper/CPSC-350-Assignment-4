#include "fileio.h"
  
FileIo::FileIo() {
}
FileIo::~FileIo() {
    closeFiles();
}
bool FileIo::openFileForRead(string fileName) {

    readStream.open(fileName);
    if (!readStream) {
        return false;
    }
    return true;
}
bool FileIo::openFileForWrite(string fileName) {

    writeStream.open(fileName);
    if (!writeStream) {
        return false;
    }
    return true;
}
void FileIo::closeFiles() {

    if (!readStream) {
        readStream.close();
    }
    if (!writeStream) {
        writeStream.close();
    }
}

