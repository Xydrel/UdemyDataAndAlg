#pragma once

//Includes---------------------------------------------------------------------
#include <vector>

//Types------------------------------------------------------------------------
template<typename T>
class Array2D
{
public:
    explicit Array2D<T>(size_t depth, size_t bredth);
    ~Array2D<T>() = default;


private:
    std::vector<std::vector<T>> _2dContainer;
    size_t _depth;
    size_t _bredth;
};



