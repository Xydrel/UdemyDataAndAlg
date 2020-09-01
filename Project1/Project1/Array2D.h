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

//implement dynamic 2d vector


//Implementation---------------------------------------------------------------

template<typename T>
inline Array2D<T>::Array2D(size_t depth, size_t bredth) :
    _2dContainer(std::vector<std::vector<T>>()),
    _depth(depth),
    _bredth(bredth)
{
    _2dContainer.reserve(_bredth);
}



