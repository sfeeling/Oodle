//
// Created by sfeeling on 18-6-16.
//

#ifndef OODLE_FILTER_H
#define OODLE_FILTER_H

#include "DirComponent.h"
#include "DirInfo.h"

#include <string>

class Filter: public DirComponent
{
public:
    Filter(DirComponent *dir_component)
            : dir_component_(dir_component)
    {
    }

    void SetFilter()
    {
        dir_component_->SetFilter();
    }

    void ShowContents()
    {
        dir_component_->ShowContents();
    }

    void Sort(std::unique_ptr<SortStrategy> sort_strategy)
    {
        dir_component_->Sort(move(sort_strategy));
    }

protected:
    DirComponent *dir_component_;
};

class FileTypeFilter: public Filter
{
public:
    FileTypeFilter(DirComponent*, vector<FileInfo>&, const string&);

    void SetFilter() override;
    void ShowContents() override;
    void Sort(std::unique_ptr<SortStrategy>) override;

private:
    string criteria_;
    vector<FileInfo> &file_vec_;
};

class FileNameFilter: public Filter
{
public:
    FileNameFilter(DirComponent*, vector<FileInfo>&, const string&);

    void SetFilter() override;
    void ShowContents() override;
    void Sort(std::unique_ptr<SortStrategy>) override;

private:
    string criteria_;
    vector<FileInfo> &file_vec_;
};

class SizeFilter: public Filter
{
public:
    SizeFilter(DirComponent*, vector<FileInfo>&, const string&);

    void SetFilter() override;
    void ShowContents() override;
    void Sort(std::unique_ptr<SortStrategy>) override;

    long long int ConvertSize(const string&);

private:
    string criteria_;
    vector<FileInfo> &file_vec_;
};

class TimeFilter: public Filter
{
public:
    TimeFilter(DirComponent*, vector<FileInfo>&, const string&);

    void SetFilter() override;
    void ShowContents() override;
    void Sort(std::unique_ptr<SortStrategy>) override;

    time_t ConvertTime(const string&);
private:
    string criteria_;
    vector<FileInfo> &file_vec_;
};

#endif //OODLE_FILTER_H
