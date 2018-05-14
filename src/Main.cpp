#include <unistd.h>
#include <cstring>

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

#include "FileInfo.h"
#include "DirInfo.h"
#include "SortStrategy.h"
#include "Pickler.h"
#include "PicklerMode.h"

using namespace std;

int main(int argc, char *argv[])
{

    string cpath(getcwd(nullptr, 0)); // 获取当前路径

    // 初始化自定义的目录类，改用智能指针
    unique_ptr<DirInfo> dir_info = make_unique<DirInfo>(cpath);

    //SortStrategy *sort_strategy = nullptr;
    unique_ptr<SortStrategy> sort_strategy;

    // 测试模式
    //PicklerMode *mode = nullptr;
    unique_ptr<PicklerMode> mode;
    unique_ptr<Pickler> pickler = make_unique<Pickler>(cpath);

    for (int i = 1; i < argc; i++)
    {
        string str_arg(argv[i]);
        if (str_arg == "log")
        {
            mode = make_unique<LogMode>();
        }
        else if (str_arg == "diff")
        {
            mode = make_unique<DiffMode>();
        }
        else
        {
            if (str_arg == "-alpha")
            {
                sort_strategy = make_unique<AlphaSort>();
            }

            if (str_arg == "-size")
            {
                sort_strategy = make_unique<SizeSort>();
            }
            if (str_arg == "-time")
            {
                sort_strategy = make_unique<TimeSort>();
            }
            dir_info->SetFilter(str_arg);
        }
    }

    if (mode)
    {
        pickler->SetMode(move(mode));
        pickler->Traversal();
        pickler->Log();
        pickler->Compare();
        pickler->Diff();
    }
    else
    {
        if (sort_strategy)
            dir_info->Sort(move(sort_strategy));
        dir_info->ShowContents();
    }

    return 0;
}
