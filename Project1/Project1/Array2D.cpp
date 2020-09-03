#pragma once

//Includes---------------------------------------------------------------------
#include "Array2D.h"

#include <vector>


//Implementation---------------------------------------------------------------

template<typename T>
Array2D<T>::Array2D(size_t depth, size_t bredth) :
    _2dContainer(std::vector<std::vector<T>>()),
    _depth(depth),
    _bredth(bredth)
{
    _2dContainer.reserve(_bredth);
}



