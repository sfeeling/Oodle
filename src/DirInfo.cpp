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


void DirInfo::Sort(unique_ptr<SortStrategy> sort_strategy)
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
            bool is_dir = dirp->d_type == 4;
            if (is_dir)
            {
                FileInfo file_info(dirp->d_name, GetDirectorySize(dirp->d_name), buf.st_mtime, is_dir);
                file_vec_.push_back(file_info);
            }
            else
            {
                FileInfo file_info(dirp->d_name, buf.st_size, buf.st_mtime, is_dir);
                file_vec_.push_back(file_info);
            }
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

void DirInfo::SetFilter()
{
}

std::vector<FileInfo> &DirInfo::GetFileVec()
{
    return file_vec_;
}

long long int DirInfo::GetDirectorySize(char *dir)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    long long int totalSize=0;

    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "Cannot open dir: %s\n", dir);
        return -1; //可能是个文件，或者目录不存在
    }

    //先加上自身目录的大小
    lstat(dir, &statbuf);
    totalSize+=statbuf.st_size;

    while ((entry = readdir(dp)) != NULL)
    {
        char subdir[256];
        sprintf(subdir, "%s/%s", dir, entry->d_name);
        lstat(subdir, &statbuf);

        if (S_ISDIR(statbuf.st_mode))
        {
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
            {
                continue;
            }

            long long int subDirSize = GetDirectorySize(subdir);
            totalSize+=subDirSize;
        }
        else
        {
            totalSize+=statbuf.st_size;
        }
    }

    closedir(dp);
    return totalSize;
}

