#pragma once

namespace basicshapes
{

class Rectangle
{
public:
	Rectangle() {}
	Rectangle(float len, float br) : _length(len), _bredth(br) {}

	const float& GetRectArea() { return _length * _bredth; }
	const float& GetRectLength() { return _length; }
	const float& GetRectBredth() { return _bredth; }

	void SetRectLength(float len) { _length = len; }
	void SetRectBredth(float br) { _bredth = br; }

private:
	float _length;
	float _bredth;
};

}

