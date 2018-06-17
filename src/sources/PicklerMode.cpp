//
// Created by sfeeling on 18-4-21.
//

#include "../headers/PicklerMode.h"

#include <dirent.h>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <fstream>

#include "../headers/Pickler.h"

using namespace std;

PicklerMode::PicklerMode()
{

}

PicklerMode::~PicklerMode()
{

}


LogMode::LogMode()
{

}

LogMode::~LogMode()
{

}

void LogMode::Log(Pickler *pickler)
{
    ofstream out_log(".oodle");
    for (auto item : pickler->file_vec_)
        out_log << item << endl;
    out_log.close();
}

void LogMode::Traversal(Pickler *pickler, const std::string &dir_name)
{
    DIR *dp;  // 目录流
    struct dirent *dirp;  // 用于记录目录中的文件信息

    if((dp = opendir(dir_name.c_str())) == nullptr)
        cout << "无法打开: " << dir_name << endl;

    while((dirp = readdir(dp)) != nullptr)
    {
        string dir = dir_name + "/" + dirp->d_name;
        if (dirp->d_type == 4 && strncmp(dirp->d_name, ".", 1) != 0)
        {
            pickler->file_vec_.push_back(dir);
            Traversal(pickler, dir);
        }
        else if(dirp->d_type == 8 && strncmp(dirp->d_name, ".", 1) != 0)
        {
            pickler->file_vec_.push_back(dir);
        }
    }

    closedir(dp);
}

void LogMode::Compare(Pickler *pickler)
{
    // empty
}

void LogMode::Diff(Pickler *pickler)
{
    // empty
}

DiffMode::DiffMode()
{

}

DiffMode::~DiffMode()
{

}

void DiffMode::Traversal(Pickler *pickler, const std::string &dir_name)
{
    DIR *dp;  // 目录流
    struct dirent *dirp;  // 用于记录目录中的文件信息

    if((dp = opendir(dir_name.c_str())) == nullptr)
        cout << "无法打开: " << dir_name << endl;

    while((dirp = readdir(dp)) != nullptr)
    {
        string dir = dir_name + "/" + dirp->d_name;
        if (dirp->d_type == 4 && strncmp(dirp->d_name, ".", 1) != 0)
        {
            pickler->file_vec_.push_back(dir);
            Traversal(pickler, dir);
        }
        else if(dirp->d_type == 8 && strncmp(dirp->d_name, ".", 1) != 0)
        {
            pickler->file_vec_.push_back(dir);
        }
    }

    closedir(dp);
}

void DiffMode::Compare(Pickler *pickler)
{
    ifstream in_log(".oodle");
    string str;
    while (in_log >> str)
        pickler->log_vec_.push_back(str);
    for (auto item : pickler->log_vec_)
    {
        auto iter = find(pickler->file_vec_.begin(), pickler->file_vec_.end(), item);
        if (iter == pickler->file_vec_.end())
            pickler->removed_vec_.push_back(item);
        else
            pickler->file_vec_.erase(iter);
    }
    for (auto item : pickler->file_vec_)
    {
        pickler->added_vec_.push_back(item);
    }
}

void DiffMode::Diff(Pickler *pickler)
{
    if (pickler->added_vec_.size() > 0)
    {
        for (auto item : pickler->added_vec_)
            cout << "\033[32m" << item << "\033[0m ";
        cout << endl;
    }
    if (pickler->removed_vec_.size() > 0)
    {
        for (auto item : pickler->removed_vec_)
            cout << "\033[31m" << item << "\033[0m ";
        cout << endl;
    }
}

void DiffMode::Log(Pickler *pickler)
{
    // empty
}

