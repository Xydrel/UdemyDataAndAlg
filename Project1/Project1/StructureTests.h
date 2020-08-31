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

    bool ConstructArray();
};

//Inline Implementation--------------------------------------------------------
bool StructureTests::ConstructArray()
{
    auto arr = Array<int>(6);
    printf("The size of arr is: %d", (int)arr.size());

    return true;
}

namespace StructTests
{
    void Run_ArrayConstructionTest()
    {
        auto structureTests = StructureTests();
        structureTests.ConstructArray();
    }
}