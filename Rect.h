#pragma once

template<typename R>
struct Rect
{

	si::Vector2<R> Position;
	si::Vector2<R> Size;

	Rect<R> operator +(Rect<R>);
	Rect<R> operator -(Rect<R>);
	Rect<R> operator *(Rect<R>);
	Rect<R> operator /(Rect<R>);
	Rect<R> operator +=(Rect<R>);
	Rect<R> operator -=(Rect<R>);
	Rect<R> operator *=(Rect<R>);
	Rect<R> operator /=(Rect<R>);

	Rect() {}
	Rect(si::Vector2<R> _position, si::Vector2<R> _size) :Position(_position), Size(_size) {}
	~Rect()
	{
		~Position();
		~Size();
	}

};

typedef Rect<float> Rectf;
typedef Rect<int> Recti;

template <typename R> Rect<R> Rect<R>::operator +(Rect<R> copy)
{
	return Rect<R>(this->Position + copy.Position, this->Size + copy.Size);
}

template <typename R> Rect<R> Rect<R>::operator -(Rect<R> copy)
{
	return Rect<R>(this->Position - copy.Position, this->Size - copy.Size);
}

template <typename R> Rect<R> Rect<R>::operator *(Rect<R> copy)
{
	return Rect<R>(this->Position * copy.Position, this->Size * copy.Size);
}

template <typename R> Rect<R> Rect<R>::operator /(Rect<R> copy)
{
	return Rect<R>(this->Position / copy.Position, this->Size / copy.Size);
}

template <typename R> Rect<R> Rect<R>::operator +=(Rect<R> copy)
{
	return Rect<R>(this->Position += copy.Position, this->Size += copy.Size);
}

template <typename R> Rect<R> Rect<R>::operator -=(Rect<R> copy)
{
	return Rect<R>(this->Position -= copy.Position, this->Size -= copy.Size);
}

template <typename R> Rect<R> Rect<R>::operator *=(Rect<R> copy)
{
	return Rect<R>(this->Position *= copy.Position, this->Size *= copy.Size);
}

template <typename R> Rect<R> Rect<R>::operator /=(Rect<R> copy)
{
	return Rect<R>(this->Position /= copy.Position, this->Size /= copy.Size);
}