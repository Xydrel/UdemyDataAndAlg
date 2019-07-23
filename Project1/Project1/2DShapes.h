#pragma once

namespace basicshapes
{

class Rectangle
{
public:
	// ctors
	Rectangle() { _length = 1; _bredth = 1; }
	Rectangle(float len, float br) : _length(len), _bredth(br) {}

	// dtors
	~Rectangle() {}
	
	// accessors
	const float* GetRectLength() { return &_length; }
	const float* GetRectBredth() { return &_bredth; }

	// facilitators
	const float GetRectArea() { return _length * _bredth; }
	const float GetPerimeter() { return 2 * (_length + _bredth); }

	// mutators
	void SetRectLength(float len) { _length = len; }
	void SetRectBredth(float br) { _bredth = br; }
	void ChangeRectLength(float newLen) { _length = newLen; }

private:
	// members
	float _length;
	float _bredth;
};

}

