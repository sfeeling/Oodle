//
// Created by sfeeling on 18-4-20.
//

#include "../headers/FileInfo.h"

#include <string>

#include "../headers/SortStrategy.h"

using namespace std;

FileInfo::FileInfo()
{

}

FileInfo::~FileInfo()
{

}

const string &FileInfo::Name() const
{
    return name_;
}

const long long int &FileInfo::Size() const
{
    return size_;
}

const time_t &FileInfo::LastModified() const
{
    return modified_time_;
}

bool FileInfo::IsDirectory()
{
    return is_dir_;
}

FileInfo::FileInfo(const std::string &name, const int &size, const time_t &modified_time, const bool &is_dir)
    : name_(name),
      size_(size),
      modified_time_(modified_time),
      is_dir_(is_dir)
{

}
