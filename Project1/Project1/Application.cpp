
#include <iostream>
#include <thread>
#include <chrono>


#include "Includes.h"

static const bool bShouldTestArith = false;
static const bool bShouldTestRecursion = true;

void Run_EnabledTests();

void Run_ArithmeticTests();
void Run_RecursionTests();

int main(void)
{
	printf("Starting test runs...");
	Run_EnabledTests();

	printf("press any key to initiate exit... ");
	// wait for the user to press a key
	getchar();

	printf("exit initiated...");
	// sleep a little to show the message
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	return 0;
}

void Run_EnabledTests()
{
	if (bShouldTestArith)
	{
		Run_ArithmeticTests();
	}

	if (bShouldTestRecursion)
	{
		Run_RecursionTests();
	}

}

void Run_ArithmeticTests()
{
	int primesToTest = 500;
	arithtests::TestPrimeNumbers(primesToTest);
	arithtests::TestAdd(4, 2);
	arithtests::TestSub(4, 2);
	
	// expected: 24
	arithtests::TestFactorialsPrint(4);
	// expected: 16
	arithtests::TestPowerOf(2, 4);
	
	// add more as needed
}

void Run_RecursionTests()
{
	recursiontesting::Test_AscDesc();
	recursiontesting::Test_CallingPrint();
	recursiontesting::Test_TreeRecursionPrint();
	recursiontesting::Test_IndirectRecursion();
	recursiontesting::Test_NestedRecursion();
	recursiontesting::Test_RecursiveSum();
}
