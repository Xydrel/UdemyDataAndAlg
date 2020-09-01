#pragma once

#include "Array.h"

#include <iostream>

//Includes---------------------------------------------------------------------


//Types------------------------------------------------------------------------
class StructureTests
{
public:
    StructureTests() = default;
    ~StructureTests() = default;

    bool TestArray();
    void PrintIntArrayValues(const Array<int>& arr) const;
};

//Inline Implementation--------------------------------------------------------
bool StructureTests::TestArray()
{
    auto arr = Array<int>(6);
    printf("The size of arr is: %d", (int)arr.size());

    arr.push_back(12);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(5);
    arr.push_back(8);

    PrintIntArrayValues(arr);

    arr.push_back(9);

    PrintIntArrayValues(arr);

    arr.pop_back();

    PrintIntArrayValues(arr);

    return true;
}

inline void StructureTests::PrintIntArrayValues(const Array<int>& arr) const
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        int elementValue = arr[i];
        printf("Value at index %d is %d\n", (int)i, elementValue);
    }
}

namespace StructTests
{
    void Run_ArrayConstructionTest()
    {
        auto structureTests = StructureTests();
        structureTests.TestArray();
    }
}