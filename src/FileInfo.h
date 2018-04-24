//
// Created by sfeeling on 18-4-20.
//

#ifndef OODLE_FILEINFO_H
#define OODLE_FILEINFO_H


#include <string>

class FileInfo
{
public:
    FileInfo();
    ~FileInfo();

    std::string Name();
    int Size();
    int LastModified();
    bool IsDirectory();
};


#endif //OODLE_FILEINFO_H
