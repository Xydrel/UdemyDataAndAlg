#pragma once

//Includes---------------------------------------------------------------------
#include "Array.h"

//Implementation--------------------------------------------------------
template<typename T>
inline Array<T>::Array(size_t len) :
    _container(std::vector<T>()),
    _maxSize(len)
{
    _container.reserve(len);
}

template<typename T>
inline size_t Array<T>::Size() const
{
    return _container.size();
}

template<typename T>
inline T& Array<T>::At(const size_t index)
{
    auto result = _container[index];
    return result;
}


template<typename T>
inline void Array<T>::InsertAt(T element, size_t index)
{
    _container[index] = element;
}

template<typename T>
void Array<T>::Push(T element)
{
    _container.insert(element, 0);
}

template<typename T>
void Array<T>::Pop()
{
    _container.erase(_container.begin());
}

template<typename T>
inline void Array<T>::PushBack(T element)
{
    if (Size() <= _maxSize)
    {
        _container.push_back(element);
    }
}

template<typename T>
inline void Array<T>::PopBack()
{
    _container.pop_back();
}

template<typename T>
inline T& Array<T>::Search(T rhs)
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
