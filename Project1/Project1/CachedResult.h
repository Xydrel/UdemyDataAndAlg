#pragma once

#include <iostream>
#include <unordered_map>
#include <functional>
#include <memory>


namespace CachedFunctions
{

class CachedFunction
{
public:
    class Parameters
    {
    public:
        Parameters(int first, int second) :
            _result(-1)
        {
            this->_first = first;
            this->_second = second;
        }

        size_t Hash() const
        {
            auto h1 = std::hash<int>()(_first);
            auto h2 = std::hash<int>()(_second);

            return h1 ^ h2;
        }

        int GetResult() { return _result; }
        void SetResult(const int& value) { _result = value; }

        void RunTests();

    private:
        int _first;
        int _second;
        int _result;
    };

public:
    CachedFunction(std::function<int(int, int)> function) : function(function) {}

    int calculate(int first, int second)
    {
        auto args = std::make_shared<Parameters>(first, second);
        auto it = calculations.find(args->Hash());
        if (it != calculations.end())
            return it->second->GetResult();

        int calculation = function(first, second);
        args->SetResult(calculation);
        calculations[args->Hash()] = args;
        return calculation;
    }

private:
    std::unordered_map<size_t, std::shared_ptr<Parameters>> calculations;
    std::function<int(int, int)> function;

};

int modulo(int a, int b)
{
    std::cout << "Function modulo has been called.\n";
    return a % b;
}

void CachedFunctions::CachedFunction::Parameters::RunTests()
{
    CachedFunction cache(modulo);

    // Function modulo should be called.
    std::cout << cache.calculate(5, 2) << std::endl;

    // Function modulo should be called.
    std::cout << cache.calculate(7, 4) << std::endl;

    // Function modulo shouldn't be called because we have already made a call with arguments (5, 2)!
    std::cout << cache.calculate(5, 2) << std::endl;

    std::cout << cache.calculate(500, 200) << std::endl;

    std::cout << cache.calculate(123, 256) << std::endl;

    std::cout << cache.calculate(122, 257) << std::endl;

    std::cout << cache.calculate(123, 256) << std::endl;

    std::cout << cache.calculate(50054, 2003453) << std::endl;

    std::cout << cache.calculate(123456, 256789) << std::endl;

    std::cout << cache.calculate(1223344, 257777) << std::endl;

    std::cout << cache.calculate(123, 256) << std::endl;

    std::cout << cache.calculate(123456, 256789) << std::endl;
}

}//End namespace CachedFunctions