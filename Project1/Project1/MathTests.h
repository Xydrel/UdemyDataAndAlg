#pragma once

#include <vector>
#include <algorithm>

template<class T>
class MathTests
{
public:
	MathTests<T>();
	MathTests(T a, T b);

	T Add();
	T Add(const T& lft, const T& rt);
	T Sub();
	T Sub(const T& lft, const T& rt);
	T Sum(const T n);

	bool IsPrime(const T val);
	T Factorial(T n);
	T IterFactorial(T n);
	T Pow(T n, T power);
	T IterPow(T n, T power);
	void NPrimes(T n, T i, std::vector<T>* primes);
	double TaylorSeriesRecursive(int x, int n);
	double TaylorSeriesOrderNIterative(double x, double n);
	double TaylorSeriesOrderNRecurse(double x, double n);
	uint64_t FibonacciSeriesIter(int n);
	int64_t FibonacciSeriesRecursive(int n);
	T CombinationFormulaRecursive(T n, T r);
	T NCRPsacalsTriangle(T n, T r);
	T nCr(T n, T r);
	void TOH(int n, int t1, int t2, int t3);

private:
	T _a;
	T _b;

};

template<class T>
MathTests<T>::MathTests()
{
	this->_a = 0;
	this->_b = 0;
}

template<class T>
MathTests<T>::MathTests(T a, T b)
{
	this->_a = a;
	this->_b = b;
}

template<class T>
T MathTests<T>::Add()
{
	return _a + _b;
}

template<class T>
inline T MathTests<T>::Add(const T& lft, const T& rt)
{
	return lft + rt;
}

template<class T>
T MathTests<T>::Sub()
{
	return _a - _b;
}

template<class T>
inline T MathTests<T>::Sub(const T& lft, const T& rt)
{
	return lft - rt;
}

template<class T>
inline T MathTests<T>::Sum(const T n)
{
	if (n > 0)
	{
		return Sum(n-1) + n;
	}
	return 0;
}

template<class T>
bool MathTests<T>::IsPrime(const T val)
{
	// O(n) algorithm

	// n times operation
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
T MathTests<T>::Factorial(T n)
{
	if(n <= 0)
	{
		return 1;
	}
	return Factorial(n - 1) * n;
		
}

template<class T>
inline T MathTests<T>::IterFactorial(T n)
{
	T product = 1;
	while (n > 0)
	{
		product *= n;
		--n;
	}

	return product;
}

template<class T>
inline T MathTests<T>::Pow(T n, T power)
{
	if(power == 0)
	{
		return 1;
	}
	if (power % 2 == 0)
	{
		return Pow(n*n, power / 2);
	}
	return n * Pow(n*n, (power - 1) / 2);
}

template<class T>
inline T MathTests<T>::IterPow(T n, T power)
{
	if (power == 0)
		return 1;

	T result = 1;
	while (power > 0)
	{
		result *= n;
		--power;
		/*if (power % 2 == 0)
		{
			result = result * result;
			power /= 2;
		}
		else
		{
			result = result * result * n;
			power = (power - 1) / 2;
		}*/
	}

	return result;
}

// TODO: This method is not actually being tested at this time.
template<class T>
inline void MathTests<T>::NPrimes(T n, T i, std::vector<T>* primes)
{
	if (primes->size() < n)
	{
		if (i > 0 && i == 1 || i == 2)
		{
			primes->push_back(i);
		}		
		else if (IsPrime(i))
		{
			primes->push_back(i);
		}
		NPrimes(n, i+1, primes);
	}

	return;
}

inline double MathTests<double>::TaylorSeriesRecursive(int x, int n)
{
	static double p = 1, f = 1;
	double res;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		res = TaylorSeriesRecursive(x, n - 1);
		p = p * x;
		f = f * n;
		return res + p / f;
	}
}

template<class T>
inline double MathTests<T>::TaylorSeriesOrderNIterative(double x, double n)
{
	double s = 1.0f;
	for (; n > 0; n--)
	{
		//s = 1.0f + (((double)x / (double)n) * (double)s);
		s = 1.0f + ((x / n) * s);
	}

	return s;
}

template<class T>
inline double MathTests<T>::TaylorSeriesOrderNRecurse(double x, double n)
{
	static double s = 1.0f;
	if (n > 0)
	{
		s = 1.0f + ((x / n) * s);
		return TaylorSeriesOrderNRecurse(x, n - 1);
	}
	return s;
}

template<class T>
inline uint64_t MathTests<T>::FibonacciSeriesIter(int n)
{
	if (n <= 1)
	{
		return n;
	}

	uint64_t sum = 0;
	uint64_t lastTerm = 1;
	int i = 1;
	for (; i <= n; i++)
	{
		uint64_t prevSum = sum;
		sum = lastTerm + sum;
		lastTerm = prevSum;
	}

	return sum;
}

template<class T>
inline int64_t MathTests<T>::FibonacciSeriesRecursive(int n)
{
	static std::vector<int64_t> arr(n+1, -1);

	if (n <= 1)
	{
		return n;
	}
	else
	{
		if (arr[n - 2] == -1)
		{
			arr[n - 2] = FibonacciSeriesRecursive(n - 2);	
		}
		if (arr[n - 1] == -1)
		{
			arr[n - 1] = FibonacciSeriesRecursive(n - 1);
		}
	}

	return FibonacciSeriesRecursive(n-2) + FibonacciSeriesRecursive(n-1);
}

