#pragma once

//Includes---------------------------------------------------------------------
#include "DoublyLinkedList.h"

//Types------------------------------------------------------------------------
class QueueLinkedList
{
public:
    explicit QueueLinkedList();

    void Push(IntDoublyNode::NodePtr node);
    IntDoublyNode::NodePtr Pop();

    const IntDoublyNode::NodePtr First() const;
    size_t Size() const;

    bool IsEmpty() const;
    bool IsFull() const;
    bool IsValid() const;

    void PrintElementValues() const;

private:
    std::unique_ptr<IntDoublyLinkedList> _container;
};

