//
// Created by sfeeling on 18-4-20.
//

#include "DirInfo.h"
#include "FileInfo.h"

#include <dirent.h>
#include <cstring>

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

DirInfo::DirInfo()
{

}

DirInfo::~DirInfo()
{

}

void DirInfo::SetFilter(const std::string &criteria)
{
    vector<FileInfo> temp_vec;
    if (criteria == "-f" || criteria == "-d")
    {
        bool is_dir = (criteria == "-d");
        for (auto &item : file_vec_)
            if (item.IsDirectory() == is_dir)
                temp_vec.push_back(item);
        if (temp_vec.size() != file_vec_.size())
        {
            file_vec_.erase(file_vec_.begin(), file_vec_.end());
            file_vec_ = temp_vec;
        }
    }
}

void DirInfo::Sort(SortStrategy *sort_strategy)
{
    sort_strategy->sort(file_vec_);
}

DirInfo::DirInfo(const std::string &dir_name)
    : dir_name_(dir_name)
{
    DIR *dp;  // 目录流
    struct dirent *dirp;  // 用于记录目录中的文件信息

    if((dp = opendir(dir_name.c_str())) == nullptr)
        cout << "无法打开: " << dir_name << endl;

    while((dirp = readdir(dp)) != nullptr)
    {
        if((dirp->d_type == 8 || dirp->d_type == 4) \
                && strncmp(dirp->d_name, ".", 1) != 0)
        {
            struct stat buf;
            stat(dirp->d_name, &buf);
            bool is_dir = dirp->d_type == 4;  // 4表示目录
            FileInfo file_info(dirp->d_name, buf.st_size, buf.st_mtime, is_dir);
            file_vec_.push_back(file_info);
        }
    }

    closedir(dp);
}

void DirInfo::ShowContents()
{
    for (auto &file : file_vec_)
    {
        cout << file.Name() << " ";
    }
    cout << endl;
}

