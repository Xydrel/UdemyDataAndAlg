#pragma once

//Includes---------------------------------------------------------------------
#include "QueueArray.h"

//Implementation---------------------------------------------------------------

IntQueueArray::IntQueueArray() :
    _front(-1),
    _rear(-1),
    _size(0)
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
        ++_size;

        return true;
    }
}

int IntQueueArray::Dequeue()
{
    auto value = _container[_front];
    _container[_front++] = -1;
    --_size;

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
    return _size;
}

bool IntQueueArray::IsEmpty() const
{
    return _size == 0;
}

bool IntQueueArray::IsFull() const
{
    return _size == MAX;
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
