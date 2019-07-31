#include "Core.h"
#include "2DShapes.h"

namespace primshapes
{

// -- Basic Shape Implementation --
Shape2D::Shape2D()
{
	_x = 0.f;
	_y = 0.f;
}

Shape2D::~Shape2D()
{
}
// -- End Basic Shape Implementation --

// -- Rectangle Implementation -- 
Rectangle2D::Rectangle2D()
{
	_length = 1;
	_bredth = 1;
}


Rectangle2D::~Rectangle2D()
{
}

const void Rectangle2D::SetX(double x)
{
	_x = x;
}

const void Rectangle2D::SetY(double y)
{
	_y = y;
}

const float* Rectangle2D::GetRectLength()
{
	return &_length;
}

const float* Rectangle2D::GetRectBredth()
{
	return &_bredth;
}

const float* Rectangle2D::GetRectArea()
{
	return &_area;
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

void Rectangle2D::_UpdateRectProperties()
{
	_area = _bredth * _length;
	_x = 0.f;
	_y = 0.f;
}

// -- End Rectangle Implementation

// -- Circle Implementation -- 
Circle2D::Circle2D()
{
	_radius = 1.f;
	_UpdateCircleProperties();
}

Circle2D::Circle2D(double rad)
{
	_radius = rad;
	_UpdateCircleProperties();
}

Circle2D::~Circle2D()
{
}

const void Circle2D::SetX(double x)
{
	_x = x;
}

const void Circle2D::SetY(double y)
{
	_y = y;
}

void Circle2D::SetCircleRadius(double newRad)
{
	_radius = newRad;
	_UpdateCircleProperties();
}

void Circle2D::_UpdateCircleProperties()
{
	assert(_radius > 0);
	_dia = _radius + _radius;
	_circumfrence = 2 * mathconsts::pi * _radius;
	_area = _radius * _radius * mathconsts::pi;
	_x = 0.f;
	_y = 0.f;
}
// -- End Circle Implementation



} // end primshapes