#pragma once

//Includes---------------------------------------------------------------------

#include <memory>

//Types------------------------------------------------------------------------

//IntNode
class IntNode
{
public:
    explicit IntNode();
    ~IntNode() = default;

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

    void PrintDataValues() const;

private:
    void incrementSize();

private:
    std::shared_ptr<IntNode> _head;
    size_t _size = 0;
};

//Implementation---------------------------------------------------------------

//IntNode
inline IntNode::IntNode()
{
    _data = -1;
    _next = nullptr;
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
    }
    else
    {
        auto current = _head;
        while (current->GetNext() != nullptr)
        {
            current = current->GetNext();
        }

        current->SetNext(node);
    }

    incrementSize();
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
