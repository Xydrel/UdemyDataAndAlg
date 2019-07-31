#include "Core.h"
#include "2DShapes.h"

namespace primshapes
{

// -- Rectangle Implementation -- 
Rectangle2D::Rectangle2D()
{
	_length = 1;
	_bredth = 1;
}

const float * Rectangle2D::GetRectLength()
{
	return &_length;
}

const float * Rectangle2D::GetRectBredth()
{
	return &_bredth;
}

const float Rectangle2D::GetRectArea()
{
	return _length * _bredth;;
}

const float Rectangle2D::GetPerimeter()
{
	return 2 * (_length + _bredth);
}

void Rectangle2D::SetRectLength(float len)
{
	_length = len;
}

void Rectangle2D::SetRectBredth(float br)
{
	_bredth = br;
}

void Rectangle2D::ChangeRectLength(float newLen)
{
	_length = newLen;
}
// -- End Rectangle Implementation

// -- Circle Implementation -- 
Circle2D::Circle2D()
{
	_radius = 1.f;
	_SetCircleProperties();
}
Circle2D::Circle2D(double rad)
{
	_radius = rad;
	_SetCircleProperties();
}

void Circle2D::_SetCircleProperties()
{
	_dia = _radius + _radius;
	_circumfrence = 2 * mathconsts::pi * _radius;
	_area = _radius * _radius * mathconsts::pi;
}
// -- End Circle Implementation

} // end primshapes