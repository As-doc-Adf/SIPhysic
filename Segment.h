#pragma once
#include<cmath>

class Segment
{
public:
	//Constructors & Destructor

	Segment();
	Segment(si::Vector2f, si::Vector2f);
	Segment(si::Vector2f, si::Vector2f, si::Vector2f);
	~Segment();

	//Get
	si::Vector2f getVector();
	si::Vector2f getPosition();
	float getLenght();

	//Set
	void setPosition(si::Vector2f);
	void setFirstPoint(si::Vector2f);
	void setSecondPoint(si::Vector2f);

	//Vector Math
	float angleBetweenVector(si::Segment segment);

	//Interactions
	void move(si::Vector2f);

	//Event
	bool contactPoint(si::Vector2f);
	friend bool collison(si::Segment first, si::Segment second);

private:
	
	//Vectors Math
	void findVector();
	float absVector(si::Vector2f);
	float multiplayVector(si::Vector2f,si::Vector2f);
	float length(si::Vector2f, si::Vector2f);

	//Function y=kx+b
	float findK(si::Vector2f&, si::Vector2f&);
	float findB(si::Vector2f&, float&);
	float findY(float);

	si::Vector2f GlobalPosition;
	si::Vector2f FPoint;
	si::Vector2f SPoint;
	si::Vector2f Vector;
	float k = 0;
	float b = 0;
	float _lenght = 0;
	float _rotate = 0;
	bool inf = false;
	
};
//Get & Set
si::Vector2f si::Segment::getVector()
{
	return Vector;
}
si::Vector2f si::Segment::getPosition()
{
	return FPoint;
}
float si::Segment::getLenght()
{
	return _lenght;
}

void si::Segment::setPosition(si::Vector2f newPos)
{
	SPoint += newPos - FPoint;
	FPoint = newPos;
}
void si::Segment::setFirstPoint(si::Vector2f Point)
{
	FPoint = Point;
}
void si::Segment::setSecondPoint(si::Vector2f Point)
{
	SPoint = Point;
}

//Interactions
void si::Segment::move(si::Vector2f speed)
{
	SPoint += speed;
	FPoint += speed;
}

//Event
bool si::Segment::contactPoint(si::Vector2f point)
{

	if (inf && point.x >= this->getPosition().x-0.001 && point.x <= this->getPosition().x + 0.001)
	{
		return true;
	}
	else
	{
		if (point.y <= (k * point.x + b) + 0.001f && point.y >= (k * point.x + b) - 0.001f)
		{
			return true;
		}
		return true;
	}

	return false;
}

//Vectors Math
void si::Segment::findVector()
{
	Vector = SPoint - FPoint;
}
float si::Segment::absVector(si::Vector2f _Vector)
{
	return sqrt(powf(_Vector.x, 2) + powf(_Vector.y, 2));
}
float si::Segment::multiplayVector(si::Vector2f _FVector , si::Vector2f _SVector)
{
	return _FVector.x * _SVector.x + _FVector.y * _SVector.y;
}
float si::Segment::angleBetweenVector(si::Segment segment)
{
	return multiplayVector(segment.getVector(),Vector) / (absVector(Vector) * absVector(segment.getVector()));
}
float si::Segment::length(si::Vector2f APoint, si::Vector2f BPoint)
{
	return sqrt(powf((BPoint.x - APoint.x), 2) + powf((BPoint.y - APoint.y), 2));
}

//Function y=kx+b

float si::Segment::findY(float x)
{
		return k * x + b;
}
float si::Segment::findK(si::Vector2f &xy0, si::Vector2f &xy1)
{
	if ((xy0.x - xy1.x) == 0) { return 0; }
	return (xy0.y - xy1.y) / (xy0.x - xy1.x);
}
float si::Segment::findB(si::Vector2f &xy0, float &k)
{
	return xy0.y - k * xy0.x;
}

//Constructors & Destructor

si::Segment::Segment(si::Vector2f _First, si::Vector2f _Second):FPoint(_First),SPoint(_Second),GlobalPosition(_First)
{
	if (FPoint.x == SPoint.x)
	{
		inf = true;
		_lenght = abs(SPoint.y - FPoint.y);
	}
	else
	{
		_lenght = length(FPoint, SPoint);
		inf = false;
		k = findK(FPoint, SPoint);
		b = findB(FPoint, k);
		if (_First.x > _Second.x)
		{
			FPoint = _Second;
			SPoint = _First;
		}
	}
}
si::Segment::Segment(si::Vector2f _First, si::Vector2f _Second,si::Vector2f _GlobalPosition): FPoint(_First), SPoint(_Second),GlobalPosition(_GlobalPosition)
{
	if (FPoint.x == SPoint.x)
	{
		inf = true;
		_lenght = abs(SPoint.y - FPoint.y);
	}
	else
	{
		_lenght = length(FPoint, SPoint);
		inf = false;
		k = findK(FPoint, SPoint);
		b = findB(FPoint, k);
		if (_First.x > _Second.x)
		{
			FPoint = _Second;
			SPoint = _First;
		}
	}
}
si::Segment::Segment()
{

}
si::Segment::~Segment()
{
	k = 0;
	b = 0;
	_lenght = 0;
	_rotate = 0;
	inf = false;
}