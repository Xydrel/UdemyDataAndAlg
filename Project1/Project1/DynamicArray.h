#pragma once

#include <vector>

template<typename T>
class DynamicArray
{
public:
	DynamicArray(const size_t size);
	DynamicArray() = delete;
	~DynamicArray() = default;

	void Push(const T& elem);
	void Pop();
	
	T& operator[](const size_t index);

	bool Contains(const T& elem) const;

private:
	std::vector<T> _container;
};

template<typename T>
inline DynamicArray<T>::DynamicArray(const size_t size)
{
	_container.reserve(size);
}

template<typename T>
inline void DynamicArray<T>::Push(const T& elem)
{
	_container.push_back(elem);
}

template<typename T>
inline void DynamicArray<T>::Pop()
{
	_container.pop_back();
}

template<typename T>
inline T& DynamicArray<T>::operator[](const size_t index)
{
	return _container[index];
}

template<typename T>
inline bool DynamicArray<T>::Contains(const T& elem) const
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
