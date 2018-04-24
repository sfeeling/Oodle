#include <unistd.h>

#include <iostream>
#include <string>

#include "FileInfo.h"
#include "DirInfo.h"
#include "SortStrategy.h"
#include "Pickler.h"
#include "PicklerMode.h"

using namespace std;

int main(int argc, char *argv[])
{
    char *path = nullptr;
    path = getcwd(nullptr, 0);  // 获取当前路径
    cout << "当前路径：" << endl << path << endl;       // 输出当前路径
    free(path);  // getcwd是c函数，使用alloc，用delete path无法正确回收内存

    cout << "目录中的文件：" << endl;
    system("ls");  // 先用shell命令临时完成最基本的显示目录的功能
    cout << endl;

    DirInfo *dir_info = new DirInfo();
    // 测试排序算法，具体取决于输入的参数
    SortStrategy *sort_strategy = new AlphaSort();
    dir_info->Sort(sort_strategy);
    // delete sort_strategy;
    // sort_strategy = new SizeSort();
    // dir_info->Sort(sort_strategy);

    // 测试模式
    PicklerMode *mode = new LogMode();
    Pickler *pickler = new Pickler(mode);
    pickler->Traversal();

    // delete mode;
    // mode = new DiffMode();
    // pickler->SetMode(mode);
    // pickler->Traversal();

    delete mode;
    delete pickler;
    delete dir_info;
    delete sort_strategy;
    return 0;
}
