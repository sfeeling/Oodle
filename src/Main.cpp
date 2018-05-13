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
    char *cpath = nullptr;
    cpath = getcwd(nullptr, 0);  // 获取当前路径

    // 初始化自定义的目录类
    //DirInfo *dir_info = new DirInfo(cpath);

    unique_ptr<DirInfo> dir_info(new DirInfo(cpath));
    SortStrategy *sort_strategy = nullptr;


    // 测试模式
    PicklerMode *mode = nullptr;
    Pickler *pickler = new Pickler(cpath);



    for (int i = 1; i < argc; i++)
    {
        string str_arg(argv[i]);
        if (str_arg == "log")
        {
            mode = new LogMode();
        }
        else if (str_arg == "diff")
        {
            mode = new DiffMode();
        }
        else
        {
            if (str_arg == "-alpha")
                sort_strategy = new AlphaSort();
            if (str_arg == "-size")
                sort_strategy = new SizeSort();
            if (str_arg == "-time")
                sort_strategy = new LastModifiedSort();
            dir_info->SetFilter(str_arg);
        }
    }

    if (mode)
    {
        pickler->SetMode(mode);
        pickler->Traversal();
        pickler->Log();
        pickler->Compare();
        pickler->Diff();
    }
    else
    {
        if (sort_strategy)
            dir_info->Sort(sort_strategy);
        dir_info->ShowContents();
    }

    free(cpath);  // getcwd是c函数，使用alloc，用delete path无法正确回收内存
    delete mode;
    delete pickler;
    delete sort_strategy;
    return 0;
}
