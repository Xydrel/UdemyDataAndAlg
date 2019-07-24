#pragma once

#include "Includes.h"


class UnitTests
{
public:
	UnitTests();
	~UnitTests();

	void Run_EnabledTests();
	void Run_ArithmeticTests();
	void Run_RecursionTests();

private:
	static const bool _bShouldTestArith = true;
	static const bool _bShouldTestRecursion = false;

};

inline UnitTests::UnitTests()
{
}

inline UnitTests::~UnitTests()
{
}

void UnitTests::Run_EnabledTests()
{
	if (_bShouldTestArith)
	{
		Run_ArithmeticTests();
	}

	if (_bShouldTestRecursion)
	{
		Run_RecursionTests();
	}

}

void UnitTests::Run_ArithmeticTests()
{
	int primesToTest = 500;
	arithtests::TestPrimeNumbers(primesToTest);
	arithtests::TestAdd(4, 2);
	arithtests::TestSub(4, 2);

	arithtests::TestFactorialPrint(5);
	arithtests::TestPowerOf(3, 3);
}

void UnitTests::Run_RecursionTests()
{
	recursiontesting::Test_AscDesc();
	recursiontesting::Test_CallingPrint();
	recursiontesting::Test_TreeRecursionPrint();
	recursiontesting::Test_IndirectRecursion();
	recursiontesting::Test_NestedRecursion();
	recursiontesting::Test_RecursiveSum();
}