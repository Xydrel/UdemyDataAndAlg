#pragma once

//Includes---------------------------------------------------------------------
#include "DoublyLinkedList.h"

#include <memory>

//Implementation---------------------------------------------------------------

//IntDoublyNode
IntDoublyNode::IntDoublyNode()
{
    _data = -1;
    _next = nullptr;
    _prev = nullptr;
}

IntDoublyNode::~IntDoublyNode()
{
}

const int IntDoublyNode::GetData() const
{
    return _data;
}

void IntDoublyNode::SetData(const int data)
{
    _data = data;
}

IntDoublyNode::NodePtr IntDoublyNode::GetNext()
{
    return _next;
}

void IntDoublyNode::SetNext(NodePtr node)
{
    _next = node;
}

IntDoublyNode::NodePtr IntDoublyNode::GetPrev()
{
    return _prev;
}

void IntDoublyNode::SetPrev(NodePtr node)
{
    _prev = node;
}

IntDoublyLinkedList::IntDoublyLinkedList()
{
    _head = nullptr;
    _last = nullptr;
}

size_t IntDoublyLinkedList::Size() const
{
    return _size;
}

IntDoublyLinkedList::ListNode IntDoublyLinkedList::GetLast()
{
    return _last;
}

IntDoublyLinkedList::ListNode IntDoublyLinkedList::GetHead()
{
    return _head;
}

void IntDoublyLinkedList::Push(ListNode& node)
{
    InsertAt(node, 0);
}

void IntDoublyLinkedList::Pop()
{
    RemoveAt(0);
}

void IntDoublyLinkedList::PushBack(ListNode& node)
{
    Append(node);
}

void IntDoublyLinkedList::PopBack()
{
    if (_last != nullptr)
    {
        auto newLast = _last->GetPrev();
        newLast->SetNext(nullptr);
        _last = nullptr;
        _last = newLast;

        decrementSize();
    }
}

void IntDoublyLinkedList::Append(ListNode& node)
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
        node->SetPrev(current);
        _last = node;
    }

    incrementSize();
}

void IntDoublyLinkedList::InsertAt(ListNode& node, size_t index)
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
                node->SetPrev(current);
                current->SetNext(node);
                return;
            }

            if (i == index - 1)
            {
                if (current->GetNext() != nullptr)
                {
                    node->SetNext(current->GetNext());
                    node->SetPrev(current);
                    current->SetNext(node);

                    return;
                }
                else
                {
                    current->SetNext(node);
                    node->SetPrev(current);
                    _last = node;

                    return;
                }
            }

            current = current->GetNext();
        }

        incrementSize();
    }
}

void IntDoublyLinkedList::RemoveAt(size_t index)
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
                newNext->SetPrev(current);

                oldNext = nullptr;

                decrementSize();

                return;
            }

            current = current->GetNext();
        }
    }
}

IntDoublyLinkedList::ListNode IntDoublyLinkedList::Search(int key)
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

void IntDoublyLinkedList::PrintDataValues() const
{
    if (_head != nullptr)
    {
        auto current = _head;
        while (current != nullptr)
        {
            printf("\nDoubly Linked Node prev value is %d", (current->GetPrev() != nullptr ? current->GetPrev()->GetData() : -1));
            printf("\nDoubly Linked Node value is %d", current->GetData());
            printf("\nDoubly Linked Node next value is %d", current->GetNext() != nullptr ? current->GetNext()->GetData() : -1);

            current = current->GetNext();
        }

        printf("\n");
    }
}

void IntDoublyLinkedList::incrementSize()
{
    _size++;
}

void IntDoublyLinkedList::decrementSize()
{
    _size--;
}

