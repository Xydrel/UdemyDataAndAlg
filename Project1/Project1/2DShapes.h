#pragma once

namespace primshapes
{

class Rectangle2D
{
public:
	// ctors
	Rectangle2D();
	Rectangle2D(float len, float br) : _length(len), _bredth(br) {}

	// dtors
	~Rectangle2D() {}
	
	// accessors
	const float* GetRectLength();
	const float* GetRectBredth();
	const float* GetRectArea();
	const float GetPerimeter();

	// mutators
	void SetRectLength(float len);
	void SetRectBredth(float br);
	void ChangeRectLength(float newLen);

private:
	// methods
	void _UpdateRectProperties();

	// members
	float _length;
	float _bredth;
	float _area;
};

class Circle2D
{
public:
	// ctors
	Circle2D();
	Circle2D(double rad);

	// mutators
	void SetCircleRadius(double newRad);

private:
	// methods
	void _UpdateCircleProperties();

	// members
	double _radius;
	double _dia;
	double _circumfrence;
	double _area;
};



}

