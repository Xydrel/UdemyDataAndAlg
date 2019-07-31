#pragma once

namespace primshapes
{

	class Shape2D
	{
	public:
		// ctors
		Shape2D();
		Shape2D(double x, double y) : _x(x), _y(y) {};

		// dtors
		~Shape2D();

	// pure virtuals
	virtual const void SetX(double x) = 0;
	virtual const void SetY(double y) = 0;

protected:
	double _x;
	double _y;

private:

};

class Rectangle2D : public Shape2D
{
public:
	// ctors
	Rectangle2D();
	Rectangle2D(float len, float br) : _length(len), _bredth(br) {}

	// dtors
	~Rectangle2D();

	// Shape2D
	const void SetX(double x) override;
	const void SetY(double y) override;
	// End Shape2D
	
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

class Circle2D : public Shape2D
{
public:
	// ctors
	Circle2D();
	Circle2D(double rad);

	// dtors
	~Circle2D();

	// Shape2D
	const void SetX(double x) override;
	const void SetY(double y) override;
	// End Shape2D

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

