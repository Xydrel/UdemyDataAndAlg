#pragma once


//Includes---------------------------------------------------------------------

//Types-------------
template<typename T>
class SinglyLinkedNode
{
public:
    explicit SinglyLinkedNode(T& data);

    T* GetData();
    void SetData(const T& data);

    SinglyLinkedNode<T>* GetNext();
    void SetNext(const SinglyLinkedNode<T>& next);

private:
    T _data;
    std::unique_ptr<SinglyLinkedNode<T>> _next;
};

template<typename T>
class DoublyLinkedNode
{
public:
    explicit DoublyLinkedNode(T& data);

    T* GetData();
    void SetData(const T& data);

    SinglyLinkedNode<T>* GetNext();
    void SetNext(const SinglyLinkedNode<T>& next);
    
    SinglyLinkedNode<T>* GetPrev();
    void SetPrev(const SinglyLinkedNode<T>& prev);

private:
    T _data;
    std::unique_ptr<DoublyLinkedNode<T>> _next;
    std::unique_ptr<DoublyLinkedNode<T>> _prev;
};

template<typename T>
class SingleLinkedList
{
public:
    explicit SingleLinkedList() = default;

    void Insert(SinglyLinkedNode<T>& node);

private:
    std::unique_ptr<SinglyLinkedNode<T>> _head;
};

template<typename T>
class DoublyLinkedList
{
public:
    explicit DoublyLinkedList() = default;

private:
    std::unique_ptr<DoublyLinkedNode<T>> _head;
};

//Implementation---------------------------------------------------------------

//SinglyLinkedNode
template<typename T>
inline SinglyLinkedNode<T>::SinglyLinkedNode(T& data)
{
    _data = data;
}

template<typename T>
inline T* SinglyLinkedNode<T>::GetData()
{
    return _data;
}

template<typename T>
inline void SinglyLinkedNode<T>::SetData(const T& data)
{
    _data = data;
}

template<typename T>
inline SinglyLinkedNode<T>* SinglyLinkedNode<T>::GetNext()
{
    return _next;
}

template<typename T>
inline void SinglyLinkedNode<T>::SetNext(const SinglyLinkedNode<T>& next)
{
    _next = next;
}

//DoublyLinkedNode
template<typename T>
inline DoublyLinkedNode<T>::DoublyLinkedNode(T& data)
{
    _data = data;
}

template<typename T>
inline T* DoublyLinkedNode<T>::GetData()
{
    return _data;
}

template<typename T>
inline void DoublyLinkedNode<T>::SetData(const T& data)
{
    _data = data;
}

template<typename T>
inline SinglyLinkedNode<T>* DoublyLinkedNode<T>::GetNext()
{
    return _next;
}

template<typename T>
inline void DoublyLinkedNode<T>::SetNext(const SinglyLinkedNode<T>& next)
{
    _next = next;
}

template<typename T>
inline SinglyLinkedNode<T>* DoublyLinkedNode<T>::GetPrev()
{
    return _prev;
}

template<typename T>
inline void DoublyLinkedNode<T>::SetPrev(const SinglyLinkedNode<T>& prev)
{
    _prev = prev;
}

template<typename T>
inline void SingleLinkedList<T>::Insert(SinglyLinkedNode<T>& node)
{
    if (node != nullptr)
    {
        
    }
}
