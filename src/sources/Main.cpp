#include <unistd.h>
#include <cstring>
#include <ctime>

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

#include "../headers/FileInfo.h"
#include "../headers/DirInfo.h"
#include "../headers/SortFactory.h"
#include "../headers/Pickler.h"
#include "../headers/PicklerMode.h"
#include "../headers/Filter.h"

using namespace std;

int main(int argc, char *argv[])
{

    char *path = getcwd(nullptr, 0);  // 获取当前路径
    string cpath(path);
    free(path);


    DirComponent *dir_info = new DirInfo(cpath);
    vector<FileInfo> &file_vec(dynamic_cast<DirInfo*>(dir_info)->GetFileVec());

    unique_ptr<SortStrategy> sort_strategy;

    unique_ptr<PicklerMode> mode;
    unique_ptr<Pickler> pickler = make_unique<Pickler>(cpath);

    for (int i = 1; i < argc; i++)
    {
        string str_arg(argv[i]);
        if (str_arg == "log")
            mode = make_unique<LogMode>();
        else if (str_arg == "diff")
            mode = make_unique<DiffMode>();
        else
        {

            if (str_arg == "-alpha" || str_arg == "-size" || str_arg == "-time")
            {
                // 工厂本身是单例模式
                shared_ptr<SortFactory> sort_factory = SortFactory::GetInstance();
                sort_strategy = sort_factory->CreateSortStrategy(str_arg);
            }
            else if (str_arg == "-d" || str_arg == "-f")
            {
                dir_info = new FileTypeFilter(dir_info, file_vec, str_arg);
            }
            else if (str_arg == "-n")
            {
                str_arg = string(argv[++i]);
                dir_info = new FileNameFilter(dir_info, file_vec, str_arg);
            }
            else if (str_arg == "-s")
            {
                str_arg = string(argv[++i]);
                dir_info = new SizeFilter(dir_info, file_vec, str_arg);
            }
            else if (str_arg == "-t")
            {
                str_arg = string(argv[++i]);
                dir_info = new TimeFilter(dir_info, file_vec, str_arg);
            }
        }
    }


    dir_info->SetFilter();

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

    // 由于使用了装饰模式，内存管理比较复杂，暂时没能解决内存泄漏的bug
    delete dir_info;
    return 0;
}
