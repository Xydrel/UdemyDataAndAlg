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
    printf("Should the Structure tests be run?: ");
    std::string userResponse = GetUserInputStringFromConsole();
    if (userResponse == "y" || userResponse == "Y")
    {
        _bShouldTestStructures = true;
    }

	printf("Should the Arith tests be run?: ");
	userResponse = "";
	userResponse = GetUserInputStringFromConsole();
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

bool UnitTests::AreAnyTestsEnabledForRun() const
{
	if (_bShouldTestStructures == true ||
		_bShouldTestArith == true ||
		_bShouldTestRecursion == true)
	{
		return true;
	}

	return false;
}

void UnitTests::Run_EnabledTests()
{
	if (_bShouldTestStructures)
	{
		Run_StructureTests();
	}

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
		printf("No tests were enabled for run...\n");
	}
}

void UnitTests::Run_StructureTests()
{
	StructTests::Run_ArrayConstructionTest();
	StructTests::Run_IntLinkedListTests();
	StructTests::Run_IntDoublyLinkedListTests();
	StructTests::Run_IntCircularLinkedListTests();
	StructTests::Run_IntStackLinkedListTests();
}

void UnitTests::Run_ArithmeticTests()
{
	printf("Enter a value for how many numbers to evaluate for prime: ");
	int primesToTest = GetUserInputIntFromConsole();
	mathtests::Test_PrimeNumbers(primesToTest);
	mathtests::Test_Add(4, 2);
	mathtests::Test_Sub(4, 2);

	printf("Enter a value for how many factorial terms to generate: ");
	mathtests::Test_FactorialPrint(GetUserInputIntFromConsole());

	printf("Enter a base for the power of calculation: ");
	int base = GetUserInputIntFromConsole();
	printf("Enter a power to multiply to: ");
	int power = GetUserInputIntFromConsole();
	mathtests::Test_PowerOf(base, power);
	mathtests::Test_IterativePowerOf(base, power);
	mathtests::Test_RecursiveSum(5);
	mathtests::Test_TaylorSeriesRecurs(4, 10);
	mathtests::Test_TaylorSeriesIter(4, 10);
	mathtests::Test_TaylorSeriesOrderNRecurse(4, 10);

	printf("Enter a numeric term to calculate Fibonacci series to: ");
	int input = GetUserInputIntFromConsole();
	mathtests::Test_FibanacciIter(input);
	mathtests::Test_FibanacciRecurse(input);

	printf("Enter values to test the Combination Formula method.\n");
	int n = GetUserInputIntFromConsole();
	int r = GetUserInputIntFromConsole();
	mathtests::Test_CombinationFormulaRecurse(n, r);
	mathtests::Test_NCRPascalsTriangle(n, r);

	printf("Enter a number of discs to move for the tower of Hanoi problem: ");
	n = GetUserInputIntFromConsole();
	mathtests::Test_TOH(n, 1, 2, 3);
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