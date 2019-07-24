
#include <iostream>
#include <thread>
#include <chrono>


#include "UnitTests.h"

void StartUnitTests();

int main(void)
{
	printf("Starting test runs...");
	StartUnitTests();

	printf("press any key to initiate exit... ");
	// wait for the user to press a key
	getchar();

	printf("exit initiated...");
	// sleep a little to show the message
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	return 0;
}

void StartUnitTests()
{
	UnitTests ut;
	ut.Run_EnabledTests();
}
