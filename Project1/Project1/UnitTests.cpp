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
	arithtests::TestPrimeNumbers(primesToTest);
	arithtests::TestAdd(4, 2);
	arithtests::TestSub(4, 2);

	printf("Enter a value for how many factorial terms to generate: ");
	arithtests::TestFactorialPrint(GetUserInputIntFromConsole());
	printf("Enter a base for the power of calculation: ");
	int base = GetUserInputIntFromConsole();
	printf("Enter a power to multiply to: ");
	int power = GetUserInputIntFromConsole();
	arithtests::TestPowerOf(base, power);
	arithtests::TestIterativePowerOf(base, power);
	//arithtests::TestFindSeatCount(15, 117); // function is on hold for now
	arithtests::TestRecursiveSum(5);
	arithtests::TestTaylorSeriesRecurs(4, 10);
	arithtests::TestTaylorSeriesIter(4, 10);
	arithtests::TestTaylorSeriesOrderNRecurse(4, 10);

	printf("Enter a numeric term to calculate Fibonacci series to: ");
	//std::string input = GetUserInputStringFromConsole();
	int input = GetUserInputIntFromConsole();
	arithtests::TestFibanacciIter(input);
	arithtests::TestFibanacciRecurse(input);
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