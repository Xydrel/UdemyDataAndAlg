#pragma once

#include <string>

namespace utests
{

class UnitTests
{
public:
	UnitTests();
	~UnitTests();

	std::string GetUserInputStringFromConsole();
	int GetUserInputIntFromConsole();

	void SetAndRunDesiredTests();
	bool AreAnyTestsEnabledForRun() const;

	void Run_StructureTests();
	void Run_EnabledTests();
	void Run_ArithmeticTests();
	void Run_RecursionTests();

private:
	bool _bShouldTestStructures = false;
	bool _bShouldTestArith = false;
	bool _bShouldTestRecursion = false;

};

} // end namespace utests

