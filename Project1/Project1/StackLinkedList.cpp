#pragma once

//Includes---------------------------------------------------------------------
#include "StackLinkedList.h"

//Implementation---------------------------------------------------------------

StackLinkedList::StackLinkedList() :
    _container(std::make_unique<IntDoublyLinkedList>())
{
    if (_container == nullptr)
    {
        printf("No container was set");
        return;
    }
}

void StackLinkedList::Push(IntDoublyNode::NodePtr node)
{
    _container->Push(node);
}

IntDoublyNode::NodePtr StackLinkedList::Pop()
{
    auto node = _container->GetHead();
    _container->Pop();

    return node;
}

const IntDoublyNode::NodePtr StackLinkedList::Top() const
{
    return _container->GetHead();
}

size_t StackLinkedList::Size() const
{
    return _container->Size();
}

bool StackLinkedList::IsEmpty() const
{
    return _container->Size() == 0;
}

bool StackLinkedList::IsFull() const
{
    return false; //This linked list implementation doesn't limit the number of elements in the list
}

bool StackLinkedList::IsValid() const
{
    return _container != nullptr;
}

void StackLinkedList::PrintElementValues() const
{
    printf("\nPrinting stack underlying doubly linked list values");

    _container->PrintDataValues();
}
