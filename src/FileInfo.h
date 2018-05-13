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
    FileInfo(const std::string &, const int &, const time_t &, const bool &);
    ~FileInfo();

    const std::string &Name() const;
    const int &Size() const;
    const time_t &LastModified() const;
    bool IsDirectory();

private:
    std::string name_;
    int size_;
    time_t modified_time_;
    bool is_dir_;
};


#endif //OODLE_FILEINFO_H
