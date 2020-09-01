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

//Inline Implementation--------------------------------------------------------
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
