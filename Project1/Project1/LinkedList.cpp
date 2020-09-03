#pragma once

//Includes---------------------------------------------------------------------
#include "LinkedList.h"

#include <memory>

//Implementation---------------------------------------------------------------

//IntNode
IntNode::IntNode()
{
    _data = -1;
    _next = nullptr;
}

IntNode::~IntNode()
{
}

const int IntNode::GetData() const
{
    return _data;
}

void IntNode::SetData(const int data)
{
    _data = data;
}

IntNode::NodePtr IntNode::GetNext()
{
    return _next;
}

void IntNode::SetNext(NodePtr node)
{
    _next = node;
}

IntLinkedList::IntLinkedList()
{
    _head = nullptr;
    _last = nullptr;
}

size_t IntLinkedList::Size() const
{
    return _size;
}

void IntLinkedList::Append(ListNode& node)
{
    if (_head == nullptr)
    {
        _head = node;
        _last = node;
    }
    else
    {
        auto current = _head;
        while (current->GetNext() != nullptr)
        {
            current = current->GetNext();
        }

        current->SetNext(node);
        _last = node;
    }

    incrementSize();
}

void IntLinkedList::InsertAt(ListNode& node, size_t index)
{
    if (_head == nullptr)
    {
        _head = node;
        _last = node;

        incrementSize();
    }
    else
    {
        auto current = _head;
        for (size_t i = 0; i <= index; i++)
        {
            if (current == _last)
            {
                current->SetNext(node);
                return;
            }

            if (i == index - 1)
            {
                if (current->GetNext() != nullptr)
                {
                    node->SetNext(current->GetNext());
                    current->SetNext(node);

                    return;
                }
                else
                {
                    current->SetNext(node);
                    _last = node;

                    return;
                }
            }

            current = current->GetNext();
        }

        incrementSize();
    }
}

void IntLinkedList::Remove(size_t index)
{
    if (_head != nullptr)
    {
        auto current = _head;
        for (size_t i = 0; i < index; i++)
        {
            if (i == index - 1)
            {
                auto oldNext = current->GetNext();
                auto newNext = oldNext->GetNext();
                
                if (oldNext == _last)
                {
                    _last = newNext;
                }

                current->SetNext(newNext);

                oldNext = nullptr;

                decrementSize();

                return;
            }

            current = current->GetNext();
        }
    }
}

IntLinkedList::ListNode IntLinkedList::Search(int key)
{
    if (_head != nullptr)
    {
        auto current = _head;
        while (current != nullptr)
        {
            if (current->GetData() == key)
            {
                return current;
            }

            current = current->GetNext();
        }
    }

    return nullptr;
}

void IntLinkedList::PrintDataValues() const
{
    if (_head != nullptr)
    {
        auto current = _head;
        while (current != nullptr)
        {
            printf("\nSingly Linked Node value is %d", current->GetData());
            
            current = current->GetNext();
        }

        printf("\n");
    }
}

void IntLinkedList::incrementSize()
{
    _size++;
}

void IntLinkedList::decrementSize()
{
    _size--;
}
