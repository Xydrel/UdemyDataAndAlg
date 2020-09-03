#pragma once

//Includes---------------------------------------------------------------------
#include <vector>

//Types------------------------------------------------------------------------
template<typename T>
class Array
{
public:
    explicit Array<T>(size_t len);

    size_t size() const;
    size_t count() const;
    T& at(const size_t index);

    const T& operator[] (const size_t index) const { return _container[index]; }

    void insertAt(T element, size_t index);

    void push_back(T element);

    void pop_back();

    T& search(T rhs);

private:
    std::vector<T> _container;
    size_t _maxSize;
    size_t _count;
};
