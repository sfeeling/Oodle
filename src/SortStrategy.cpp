//
// Created by sfeeling on 18-4-24.
//

#include "SortStrategy.h"
#include "DirInfo.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void AlphaSort::sort(vector<FileInfo> &file_vec)
{
    std::sort(file_vec.begin(), file_vec.end(), [this](const FileInfo &file1, const FileInfo &file2)
    {   string str1(file1.Name());
        string str2(file2.Name());
        transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
        transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
        return str1 < str2; });
}

void SizeSort::sort(vector<FileInfo> &file_vec)
{
    std::sort(file_vec.begin(), file_vec.end(), [this](const FileInfo &file1, const FileInfo &file2)
    { return file1.Size() < file2.Size(); });
}

void TimeSort::sort(vector<FileInfo> &file_vec)
{
    std::sort(file_vec.begin(), file_vec.end(), [this](const FileInfo &file1, const FileInfo &file2)
    { return file1.LastModified() < file2.LastModified(); });
}

SortStrategy::SortStrategy()
{

}

SortStrategy::~SortStrategy()
{

}
