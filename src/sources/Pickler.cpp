//
// Created by sfeeling on 18-4-21.
//

#include "../headers/Pickler.h"

#include "../headers/PicklerMode.h"

Pickler::Pickler()
{

}

Pickler::Pickler(const std::string &dir_name)
    : dir_name_(dir_name)
{
}

Pickler::~Pickler()
{

}

void Pickler::SetMode(std::unique_ptr<PicklerMode> mode)
{
    mode_ = std::move(mode);
}

void Pickler::Log()
{
    mode_->Log(this);
}

void Pickler::Traversal()
{
    mode_->Traversal(this, dir_name_);
}

void Pickler::Compare()
{
    mode_->Compare(this);
}

void Pickler::Diff()
{
    mode_->Diff(this);
}

