#pragma once

//Includes---------------------------------------------------------------------
#include "Array.h"

#include <vector>

//Implementation--------------------------------------------------------
template<typename T>
inline Array<T>::Array(size_t len) :
    _container(std::vector<T>()),
    _maxSize(len),
    _count(0)
{
    _container.reserve(len);
}

template<typename T>
inline size_t Array<T>::size() const
{
    return _container.size();
}

template<typename T>
inline size_t Array<T>::count() const
{
    return _count;
}

template<typename T>
inline T& Array<T>::at(const size_t index)
{
    auto result = _container[index];
    return result;
}


template<typename T>
inline void Array<T>::insertAt(T element, size_t index)
{
    _container[index] = element;
    _count += 1;
}

template<typename T>
inline void Array<T>::push_back(T element)
{
    if (_count <= _maxSize)
    {
        _count += 1;
        _container.push_back(element);
    }
}

template<typename T>
inline void Array<T>::pop_back()
{
    if (_count != 0)
    {
        _container.pop_back();
        _count -= 1;
    }
}

template<typename T>
inline T& Array<T>::search(T rhs)
{
    auto result = T();
    for (size_t i = 0; i < _container.size(); i++)
    {
        if (_container[i] == rhs)
        {
            result = _container[i];
            break;
        }
    }

    return result;
}
