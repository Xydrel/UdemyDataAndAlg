
#include <iostream>
#include <thread>
#include <chrono>


#include "Includes.h"

int main(void)
{
	int primesToTest = 500;
	arithtests::TestPrimeNumbers(primesToTest);
	arithtests::TestAdd(4, 2);
	arithtests::TestSub(4, 2);


	printf("press any key to initiate exit... ");
	// wait for the user to press a key
	getchar();

	printf("exit initiated...");
	// sleep a little to show the message
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	return 0;
}

