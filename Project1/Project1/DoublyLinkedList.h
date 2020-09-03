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