template<class T>
inline T MathTests<T>::CombinationFormulaRecursive(T n, T r)
{
	// nCr = n!/r!(n-r)!

	T t1, t2, t3;
	t1 = Factorial(n);
	t2 = Factorial(r);
	t3 = Factorial(n - r);
	return t1 /(T)(t2*t3);
}

template<class T>
inline T MathTests<T>::NCRPsacalsTriangle(T n, T r)
{
	if (r == 0 || n == r)
	{
		return 1;
	}
	return NCRPsacalsTriangle(n - 1, r - 1) + NCRPsacalsTriangle(n - 1, r);
}

template<class T>
inline T MathTests<T>::nCr(T n, T r)
{
	// nCr = n!/r!(n-r)!
	T num, denom;

	num = Factorial(n);
	denom = Factorial(r) * (long double)Factorial(n - r);

	return num.denom;
}

template<class T>
inline void MathTests<T>::TOH(int n, int t1, int t2, int t3)
{
	if (n > 0)
	{
		TOH(n - 1, t1, t3, t2);
		printf("from %d to %d\n", t1, t3);
		TOH(n - 1, t2, t1, t3);
	}
}

namespace mathtests
{

template<class T>
void Test_PrimeNumbers(const T primesToTest)
{
	// O(n^2) algorithm

	std::vector<T> primes;
	MathTests<T> ar;
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
void Test_Add(const T lft, const T rt)
{
	MathTests<T> ar;
	T sum = ar.Add(lft, rt);
	printf("The sum of %d + %d = %d\n", lft, rt, sum);
}

template<class T>
void Test_Sub(const T lft, const T rt)
{
	MathTests<T> ar;
	T diff = ar.Sub(lft, rt);
	printf("The diff of %d - %d = %d\n", lft, rt, diff);
}

template<class T>
void Test_FactorialPrint(const T n)
{
	MathTests<T> ar;
	T res = ar.Factorial(n);
	printf("result of %d! =  %d\n", n, res);
	T iterRes = ar.IterFactorial(n);
	printf("result of iterative %d! =  %d\n", n, iterRes);
}

template<class T>
void Test_PowerOf(const T n, const T power)
{
	MathTests<T> ar;
	T res = ar.Pow(n, power);
	printf("%d to the power of %d = %d\n", n, power, res);
}

template<class T>
void Test_IterativePowerOf(const T n, const T power)
{
	MathTests<T> ar;
	T res = ar.IterPow(n, power);
	printf("%d to the power of %d = %d\n", n, power, res);
}

template<class T>
void Test_RecursiveSum(const T n)
{
	MathTests<T> ar;
	T res = ar.Sum(n);
	printf("result of summation to %d = %d\n", n, res);
}

void Test_TaylorSeriesRecurs(const int x, const int n)
{
	MathTests<double> ar;
	double res = ar.TaylorSeriesRecursive(x, n);
	printf("result of taylor series calculation for x = %d and n = %d is %lf\n", x, n, res);
}

void Test_TaylorSeriesIter(const int x, const int n)
{
	MathTests<double> ar;
	double res = ar.TaylorSeriesOrderNIterative(x, n);
	printf("result of taylor series O(n) iterative calculation for x = %d and n = %d is %lf\n", x, n, res);
}

void Test_TaylorSeriesOrderNRecurse(const int x, const int n)
{
	MathTests<double> ar;
	double res = ar.TaylorSeriesOrderNRecurse(x, n);
	printf("result of taylor series O(n) recursive calculation for x = %d and n = %d is %lf\n", x, n, res);
}

void Test_FibanacciIter(const int n)
{
	MathTests<double> ar;
	uint64_t res = ar.FibonacciSeriesIter(n);
	printf("result Fibonacci series iterative to %d term = %llu\n", n, (unsigned long long)res);
}

void Test_FibanacciRecurse(const int n)
{
	MathTests<double> ar;
	uint64_t res = ar.FibonacciSeriesRecursive(n);
	printf("result Fibonacci series recursive to %d term = %llu\n", n, (unsigned long long)res);
}

template<class T>
void Test_CombinationFormulaRecurse(const T n, const T r)
{
	MathTests<T> ar;
	T res = ar.CombinationFormulaRecursive(n, r);
	printf("result Combination formula with terms n = %llu and r =  %llu and res = %llu\n", 
		(unsigned long long)n, 
		(unsigned long long)r, 
		(unsigned long long)res);
}

template<class T>
void Test_NCRPascalsTriangle(const T n, const T r)
{
	MathTests<T> ar;
	T res = ar.NCRPsacalsTriangle(n, r);
	printf("result NCR with using Pascal's Triangle with terms n = %llu and r =  %llu and res = %llu\n",
		(unsigned long long)n,
		(unsigned long long)r,
		(unsigned long long)res);
}

void Test_TOH(int n, int t1, int t2, int t3)
{
	MathTests<int> ar;
	ar.TOH(n, t1, t2, t3);
}

int f(int &x, int c)

{

	c = c - 1;

	if (c == 0) return 1;

	x = x + 1;

	return f(x, c) * x;

}

}
