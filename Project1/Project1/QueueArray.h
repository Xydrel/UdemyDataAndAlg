#pragma once

//Includes---------------------------------------------------------------------
#include <memory>

//Types------------------------------------------------------------------------

class IntQueueArray
{
    static const auto MAX = 100;

public:
    explicit IntQueueArray();

    bool Queue(int value);
    int Dequeue();

    const size_t Front() const;
    const size_t Rear() const;

    size_t Size() const;

    bool IsEmpty() const;
    bool IsFull() const;

    void PrintElementValues() const;

private:
    int _container[MAX] = {-1};
    size_t _front;
    size_t _rear;
};

