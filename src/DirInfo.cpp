//
// Created by sfeeling on 18-4-20.
//

#include "DirInfo.h"

DirInfo::DirInfo()
{

}

DirInfo::~DirInfo()
{

}

void DirInfo::SetFilter()
{

}

void DirInfo::Sort(SortStrategy *sort_strategy)
{
    sort_strategy->sort();
}
