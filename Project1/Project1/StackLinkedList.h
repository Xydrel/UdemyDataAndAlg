#pragma once

//Includes---------------------------------------------------------------------
#include "DoublyLinkedList.h"

//Types------------------------------------------------------------------------
class StackLinkedList
{
public:
    explicit StackLinkedList();

    void Push(IntDoublyNode::NodePtr node);
    IntDoublyNode::NodePtr Pop();

    const IntDoublyNode::NodePtr Top() const;
    size_t Size() const;

    bool IsEmpty() const;
    bool IsFull() const;
    bool IsValid() const;

    void PrintElementValues() const;

private:
    std::unique_ptr<IntDoublyLinkedList> _container;
};

