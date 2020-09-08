#pragma once

//Includes---------------------------------------------------------------------
#include <vector>

//Types------------------------------------------------------------------------
template<typename T>
class Array
{
public:
    explicit Array<T>(size_t len);
    ~Array<T>() {}

    size_t Size() const;
    T& At(const size_t index);

    const T& operator[] (const size_t index) const { return _container[index]; }

    void InsertAt(T element, size_t index);

    void Push(T element);
    void Pop();

    void PushBack(T element);
    void PopBack();

    T& Search(T rhs);

private:
    std::vector<T> _container;
    size_t _maxSize;
};
