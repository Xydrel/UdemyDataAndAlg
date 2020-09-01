#pragma once

//Includes---------------------------------------------------------------------

#include <memory>

//Types------------------------------------------------------------------------

//IntNode
class IntNode
{
public:
    explicit IntNode();
    ~IntNode();

    const int GetData() const;
    void SetData(const int data);

    std::shared_ptr<IntNode> GetNext();
    void SetNext(std::shared_ptr<IntNode> node);

private:
    int _data;
    std::shared_ptr<IntNode> _next;
};

//IntLinkedList
class IntLinkedList
{
public:
    explicit IntLinkedList();

    size_t Size() const;

    void Append(std::shared_ptr<IntNode>& node);
    void InsertAt(std::shared_ptr<IntNode>& node, size_t index);
    void Remove(size_t index);

    void PrintDataValues() const;

private:
    void incrementSize();
    void decrementSize();

private:
    std::shared_ptr<IntNode> _head;
    std::shared_ptr<IntNode> _last;
    size_t _size = 0;
};

//Implementation---------------------------------------------------------------

//IntNode
inline IntNode::IntNode()
{
    _data = -1;
    _next = nullptr;
}

inline IntNode::~IntNode()
{
}

inline const int IntNode::GetData() const
{
    return _data;
}

inline void IntNode::SetData(const int data)
{
    _data = data;
}

inline std::shared_ptr<IntNode> IntNode::GetNext()
{
    return _next;
}

inline void IntNode::SetNext(std::shared_ptr<IntNode> node)
{
    _next = node;
}

inline IntLinkedList::IntLinkedList()
{
    _head = nullptr;
    _last = nullptr;
}

inline size_t IntLinkedList::Size() const
{
    return _size;
}


inline void IntLinkedList::Append(std::shared_ptr<IntNode>& node)
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

inline void IntLinkedList::InsertAt(std::shared_ptr<IntNode>& node, size_t index)
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

inline void IntLinkedList::Remove(size_t index)
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

inline void IntLinkedList::PrintDataValues() const
{
    if (_head != nullptr)
    {
        auto current = _head;
        while (current != nullptr)
        {
            printf("\nNode value is %d", current->GetData());
            
            current = current->GetNext();
        }

        printf("\n");
    }
}

inline void IntLinkedList::incrementSize()
{
    _size++;
}

inline void IntLinkedList::decrementSize()
{
    _size--;
}
