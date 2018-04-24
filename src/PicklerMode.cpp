//
// Created by sfeeling on 18-4-21.
//

#include "PicklerMode.h"

#include <iostream>

#include "Pickler.h"

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
    // TODO
    cout << "测试 LogMode::Log" << endl;
}

void LogMode::Traversal(Pickler *pickler)
{
    // TODO
    cout << "测试 LogMode::Traversal" << endl;
}

void LogMode::Compare(Pickler *)
{
    // empty
}

void LogMode::Diff(Pickler *)
{
    // empty
}

DiffMode::DiffMode()
{

}

DiffMode::~DiffMode()
{

}

void DiffMode::Traversal(Pickler *pickler)
{
    // TODO
    cout << "测试 DiffMode::Traversal" << endl;
}

void DiffMode::Compare(Pickler *pickler)
{
    // TODO
    cout << "测试 DiffMode::Compare" << endl;
}

void DiffMode::Diff(Pickler *pickler)
{
    // TODO
    cout << "测试 DiffMode::Diff" << endl;
}

void DiffMode::Log(Pickler *)
{
    // empty
}
