#pragma once

//Includes---------------------------------------------------------------------
#include "Array.h"

#include <memory>

//Types------------------------------------------------------------------------
class IntStackArray
{
    static const auto MAX = 100;

public:
    explicit IntStackArray();

    bool Push(int value);
    int Pop();

    const size_t Top() const;
    size_t Size() const;

    bool IsEmpty() const;
    bool IsFull() const;

    void PrintElementValues() const;

private:
    int _container[MAX] = {-1};
    size_t _top;
};

