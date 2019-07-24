#pragma once

#include <algorithm>

#include <vector>

// forwards
void AscendDecendRecurse(std::vector<int>* a,
	std::vector<int>* b,
	const int val);
void CallingRecursePrint(int n);
void ReturningRecursePrint(int n);


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


