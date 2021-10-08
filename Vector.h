#pragma once

template <typename V>
struct Vector2
{

	V x;
	V y;

	Vector2<V> operator +(Vector2<V>);
	Vector2<V> operator -(Vector2<V>);
	Vector2<V> operator *(Vector2<V>);
	Vector2<V> operator /(Vector2<V>);
	Vector2<V> operator +=(Vector2<V>);
	Vector2<V> operator -=(Vector2<V>);
	Vector2<V> operator *=(Vector2<V>);
	Vector2<V> operator /=(Vector2<V>);

	Vector2():x(V(0)), y(V(0)) {}
	Vector2(V _x ,V _y):x(_x),y(_y){}
	~Vector2()
	{
		x = 0;
		y = 0;
	}
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;

template <typename V> Vector2<V> Vector2<V>::operator +(Vector2<V> copy)
{
	return Vector2<V>(this->x + copy.x, this->y + copy.y);
}

template <typename V> Vector2<V> Vector2<V>::operator -(Vector2<V> copy)
{
	return Vector2<V>(this->x - copy.x, this->y - copy.y);
}

template <typename V> Vector2<V> Vector2<V>::operator *(Vector2<V> copy)
{
	return Vector2<V>(this->x * copy.x, this->y * copy.y);
}

template <typename V> Vector2<V> Vector2<V>::operator /(Vector2<V> copy)
{
	return Vector2<V>(this->x / copy.x, this->y / copy.y);
}

template <typename V> Vector2<V> Vector2<V>::operator +=(Vector2<V> copy)
{
	return Vector2<V>(this->x += copy.x, this->y += copy.y);
}

template <typename V> Vector2<V> Vector2<V>::operator -=(Vector2<V> copy)
{
	return Vector2<V>(this->x -= copy.x, this->y -= copy.y);
}

template <typename V> Vector2<V> Vector2<V>::operator *=(Vector2<V> copy)
{
	return Vector2<V>(this->x *= copy.x, this->y *= copy.y);
}

template <typename V> Vector2<V> Vector2<V>::operator /=(Vector2<V> copy)
{
	return Vector2<V>(this->x /= copy.x, this->y /= copy.y);
}