//
// Created by sfeeling on 18-4-24.
//

#ifndef OODLE_SORTSTRATEGY_H
#define OODLE_SORTSTRATEGY_H


class SortStrategy
{
public:
    SortStrategy();
    virtual ~SortStrategy();

    virtual void sort() = 0;
};

class AlphaSort : public SortStrategy
{
public:
    void sort() override;
};

class SizeSort : public SortStrategy
{
public:
    void sort() override;
};

class LastModifiedSort : public SortStrategy
{
public:
    void sort() override;
};

#endif //OODLE_SORTSTRATEGY_H
