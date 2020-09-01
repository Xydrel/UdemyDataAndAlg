#pragma once

//Includes---------------------------------------------------------------------

#include <memory>

//Types------------------------------------------------------------------------

//IntNode
class IntNode
{
public:
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
    explicit IntLinkedList() = default;

    void Append(std::shared_ptr<IntNode>& node);

private:
    std::shared_ptr<IntNode> _head;
};

//Implementation---------------------------------------------------------------

//IntNode
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
}