//
// Created by sfeeling on 18-4-21.
//

#ifndef OODLE_PICKLER_H
#define OODLE_PICKLER_H

#include <string>
#include <vector>
#include <memory>

class PicklerMode;

class Pickler
{
public:
    Pickler();
    explicit Pickler(const std::string &);
    ~Pickler();

    void Log();  // 记录日志
    void Traversal();  // 遍历目录
    void Compare();  // 获取日志进行比较
    void Diff();  // 显示差异

    void SetMode(std::unique_ptr<PicklerMode>);

private:
    friend class LogMode;
    friend class DiffMode;

    std::unique_ptr<PicklerMode> mode_;
    std::string dir_name_;
    std::vector<std::string> file_vec_;
    std::vector<std::string> log_vec_;
    std::vector<std::string> added_vec_;
    std::vector<std::string> removed_vec_;
};


#endif //OODLE_PICKLER_H
