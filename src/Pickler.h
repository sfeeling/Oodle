//
// Created by sfeeling on 18-4-21.
//

#ifndef OODLE_PICKLER_H
#define OODLE_PICKLER_H

class PicklerMode;

class Pickler
{
public:
    Pickler();
    Pickler(PicklerMode *);
    ~Pickler();

    void Log();  // 记录日志
    void Traversal();  // 遍历目录
    void Compare();  // 获取日志进行比较
    void Diff();  // 显示差异

    bool SetMode(PicklerMode *);

private:
    PicklerMode *mode_;
};


#endif //OODLE_PICKLER_H
