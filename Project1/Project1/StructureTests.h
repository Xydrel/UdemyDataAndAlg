#pragma once

//Includes---------------------------------------------------------------------
#include "Array.h"
#include "LinkedList.h"

#include <iostream>

//Types------------------------------------------------------------------------
class StructureTests
{
public:
    StructureTests() = default;
    ~StructureTests() = default;

    void TestArray();
    void PrintIntArrayValues(const Array<int>& arr) const;

    void TestSingleLinkedList();
    void PrintIntLinkedListStatistics(const IntLinkedList& list) const;
};

//Inline Implementation--------------------------------------------------------
void StructureTests::TestArray()
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

}

inline void StructureTests::PrintIntArrayValues(const Array<int>& arr) const
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        int elementValue = arr[i];
        printf("Value at index %d is %d\n", (int)i, elementValue);
    }
}

inline void StructureTests::TestSingleLinkedList()
{
    auto intLinkedList = std::make_unique<IntLinkedList>();

    std::vector<int> numbers = { 12, 24, 36, 48, 60, 72, 94, 106 };

    for (size_t i = 0; i < numbers.size(); i++)
    {
        auto newNode = std::make_shared<IntNode>();
        newNode->SetData(numbers[i]);
        intLinkedList->Append(newNode);
    }

    PrintIntLinkedListStatistics(*intLinkedList);

}

inline void StructureTests::PrintIntLinkedListStatistics(const IntLinkedList& list) const
{
    printf("\nList size is: %d", (long long)list.Size());

    list.PrintDataValues();
}

namespace StructTests
{
    void Run_ArrayConstructionTest()
    {
        auto structureTests = StructureTests();
        structureTests.TestArray();
    }

    void Run_IntLinkedListTests()
    {
        auto structureTests = StructureTests();
        structureTests.TestSingleLinkedList();
    }
}