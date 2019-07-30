#pragma once

#include <algorithm>

#include <vector>

// forwards
void AscendDecendRecurse(std::vector<int>* a,
	std::vector<int>* b,
	const int val);
void CallingRecursePrint(int n);
void ReturningRecursePrint(int n);
void TreeRecursionPrint(int n, int& functCallCnt);
void IndirectARecursionPrint(int n);
void IndirectBRecursionPrint(int n);
int NestedRecursionPrint(int n);
int RecursiveSum(int n);


namespace recursiontesting
{

void Test_AscDesc()
{
	int loopCount = 8;
	std::vector<int> a;
	a.reserve(loopCount);
	std::vector<int> b;
	b.reserve(loopCount);
	AscendDecendRecurse(&a, &b, loopCount);
	
	printf("\nPrinting calling vector:   ");
	for (auto item : a)
	{
		printf("%d ", item);
	}
	printf("\nPrinting returning vector: ");
	for (auto item : b)
	{
		printf("%d ", item);
	}
	printf("\n");
}

void Test_CallingPrint()
{
	int loopCnt = 3;
	printf("\nloopCnt = %d", loopCnt);
	printf("\nTesting printing in recursion calling\n");
	CallingRecursePrint(loopCnt);
	printf("\n");
	ReturningRecursePrint(loopCnt);
	printf("\n");
}

void Test_TreeRecursionPrint()
{
	int cnt = 3;
	printf("\ndepth count = %d\n", cnt);
	int functCallCnt = 0;
	TreeRecursionPrint(cnt, functCallCnt);
	printf("\nfunct call cnt = %d\n", functCallCnt);
}

void Test_IndirectRecursion()
{
	int num = 20;
	printf("\nStating indirect recursion test with value %d\n", num);
	IndirectARecursionPrint(num);
	printf("\n");
}

void Test_NestedRecursion()
{
	int num = 95;
	printf("\nStating nested recursion test with value %d\n", num);
	int res = NestedRecursionPrint(num);
	printf("Result of the nested function recursive call with %d = %d\n", num, res);
	printf("\n");
}

void Test_RecursiveSum()
{
	int num = 5;
	printf("\nStating recursive sum test with value %d\n", num);
	int res = RecursiveSum(num);
	printf("Result of the recursive sum function call with %d = %d\n", num, res);
	printf("\n");
}

} // end namespace recursiontesting

void AscendDecendRecurse(std::vector<int>* a, 
					  std::vector<int>* b, 
					  const int val = 0)
{
	if (val > 0)
	{
		a->push_back(val);
		AscendDecendRecurse(a, b, val - 1);
		b->push_back(val);
	}
}

void CallingRecursePrint(int n)
{
	if (n > 0)
	{
		printf("%d ", n);
		CallingRecursePrint(n - 1);
	}
}

inline void ReturningRecursePrint(int n)
{
	if (n > 0)
	{
		ReturningRecursePrint(n - 1);
		printf("%d ", n);
	}
}

inline void TreeRecursionPrint(int n, int& functCallCnt)
{
	functCallCnt++;
	if (n > 0)
	{
		printf("%d ", n);
		TreeRecursionPrint(n - 1, functCallCnt);
		TreeRecursionPrint(n - 1, functCallCnt);
	}
}

inline void IndirectARecursionPrint(int n)
{
	if (n > 0)
	{
		printf("%d ", n);
		IndirectBRecursionPrint(n - 1);
	}
}

inline void IndirectBRecursionPrint(int n)
{
	if (n > 1)
	{
		printf("%d ", n);
		IndirectARecursionPrint(n / 2);
	}
}

inline int NestedRecursionPrint(int n)
{
	if (n > 100)
	{
		return n - 10;
	}
	return NestedRecursionPrint(NestedRecursionPrint(n + 11));
}

inline int RecursiveSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return RecursiveSum(n - 1) + n;
}

