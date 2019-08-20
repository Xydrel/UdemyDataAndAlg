#pragma once

#include <vector>

template<typename T>
class Array
{
public:
	Array(const size_t size);
	~Array();

	void Push(const T& elem);
	void Pop();
	
	T& operator[](const size_t index);

	bool Contains(const T& elem) const;

private:
	std::vector<T> _container;
};

template<typename T>
inline Array<T>::Array(const size_t size)
{
	_container.reserve(size);
}

template<typename T>
inline Array<T>::~Array()
{
}

template<typename T>
inline void Array<T>::Push(const T& elem)
{
	_container.push_back(elem);
}

template<typename T>
inline void Array<T>::Pop()
{
	_container.pop_back();
}

template<typename T>
inline T& Array<T>::operator[](const size_t index)
{
	return _container[index];
}

template<typename T>
inline bool Array<T>::Contains(const T& elem) const
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
