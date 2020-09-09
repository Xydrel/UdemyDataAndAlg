#pragma once

//Includes---------------------------------------------------------------------
#include "QueueLinkedList.h"

//Implementation---------------------------------------------------------------

QueueLinkedList::QueueLinkedList() :
    _container(std::make_unique<IntDoublyLinkedList>())
{
    if (_container == nullptr)
    {
        printf("No container was set");
        return;
    }
}

void QueueLinkedList::Push(IntDoublyNode::NodePtr node)
{
    _container->Push(node);
}

IntDoublyNode::NodePtr QueueLinkedList::Pop()
{
    auto node = _container->GetLast();
    _container->PopBack();

    return node;
}

const IntDoublyNode::NodePtr QueueLinkedList::First() const
{
    return _container->GetLast();
}

size_t QueueLinkedList::Size() const
{
    return _container->Size();
}

bool QueueLinkedList::IsEmpty() const
{
    return _container->Size() == 0;
}

bool QueueLinkedList::IsFull() const
{
    return false; //This linked list implementation doesn't limit the number of elements in the list
}

bool QueueLinkedList::IsValid() const
{
    return _container != nullptr;
}

void QueueLinkedList::PrintElementValues() const
{
    printf("\nPrinting stack underlying doubly linked list values");

    _container->PrintDataValues();
}
