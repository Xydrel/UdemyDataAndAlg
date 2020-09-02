#pragma once


//Includes---------------------------------------------------------------------

#include <memory>

//Types------------------------------------------------------------------------

//IntCircularNode
class IntCircularNode
{
public:
    using NodePtr = std::shared_ptr<IntCircularNode>;

    explicit IntCircularNode();
    ~IntCircularNode();
    //~IntCircularNode() = default; //disabled for destructor testing

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

//IntCircularLinkedList
class IntCircularLinkedList
{
public:
    using ListNode = std::shared_ptr<IntCircularNode>;

    explicit IntCircularLinkedList();
    ~IntCircularLinkedList() = default;

    IntCircularLinkedList(const IntCircularLinkedList& rhs) = delete;
    IntCircularLinkedList operator=(const IntCircularLinkedList& rhs) = delete;

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

//IntCircularNode
inline IntCircularNode::IntCircularNode()
{
    _data = -1;
    _next = nullptr;
    _prev = nullptr;
}

inline IntCircularNode::~IntCircularNode()
{
}

inline const int IntCircularNode::GetData() const
{
    return _data;
}

inline void IntCircularNode::SetData(const int data)
{
    _data = data;
}

inline IntCircularNode::NodePtr IntCircularNode::GetNext()
{
    return _next;
}

inline void IntCircularNode::SetNext(NodePtr node)
{
    _next = node;
}

inline IntCircularNode::NodePtr IntCircularNode::GetPrev()
{
    return _prev;
}

inline void IntCircularNode::SetPrev(NodePtr node)
{
    _prev = node;
}

inline IntCircularLinkedList::IntCircularLinkedList()
{
    _head = nullptr;
    _last = nullptr;
}

inline size_t IntCircularLinkedList::Size() const
{
    return _size;
}


inline void IntCircularLinkedList::Append(ListNode& node)
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

inline void IntCircularLinkedList::InsertAt(ListNode& node, size_t index)
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

inline void IntCircularLinkedList::Remove(size_t index)
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

inline IntCircularLinkedList::ListNode IntCircularLinkedList::Search(int key)
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

inline void IntCircularLinkedList::PrintDataValues() const
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

inline void IntCircularLinkedList::incrementSize()
{
    _size++;
}

inline void IntCircularLinkedList::decrementSize()
{
    _size--;
}



//Implementation---------------------------------------------------------------

