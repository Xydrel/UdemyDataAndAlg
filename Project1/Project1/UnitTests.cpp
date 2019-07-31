#include <iostream>

#include "UnitTests.h"
#include "Includes.h"

namespace utests
{

UnitTests::UnitTests()
{
}

UnitTests::~UnitTests()
{
}

std::string UnitTests::GetUserInputStringFromConsole()
{
	std::string input;
	printf("Please enter a response y/n: ");
	getline(std::cin, input);

	return input;
}

int UnitTests::GetUserInputIntFromConsole()
{
	std::string input;
	printf("Please enter a value: ");
	getline(std::cin, input);

	return std::stoi(input);
}

void UnitTests::SetAndRunDesiredTests()
{
	printf("Should the Arith tests be run?: ");
	std::string userResponse = GetUserInputStringFromConsole();
	if (userResponse == "y" || userResponse == "Y")
	{
		_bShouldTestArith = true;
	}

	printf("should the recursive tests be run?: ");
	userResponse = "";
	userResponse = GetUserInputStringFromConsole();
	if (userResponse == "y" || userResponse == "Y")
	{
		_bShouldTestRecursion = true;
	}

	Run_EnabledTests();
}

bool UnitTests::AreAnyTestsEnabledForRun()
{
	if (_bShouldTestArith == true ||
		_bShouldTestRecursion == true)
	{
		return true;
	}

	return false;
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

	if (!AreAnyTestsEnabledForRun())
	{
		printf("\nNo tests were enabled for run...\n");
	}
}

void UnitTests::Run_ArithmeticTests()
{
	printf("Enter a value for how many numbers to evaluate for prime: ");
	int primesToTest = GetUserInputIntFromConsole();
	arithtests::Test_PrimeNumbers(primesToTest);
	arithtests::Test_Add(4, 2);
	arithtests::Test_Sub(4, 2);

	printf("Enter a value for how many factorial terms to generate: ");
	arithtests::Test_FactorialPrint(GetUserInputIntFromConsole());

	printf("Enter a base for the power of calculation: ");
	int base = GetUserInputIntFromConsole();
	printf("Enter a power to multiply to: ");
	int power = GetUserInputIntFromConsole();
	arithtests::Test_PowerOf(base, power);
	arithtests::Test_IterativePowerOf(base, power);
	arithtests::Test_RecursiveSum(5);
	arithtests::Test_TaylorSeriesRecurs(4, 10);
	arithtests::Test_TaylorSeriesIter(4, 10);
	arithtests::Test_TaylorSeriesOrderNRecurse(4, 10);

	printf("Enter a numeric term to calculate Fibonacci series to: ");
	int input = GetUserInputIntFromConsole();
	arithtests::Test_FibanacciIter(input);
	arithtests::Test_FibanacciRecurse(input);
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

} // end namespace utests