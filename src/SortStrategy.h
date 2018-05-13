//
// Created by sfeeling on 18-4-24.
//

#ifndef OODLE_SORTSTRATEGY_H
#define OODLE_SORTSTRATEGY_H

#include "FileInfo.h"

#include <vector>

using namespace std;

class DirInfo;

class SortStrategy
{
public:
    SortStrategy();
    virtual ~SortStrategy();

    virtual void sort(vector<FileInfo> &) = 0;
};

class AlphaSort : public SortStrategy
{
public:
    void sort(vector<FileInfo> &) override;
};

class SizeSort : public SortStrategy
{
public:
    void sort(vector<FileInfo> &) override;
};

class LastModifiedSort : public SortStrategy
{
public:
    void sort(vector<FileInfo> &) override;
};

#endif //OODLE_SORTSTRATEGY_H
