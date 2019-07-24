#pragma once

#include <vector>
#include <algorithm>

template<class T>
class Arithmatic
{
public:
	Arithmatic<T>();
	Arithmatic(T a, T b);

	T Add();
	T Add(const T& lft, const T& rt);
	T Sub();
	T Sub(const T& lft, const T& rt);

	bool IsPrime(const T val);
	T Factorials(T nFactorials);
	T PowerOf(T n, T power);

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
inline T Arithmatic<T>::Add(const T& lft, const T& rt)
{
	return lft + rt;
}

template<class T>
T Arithmatic<T>::Sub()
{
	return _a - _b;
}

template<class T>
inline T Arithmatic<T>::Sub(const T& lft, const T& rt)
{
	return lft - rt;
}

template<class T>
bool Arithmatic<T>::IsPrime(const T val)
{
	// O(n) algorithm

	// n+1 operation
	for (int i = 2; i < val; ++i)
	{
		// constant 1 operation
		if (val % i == 0)
		{
			return false;
		}
	}

	return true;
}

template<class T>
T Arithmatic<T>::Factorials(T nFactorials)
{
	if (nFactorials > 1)
	{
		return nFactorials * Factorials(nFactorials - 1);
	}

	return 1;
}

template<class T>
inline T Arithmatic<T>::PowerOf(T n, T power)
{
	int res = 1;
	if (power >= 0)
	{
		res = PowerOf(n, power-1) * n;
	}

	return res;
}

namespace arithtests
{

template<class T>
void TestPrimeNumbers(const T primesToTest)
{
	// O(n^2) algorithm

	std::vector<T> primes;
	Arithmatic<T> ar;
	primes.reserve(primesToTest << 1);
	// n
	for (int i = 1; i < primesToTest; ++i)
	{
		bool res = false;
		// nxn times
		res = ar.IsPrime(i);

		if (res)
		{
			primes.push_back(i);
		}

		printf("| Is %d prime? %s%s", i, res ? "true" : "false", (i % 5 == 0) ? "\n" : " ");
	}

	if (primes.size() > 0)
	{
		printf("\n");
		printf("\n");
		printf("\n");
		// n times
		for (int i = 0; i < primes.size(); ++i)
		{
			printf("%d | %s", primes[i], (i != 0 && i % 10 == 0) ? "\n" : " ");
		}
		printf("\n");
		printf("\n");
	}
}

template<class T>
void TestAdd(const T lft, const T rt)
{
	Arithmatic<T> ar;
	T sum = ar.Add(lft, rt);
	printf("The sum of %d + %d = %d\n", lft, rt, sum);
}

template<class T>
void TestSub(const T lft, const T rt)
{
	Arithmatic<T> ar;
	T diff = ar.Sub(lft, rt);
	printf("The diff of %d - %d = %d\n", lft, rt, diff);
}

template<class T>
void TestFactorialsPrint(const T n)
{
	Arithmatic<T> ar;
	T res = ar.Factorials(n);
	printf("result of %d! =  %d\n", n, res);
}

template<class T>
void TestPowerOf(const T n, const T power)
{
	Arithmatic<T> ar;
	T res = ar.PowerOf(n, power);
	printf("%d to the power of %d = %d\n", n, power, res);
}

}
