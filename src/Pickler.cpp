//
// Created by sfeeling on 18-4-21.
//

#include "Pickler.h"

#include "PicklerMode.h"

Pickler::Pickler()
{

}

Pickler::Pickler(PicklerMode *mode)
    : mode_(mode)
{
}

Pickler::~Pickler()
{

}

bool Pickler::SetMode(PicklerMode *mode)
{
    // 由PicklerMode中的SetMode调用
    mode_ = mode;
    return true;
}

void Pickler::Log()
{
    mode_->Log(this);
}

void Pickler::Traversal()
{
    mode_->Traversal(this);
}

void Pickler::Compare()
{
    mode_->Compare(this);
}

void Pickler::Diff()
{
    mode_->Diff(this);
}
