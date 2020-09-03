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
