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

    SinglyLinkedNode<T>* GetHead();
    void SetHead(const SinglyLinkedNode<T>& head);

    SinglyLinkedNode<T>* GetNext();
    void SetNext(const SinglyLinkedNode<T>& next);

private:
    T _data;
    SinglyLinkedNode<T>* _head;
    SinglyLinkedNode<T>* _next;
};

template<typename T>
class DoublyLinkedNode
{
public:
    explicit DoublyLinkedNode(T& data);

    T* GetData();
    void SetData(const T& data);

    SinglyLinkedNode<T>* GetHead();
    void SetHead(const SinglyLinkedNode<T>& head);

    SinglyLinkedNode<T>* GetNext();
    void SetNext(const SinglyLinkedNode<T>& next);
    
    SinglyLinkedNode<T>* GetPrev();
    void SetPrev(const SinglyLinkedNode<T>& prev);

private:
    T _data;
    DoublyLinkedNode<T>* _head;
    DoublyLinkedNode<T>* _next;
    DoublyLinkedNode<T>* _prev;
};

class GenericLinkedList
{
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
inline SinglyLinkedNode<T>* SinglyLinkedNode<T>::GetHead()
{
    return _head;
}

template<typename T>
inline void SinglyLinkedNode<T>::SetHead(const SinglyLinkedNode<T>& head)
{
    head = _head;
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
inline SinglyLinkedNode<T>* DoublyLinkedNode<T>::GetHead()
{
    return _head;
}

template<typename T>
inline void DoublyLinkedNode<T>::SetHead(const SinglyLinkedNode<T>& head)
{
    _head = head;
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
