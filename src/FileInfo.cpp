//
// Created by sfeeling on 18-4-20.
//

#include "FileInfo.h"

#include <string>

#include "SortStrategy.h"

using namespace std;

FileInfo::FileInfo()
{

}

FileInfo::~FileInfo()
{

}

string FileInfo::Name()
{
    return nullptr;
}

int FileInfo::Size()
{
    return 0;
}

int FileInfo::LastModified()
{
    return 0;
}

bool FileInfo::IsDirectory()
{
    return false;
}
