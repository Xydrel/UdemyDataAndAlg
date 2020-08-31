#pragma once

//Includes---------------------------------------------------------------------


//Constants--------------------------------------------------------------------
constexpr size_t defaultContianerSize = 8; //8*sizeof(T) bytes for starting data structure

//Types------------------------------------------------------------------------
template<typename T>
class Array
{
public:
    explicit Array<T>(size_t len);

    size_t size() const;
    size_t count() const;

    T& operator[] (size_t index);

    void insert(T element);
    //void insertAt(T element, size_t index);

    void push_back(T element);

    void pop_back();

private:
    T* _container;
    size_t _maxSize;
    size_t _count;
};

//Inline Implementation--------------------------------------------------------
template<typename T>
inline Array<T>::Array(size_t len) :
    _container(new T[len]),
    _maxSize(len),
    _count(0)
{
}

template<typename T>
inline size_t Array<T>::size() const
{
    //return sizeof(_container) / sizeof(T);
    return _maxSize;
}

template<typename T>
inline size_t Array<T>::count() const
{
    return _count;
}

template<typename T>
inline T& Array<T>::operator[](size_t index)
{
    return _container[index];
}

template<typename T>
inline void Array<T>::insert(T element)
{
    
}

template<typename T>
inline void Array<T>::push_back(T element)
{
    if (_count <= _maxSize)
    {
        _count += 1;
        _container[_count] = element;
    }
}

template<typename T>
inline void Array<T>::pop_back()
{
    if (_count != 0)
    {
        //just lower the count so the data will be over-written as that's more performant
        _count -= 1;
    }
}
