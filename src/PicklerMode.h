//
// Created by sfeeling on 18-4-21.
//

#ifndef OODLE_PICKLERMODE_H
#define OODLE_PICKLERMODE_H

class Pickler;

class PicklerMode
{
public:
    PicklerMode();
    virtual ~PicklerMode();

    virtual void Log(Pickler *) = 0;
    virtual void Traversal(Pickler *) = 0;
    virtual void Compare(Pickler *) = 0;
    virtual void Diff(Pickler *) = 0;

};


class LogMode : public PicklerMode
{
public:
    LogMode();
    ~LogMode() override;

    // 这两个函数是需要的，但还未实现
    void Log(Pickler *) override;
    void Traversal(Pickler *) override;

    // 这两个函数不需要，只需要空的函数
    void Compare(Pickler *) override;
    void Diff(Pickler *) override;
};

class DiffMode : public PicklerMode
{
public:
    DiffMode();
    ~DiffMode() override;

    // 需要的函数，暂未实现
    void Traversal(Pickler *) override;
    void Compare(Pickler *) override;
    void Diff(Pickler *) override;

    // 不需要的函数，为空
    void Log(Pickler *) override;
};


#endif //OODLE_PICKLERMODE_H
