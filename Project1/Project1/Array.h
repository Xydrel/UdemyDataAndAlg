#pragma once

#include <vector>

template<typename T>
class Array
{
public:
	Array(size_t size);
	~Array();

	void Push(T elem);
	void Pop();
	
	T operator[](size_t i);

	bool Contains(T elem);

private:
	std::vector<T> _container;
};

template<typename T>
inline Array<T>::Array(size_t size)
{
	_container.reserve(size);
}

template<typename T>
inline Array<T>::~Array()
{
}

template<typename T>
inline void Array<T>::Push(T elem)
{
	_container.push_back(elem);
}

template<typename T>
inline void Array<T>::Pop()
{
	_container.pop_back();
}

template<typename T>
inline T Array<T>::operator[](size_t i)
{
	return _container[i];
}

template<typename T>
inline bool Array<T>::Contains(T elem)
{
	if (_container.size() > 0)
	{
		for (size_t i = 0; i < _container.size(); i++)
		{
			if (_container[i] == elem)
			{
				return true;
			}
		}
	}
	return false;
}
