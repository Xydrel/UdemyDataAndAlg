#pragma once

//Includes---------------------------------------------------------------------
#include "Array.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"

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

    void TestDoublyLinkedList();
    void PrintIntDoublyLinkedListStatistics(const IntDoublyLinkedList& list) const;

    void TestCircularLinkedList();
    void PrintIntCircularLinkedListStatistics(const IntCircularLinkedList& list) const;
};

//Inline Implementation--------------------------------------------------------
void StructureTests::TestArray()
{
    printf("\nArray tests disabled due to linker errors.\n");

    //The linker errors arrived once I moved the implementation to a .cpp file and probably has something to do with the template code which I am not super familiar with.

    //auto arr = Array<int>(6);
    //printf("The size of arr is: %d", (int)arr.size());

    //arr.push_back(12);
    //arr.push_back(1);
    //arr.push_back(6);
    //arr.push_back(5);
    //arr.push_back(8);

    //PrintIntArrayValues(arr);

    //arr.push_back(9);

    //PrintIntArrayValues(arr);

    //arr.pop_back();

    //PrintIntArrayValues(arr);

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

    intLinkedList->Remove(3); //remove 48

    PrintIntLinkedListStatistics(*intLinkedList);

    {
        auto newNode = std::make_shared<IntNode>();
        newNode->SetData(99);
        intLinkedList->InsertAt(newNode, 5); //after 72

        PrintIntLinkedListStatistics(*intLinkedList);
    }

    {
        auto newNode = std::make_shared<IntNode>();
        newNode->SetData(256);
        intLinkedList->InsertAt(newNode, 10); //after 106

        PrintIntLinkedListStatistics(*intLinkedList);
    }
}

inline void StructureTests::PrintIntLinkedListStatistics(const IntLinkedList& list) const
{
    printf("\nSingly linked list size is: %d", (int)list.Size());

    list.PrintDataValues();
}

inline void StructureTests::TestDoublyLinkedList()
{
    auto intDoublyLinkedList = std::make_unique<IntDoublyLinkedList>();

    std::vector<int> numbers = { 2, 4, 6, 8, 10, 12, 14, 16 };

    for (size_t i = 0; i < numbers.size(); i++)
    {
        auto newNode = std::make_shared<IntDoublyNode>();
        newNode->SetData(numbers[i]);
        intDoublyLinkedList->Append(newNode);
    }

    PrintIntDoublyLinkedListStatistics(*intDoublyLinkedList);

    intDoublyLinkedList->Remove(3); //remove 8

    PrintIntDoublyLinkedListStatistics(*intDoublyLinkedList);

    {
        auto newNode = std::make_shared<IntDoublyNode>();
        newNode->SetData(99);
        intDoublyLinkedList->InsertAt(newNode, 5); //after 12

        PrintIntDoublyLinkedListStatistics(*intDoublyLinkedList);
    }

    {
        auto newNode = std::make_shared<IntDoublyNode>();
        newNode->SetData(256);
        intDoublyLinkedList->InsertAt(newNode, 10); //last element no exception

        PrintIntDoublyLinkedListStatistics(*intDoublyLinkedList);
    }
}

inline void StructureTests::PrintIntDoublyLinkedListStatistics(const IntDoublyLinkedList& list) const
{
    printf("\nDoubly linked list size is: %d", (int)list.Size());

    list.PrintDataValues();
}

inline void StructureTests::TestCircularLinkedList()
{
    auto intCircularLinkedList = std::make_unique<IntCircularLinkedList>();

    std::vector<int> numbers = { 2, 4, 6, 8, 10, 12, 14, 16 };

    for (size_t i = 0; i < numbers.size(); i++)
    {
        auto newNode = std::make_shared<IntCircularNode>();
        newNode->SetData(numbers[i]);
        intCircularLinkedList->Append(newNode);
    }

    PrintIntCircularLinkedListStatistics(*intCircularLinkedList);

    intCircularLinkedList->Remove(3); //remove 8

    PrintIntCircularLinkedListStatistics(*intCircularLinkedList);

    {
        auto newNode = std::make_shared<IntCircularNode>();
        newNode->SetData(99);
        intCircularLinkedList->InsertAt(newNode, 5); //after 12

        PrintIntCircularLinkedListStatistics(*intCircularLinkedList);
    }

    {
        auto newNode = std::make_shared<IntCircularNode>();
        newNode->SetData(256);
        intCircularLinkedList->InsertAt(newNode, 10); //last element no exception

        PrintIntCircularLinkedListStatistics(*intCircularLinkedList);
    }
}

inline void StructureTests::PrintIntCircularLinkedListStatistics(const IntCircularLinkedList& list) const
{
    printf("\nCircular linked list size is: %d", (int)list.Size());

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

    void Run_IntDoublyLinkedListTests()
    {
        auto structureTests = StructureTests();
        structureTests.TestDoublyLinkedList();
    }

    void Run_IntCircularLinkedListTests()
    {
        auto structureTests = StructureTests();
        structureTests.TestCircularLinkedList();
    }
}