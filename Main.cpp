#include<iostream>
#include"Physic.h"

int main()
{

	si::Vector2f f(4, 5) ;
	si::Vector2f s(1,4);
	si::Vector2f n = s + f;
	std::cout << n.x << ' ' << n.y << std::endl;
	 f *= s;
	std::cout << f.x << ' ' << f.y << std::endl;

}