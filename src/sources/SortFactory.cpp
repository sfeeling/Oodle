//
// Created by sfeeling on 18-6-16.
//

#include "../headers/SortFactory.h"

shared_ptr<SortFactory> SortFactory::instance_ = nullptr;

unique_ptr<SortStrategy> SortFactory::CreateSortStrategy(const std::string &sort_method)
{
    if (sort_method == "-alpha")
        return make_unique<AlphaSort>();
    if (sort_method == "-size")
        return make_unique<SizeSort>();
    if (sort_method == "-time")
        return make_unique<TimeSort>();
    return nullptr;
}

SortFactory::SortFactory()
{

}

shared_ptr<SortFactory> SortFactory::GetInstance()
{
    if (!instance_)
        instance_ = shared_ptr<SortFactory>(new SortFactory);
    return instance_;
}
