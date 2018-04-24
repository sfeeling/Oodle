//
// Created by sfeeling on 18-4-20.
//

#ifndef OODLE_DIRINFO_H
#define OODLE_DIRINFO_H


#include "FileInfo.h"
#include "SortStrategy.h"

class DirInfo : public FileInfo
{
public:
    DirInfo();
    ~DirInfo();

    // GetContents()
    // GetDirInfo()
    // GetFileInfo()
    void SetFilter();
    void Sort(SortStrategy *);

private:
    // SortStrategy *sort_strategy_;
    // 保留项，若使用则Sort()函数不需要参数，但是需要一个SetStrategy函数
};


#endif //OODLE_DIRINFO_H
