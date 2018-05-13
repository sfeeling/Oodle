//
// Created by sfeeling on 18-4-20.
//

#ifndef OODLE_DIRINFO_H
#define OODLE_DIRINFO_H

#include "FileInfo.h"
#include "SortStrategy.h"

#include <sys/stat.h>

#include <vector>


class DirInfo : public FileInfo
{
public:
    DirInfo();
    explicit DirInfo(const std::string &);
    ~DirInfo();

    void ShowContents();
    // GetDirInfo()
    // GetFileInfo()
    void SetFilter(const std::string &);
    void Sort(SortStrategy *);

private:
    // SortStrategy *sort_strategy_;
    // 保留项，若使用则Sort()函数不需要参数，但是需要一个SetStrategy函数
    friend class AlphaSort;
    std::string dir_name_;
    std::vector<FileInfo> file_vec_;
};


#endif //OODLE_DIRINFO_H
