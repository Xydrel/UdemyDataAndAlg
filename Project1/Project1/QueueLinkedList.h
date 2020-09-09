#pragma once

//Includes---------------------------------------------------------------------
#include "DoublyLinkedList.h"

//Types------------------------------------------------------------------------
class QueueLinkedList
{
public:
    explicit QueueLinkedList();

    void Queue(IntDoublyNode::NodePtr node);
    IntDoublyNode::NodePtr Dequeue();

    const IntDoublyNode::NodePtr First() const;
    const IntDoublyNode::NodePtr Rear() const;

    size_t Size() const;

    bool IsEmpty() const;
    bool IsFull() const;
    bool IsValid() const;

    void PrintElementValues() const;

private:
    std::unique_ptr<IntDoublyLinkedList> _container;
};

