#pragma once

//Includes---------------------------------------------------------------------
#include "QueueArray.h"

//Implementation---------------------------------------------------------------

IntQueueArray::IntQueueArray() :
    _front(0),
    _rear(0)
{
}

bool IntQueueArray::Queue(int value)
{
    if (_rear >= MAX - 1)
    {
        printf("Stack overflow on element insertion.");

        return false;
    }
    else
    {
        _container[++_rear] = value;

        return true;
    }
}

int IntQueueArray::Dequeue()
{
    auto value = _container[_front];
    for (auto i = _front; i < _rear; i++)
    {
        _container[i] = _container[i + 1];
    }
    --_rear;

    return value;
}

const size_t IntQueueArray::Front() const
{
    return _front;
}

const size_t IntQueueArray::Rear() const
{
    return _rear;
}

size_t IntQueueArray::Size() const
{
    return _rear;
}

bool IntQueueArray::IsEmpty() const
{
    return _rear == 0;
}

bool IntQueueArray::IsFull() const
{
    return _rear == MAX;
}

void IntQueueArray::PrintElementValues() const
{
    if (_rear != MAX)
    {
        for (auto i = _front; i <= _rear; i++)
        {
            printf("Stack element value : %d", _container[i]);
        }
    }
}
