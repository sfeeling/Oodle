//
// Created by sfeeling on 18-6-16.
//

#ifndef OODLE_SORTFACTORY_H
#define OODLE_SORTFACTORY_H

#include <string>
#include <memory>

#include "SortStrategy.h"

class SortFactory
{
public:
    static shared_ptr<SortFactory> GetInstance();
    unique_ptr<SortStrategy> CreateSortStrategy(const std::string &);

private:
    SortFactory();

    static shared_ptr<SortFactory> instance_;
};


#endif //OODLE_SORTFACTORY_H
