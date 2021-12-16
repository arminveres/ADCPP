#ifndef FILE_LOCKER_H_
#define FILE_LOCKER_H_

#include <string>

class FileLocker {
    std::string file;
    void lock();
    void unlock();
 public:
    FileLocker(std::string &fl);
    ~FileLocker();
};

#endif
