#pragma once

//Includes---------------------------------------------------------------------
#include "CircularLinkedList.h"

#include <memory>
//Implementation---------------------------------------------------------------

//IntCircularNode
IntCircularNode::IntCircularNode()
{
    _data = -1;
    _next = nullptr;
    _prev = nullptr;
}

IntCircularNode::~IntCircularNode()
{
}

const int IntCircularNode::GetData() const
{
    return _data;
}

void IntCircularNode::SetData(const int data)
{
    _data = data;
}

IntCircularNode::NodePtr IntCircularNode::GetNext()
{
    return _next;
}

void IntCircularNode::SetNext(NodePtr node)
{
    _next = node;
}

IntCircularNode::NodePtr IntCircularNode::GetPrev()
{
    return _prev;
}

void IntCircularNode::SetPrev(NodePtr node)
{
    _prev = node;
}

//IntCircularLinkedList
IntCircularLinkedList::IntCircularLinkedList()
{
    _head = nullptr;
    _last = nullptr;
}

size_t IntCircularLinkedList::Size() const
{
    return _size;
}

void IntCircularLinkedList::Append(ListNode& node)
{
    if (_head == nullptr)
    {
        _head = node;
        _last = node;
        _last->SetNext(_head);
    }
    else
    {
        auto current = _head;
        while (current->GetNext() != nullptr)
        {
            if (current == _last) break;

            current = current->GetNext();
        }

        current->SetNext(node);
        node->SetPrev(current);
        _last = node;
        _last->SetNext(_head);
    }

    incrementSize();
}

void IntCircularLinkedList::InsertAt(ListNode& node, size_t index)
{
    if (_head == nullptr)
    {
        _head = node;
        _last = node;
        _last->SetNext(_head);

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
                _last = node;
                _last->SetNext(_head);
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
                    _last->SetNext(_head);

                    return;
                }
            }

            current = current->GetNext();
        }

        incrementSize();
    }
}

void IntCircularLinkedList::Remove(size_t index)
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
                    _last->SetNext(_head);
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

IntCircularLinkedList::ListNode IntCircularLinkedList::Search(int key)
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

void IntCircularLinkedList::PrintDataValues() const
{
    if (_head != nullptr)
    {
        auto current = _head;
        auto iteration = 0;
        while (current != nullptr && iteration < 17)
        {
            iteration++;
            printf("\nCircular Linked Node prev value is %d", (current->GetPrev() != nullptr ? current->GetPrev()->GetData() : -1));
            printf("\nCircular Linked Node value is %d", current->GetData());
            printf("\nCircular Linked Node next value is %d", current->GetNext() != nullptr ? current->GetNext()->GetData() : -1);

            current = current->GetNext();
        }

        printf("\n");
    }
}

void IntCircularLinkedList::incrementSize()
{
    _size++;
}

void IntCircularLinkedList::decrementSize()
{
    _size--;
}

