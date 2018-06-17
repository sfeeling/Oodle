//
// Created by sfeeling on 18-6-16.
//

#include "../headers/Filter.h"
#include "../headers/DirInfo.h"

#include <vector>
#include <iostream>

void FileTypeFilter::SetFilter()
{
    Filter::SetFilter();

    vector<FileInfo> temp_vec;

    if (criteria_ == "-f" || criteria_ == "-d")
    {
        bool is_dir = (criteria_ == "-d");
        for (auto &item : file_vec_)
            if (item.IsDirectory() == is_dir)
                temp_vec.push_back(item);
        if (temp_vec.size() != file_vec_.size())
        {
            file_vec_.erase(file_vec_.begin(), file_vec_.end());
            swap(file_vec_, temp_vec);
        }
    }
}


FileTypeFilter::FileTypeFilter(DirComponent *dir_component, vector<FileInfo> &file_vec, const string &criteria)
    : Filter(dir_component), criteria_(criteria), file_vec_(file_vec)
{
}

void FileTypeFilter::ShowContents()
{
    Filter::ShowContents();
}

void FileTypeFilter::Sort(std::unique_ptr<SortStrategy> sort_strategy)
{
    Filter::Sort(move(sort_strategy));
}


FileNameFilter::FileNameFilter(DirComponent *dir_component, vector<FileInfo> &file_vec, const string &criteria)
    : Filter(dir_component), criteria_(criteria), file_vec_(file_vec)
{

}

void FileNameFilter::ShowContents()
{
    Filter::ShowContents();
}

void FileNameFilter::SetFilter()
{
    Filter::SetFilter();

    vector<FileInfo> temp_vec;

    for (auto &item : file_vec_)
    {
        if (item.Name().find(criteria_) != string::npos)
            temp_vec.push_back(item);
    }
    if (temp_vec.size() != file_vec_.size())
    {
        file_vec_.erase(file_vec_.begin(), file_vec_.end());
        swap(file_vec_, temp_vec);
    }
}

void FileNameFilter::Sort(std::unique_ptr<SortStrategy> sort_strategy)
{
    Filter::Sort(move(sort_strategy));
}

SizeFilter::SizeFilter(DirComponent *dir_component, vector<FileInfo> &file_vec, const string &criteria)
        : Filter(dir_component), criteria_(criteria), file_vec_(file_vec)
{

}

long long int SizeFilter::ConvertSize(const string &str_size)
{
    char unit = str_size[str_size.size() - 1];
    long long int val = stoll(str_size.substr(0, str_size.size() - 1));
    if (unit == 'B')
        return val;
    else if (unit == 'K')
        return val * 1024;
    else if (unit == 'M')
        return val * 1024 * 1024;
    else if (unit == 'G')
        return val * 1024 * 1024 * 1024;
}

void SizeFilter::SetFilter()
{
    Filter::SetFilter();

    vector<FileInfo> temp_vec;
    long long int min_size = 0, max_size = 0;
    string min_str, max_str;
    auto pos = criteria_.find('-');
    if (pos != string::npos)
    {
        // -max_size
        if (pos == 0)
        {
            max_str = criteria_.substr(1);
        }
        // min_size-
        else if (pos == criteria_.size() - 1)
        {
            min_str = criteria_.substr(0, criteria_.size() - 1);
        }
        // min_size-max_size
        else
        {
            min_str = criteria_.substr(0, criteria_.find('-'));
            max_str = criteria_.substr(criteria_.find('-') + 1);
        }

        string str;
        for (auto c : min_str)
        {
            if (c == 'B' || c == 'K' || c == 'M' || c == 'G')
            {
                str += c;
                min_size += ConvertSize(str);
                str.erase();
            }
            else
            {
                str += c;
            }
        }
        for (auto c : max_str)
        {
            if (c == 'B' || c == 'K' || c == 'M' || c == 'G')
            {
                str += c;
                max_size += ConvertSize(str);
                str.erase();
            }
            else
            {
                str += c;
            }
        }
    }

    if (max_size != 0)
        for (auto &item : file_vec_)
        {
            if (item.Size() > min_size && item.Size() < max_size)
                temp_vec.push_back(item);
        }
    else
    {
        for (auto &item : file_vec_)
        {
            if (item.Size() > min_size)
                temp_vec.push_back(item);
        }
    }
    if (temp_vec.size() != file_vec_.size())
    {
        file_vec_.erase(file_vec_.begin(), file_vec_.end());
        swap(file_vec_, temp_vec);
    }

}

void SizeFilter::ShowContents()
{
    Filter::ShowContents();
}

void SizeFilter::Sort(std::unique_ptr<SortStrategy> sort_strategy)
{
    Filter::Sort(move(sort_strategy));
}


TimeFilter::TimeFilter(DirComponent *dir_component, vector<FileInfo> &file_vec, const string &criteria)
        : Filter(dir_component), criteria_(criteria), file_vec_(file_vec)
{

}

time_t TimeFilter::ConvertTime(const string &str_time)
{
    char unit = str_time[str_time.size() - 1];
    time_t val = stol(str_time.substr(0, str_time.size() - 1));
    if (unit == 's')
        return val;
    else if (unit == 'm')
        return val * 60;
    else if (unit == 'h')
        return val * 3600;
    else if (unit == 'd')
        return val * 3600 * 24;
    else if (unit == 'M')
        return val * 3600 * 24 * 30;
    else if (unit == 'y')
        return val * 3600 * 24 * 365;
}

void TimeFilter::SetFilter()
{
    Filter::SetFilter();

    vector<FileInfo> temp_vec;
    time_t now_time = time(nullptr);
    time_t start_time = now_time, end_time = now_time;
    string start_str, end_str;
    auto pos = criteria_.find('-');
    if (pos != string::npos)
    {
        // -end_time
        if (pos == 0)
        {
            end_str = criteria_.substr(1);
        }
        // start_time-
        else if (pos == criteria_.size() - 1)
        {
            start_str = criteria_.substr(0, criteria_.size() - 1);
        }
        // start_time-end_time
        else
        {
            start_str = criteria_.substr(0, criteria_.find('-'));
            end_str = criteria_.substr(criteria_.find('-') + 1);
        }

        string str;
        for (auto c : start_str)
        {
            if (c == 's' || c == 'm' || c == 'h' || c == 'd' || c == 'M' || c == 'y')
            {
                str += c;
                start_time -= ConvertTime(str);
                str.erase();
            }
            else
            {
                str += c;
            }
        }
        for (auto c : end_str)
        {
            if (c == 's' || c == 'm' || c == 'h' || c == 'd' || c == 'M' || c == 'y')
            {
                str += c;
                end_time -= ConvertTime(str);
                str.erase();
            }
            else
            {
                str += c;
            }
        }
    }

    if (start_time != now_time)
        for (auto &item : file_vec_)
        {
            if (item.LastModified() > start_time && item.LastModified() < end_time)
                temp_vec.push_back(item);
        }
    else
    {
        for (auto &item : file_vec_)
        {
            if (item.LastModified() < end_time)
                temp_vec.push_back(item);
        }
    }
    if (temp_vec.size() != file_vec_.size())
    {
        file_vec_.erase(file_vec_.begin(), file_vec_.end());
        swap(file_vec_, temp_vec);
    }
}

void TimeFilter::ShowContents()
{
    Filter::ShowContents();
}

void TimeFilter::Sort(std::unique_ptr<SortStrategy> sort_strategy)
{
    Filter::Sort(move(sort_strategy));
}


