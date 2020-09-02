#pragma once


//Includes---------------------------------------------------------------------

#include <memory>

//Types------------------------------------------------------------------------

//IntDoublyNode
class IntDoublyNode
{
public:
    using NodePtr = std::shared_ptr<IntDoublyNode>;

    explicit IntDoublyNode();
    ~IntDoublyNode();
    //~IntDoublyNode() = default; //disabled for destructor testing

    const int GetData() const;
    void SetData(const int data);

    NodePtr GetNext();
    void SetNext(NodePtr node);

    NodePtr GetPrev();
    void SetPrev(NodePtr node);

private:
    int _data;
    NodePtr _next;
    NodePtr _prev;
};

//IntDoublyLinkedList
class IntDoublyLinkedList
{
public:
    using ListNode = std::shared_ptr<IntDoublyNode>;

    explicit IntDoublyLinkedList();
    ~IntDoublyLinkedList() = default;

    IntDoublyLinkedList(const IntDoublyLinkedList& rhs) = delete;
    IntDoublyLinkedList operator=(const IntDoublyLinkedList& rhs) = delete;

    size_t Size() const;

    void Append(ListNode& node);
    void InsertAt(ListNode& node, size_t index);
    void Remove(size_t index);

    ListNode Search(int key);

    void PrintDataValues() const;

private:
    void incrementSize();
    void decrementSize();

private:
    ListNode _head;
    ListNode _last;
    size_t _size = 0;
};

//Implementation---------------------------------------------------------------

//IntDoublyNode
inline IntDoublyNode::IntDoublyNode()
{
    _data = -1;
    _next = nullptr;
    _prev = nullptr;
}

inline IntDoublyNode::~IntDoublyNode()
{
}

inline const int IntDoublyNode::GetData() const
{
    return _data;
}

inline void IntDoublyNode::SetData(const int data)
{
    _data = data;
}

inline IntDoublyNode::NodePtr IntDoublyNode::GetNext()
{
    return _next;
}

inline void IntDoublyNode::SetNext(NodePtr node)
{
    _next = node;
}

inline IntDoublyNode::NodePtr IntDoublyNode::GetPrev()
{
    return _prev;
}

inline void IntDoublyNode::SetPrev(NodePtr node)
{
    _prev = node;
}

inline IntDoublyLinkedList::IntDoublyLinkedList()
{
    _head = nullptr;
    _last = nullptr;
}

inline size_t IntDoublyLinkedList::Size() const
{
    return _size;
}


inline void IntDoublyLinkedList::Append(ListNode& node)
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

inline void IntDoublyLinkedList::InsertAt(ListNode& node, size_t index)
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

inline void IntDoublyLinkedList::Remove(size_t index)
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

inline IntDoublyLinkedList::ListNode IntDoublyLinkedList::Search(int key)
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

inline void IntDoublyLinkedList::PrintDataValues() const
{
    if (_head != nullptr)
    {
        auto current = _head;
        while (current != nullptr)
        {
            printf("\nDoubly Linked Node value is %d", current->GetData());

            current = current->GetNext();
        }

        printf("\n");
    }
}

inline void IntDoublyLinkedList::incrementSize()
{
    _size++;
}

inline void IntDoublyLinkedList::decrementSize()
{
    _size--;
}

