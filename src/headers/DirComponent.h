//
// Created by sfeeling on 18-6-16.
//

#ifndef OODLE_DIRCOMPONENT_H
#define OODLE_DIRCOMPONENT_H

#include "SortStrategy.h"

#include <memory>

class DirComponent
{
public:
    virtual void SetFilter() = 0;
    virtual void ShowContents() = 0;
    virtual void Sort(std::unique_ptr<SortStrategy>) = 0;
};


#endif //OODLE_DIRCOMPONENT_H
