#pragma once

template<class T>
class Arithmatic
{
public:
	Arithmatic<T>();
	Arithmatic(T a, T b);

	T Add();
	T Sub();

private:
	T _a;
	T _b;

};

template<class T>
Arithmatic<T>::Arithmatic()
{
	this->_a = 0;
	this->_b = 0;
}

template<class T>
Arithmatic<T>::Arithmatic(T a, T b)
{
	this->_a = a;
	this->_b = b;
}

template<class T>
T Arithmatic<T>::Add()
{
	return _a + _b;
}

template<class T>
T Arithmatic<T>::Sub()
{
	return _a - _b;
}