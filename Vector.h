#pragma once

template <typename V>
struct Vector2
{

	V x;
	V y;

	Vector2(){}
	Vector2(V _x ,V _y):x(_x),y(_y){}
	~Vector2()
	{
		x = 0;
		y = 0;
	}
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Vector2<double> Vector2d;