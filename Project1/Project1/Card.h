#pragma once


enum class Shape : unsigned int 
{
	Spade = 0,
	Club = 1,
	Diamond = 2,
	Heart = 3,
};

enum class CardColor : unsigned int 
{
	Red = 0,
	Black = 1,
};

enum class FaceValue : unsigned int
{
	Ace = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
	Ten = 10,
	Jack = 11,
	Queen = 12,
	King = 13,
};

class Card
{
public:
	Card() {}
	Card(FaceValue fv, Shape sh, CardColor cc) : _face(fv), _shape(sh), _color(cc) {}

	const FaceValue* GetCardFaceValue() { return &_face; }
	const Shape* GetCardShape() { return &_shape; }
	const CardColor* GetCardColor() { return &_color; }

private:
	FaceValue _face;
	Shape _shape;
	CardColor _color;
};


class CardDeck
{
public:
	CardDeck() {}

private:
	Card _deck[52];
};