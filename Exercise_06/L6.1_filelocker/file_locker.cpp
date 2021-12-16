#include "file_locker.h"

#include <iostream>

using namespace std;

void FileLocker::lock() {
    cout << "File " << file << "is locked" << endl;
}

void FileLocker::unlock() {
    cout << "File " << file << "is unlocked" << endl;
}

FileLocker::FileLocker(string &fl) : file(fl) {
    lock();
}

FileLocker::~FileLocker() {
    unlock();
}
