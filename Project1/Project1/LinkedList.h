#pragma once

//Includes---------------------------------------------------------------------

#include <memory>

//Types------------------------------------------------------------------------

//IntNode
class IntNode
{
public:
    using NodePtr = std::shared_ptr<IntNode>;

    explicit IntNode();
    ~IntNode();

    const int GetData() const;
    void SetData(const int data);

    NodePtr GetNext();
    void SetNext(NodePtr node);

private:
    int _data;
    NodePtr _next;
};

//IntLinkedList
class IntLinkedList
{
public:
    using ListNode = std::shared_ptr<IntNode>;

    explicit IntLinkedList();
    //~IntLinkedList() = default; //disabled for destructor testing

    IntLinkedList(const IntLinkedList& rhs) = delete;
    IntLinkedList operator=(const IntLinkedList& rhs) = delete;

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
