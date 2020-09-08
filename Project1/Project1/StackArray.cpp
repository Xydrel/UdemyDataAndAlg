#pragma once

//Includes---------------------------------------------------------------------
#include "StackArray.h"

//Implementation---------------------------------------------------------------

IntStackArray::IntStackArray() :
    _top(-1)
{
}

bool IntStackArray::Push(int value)
{
    if (_top >= MAX - 1)
    {
        printf("Stack overflow on element insertion.");
        return false;
    }
    else
    {
        _container[++_top] = value;
        return true;
    }
}

int IntStackArray::Pop()
{
    auto value = _container[_top];
    _container[_top--] = -1;
    return value;
}

const size_t IntStackArray::Top() const
{
    return _top;
}

size_t IntStackArray::Size() const
{
    return (_top == -1) ? 0 : _top + 1;
}

bool IntStackArray::IsEmpty() const
{
    return _top <= -1;
}

bool IntStackArray::IsFull() const
{
    return _top == MAX - 1;
}

void IntStackArray::PrintElementValues() const
{
    if (_top != MAX)
    {
        for (auto i = 0; i <= _top; i++)
        {
            printf("Stack element value : %d", _container[i]);
        }
    }
}
