#include<iostream>
#include"Physic.h"
#include<SFML/Graphics.hpp>

int main()
{

	sf::Event evn;
	sf::RenderWindow win(sf::VideoMode(1280, 720), "SIPhysic");
	win.setFramerateLimit(75);

	while (win.isOpen())
	{

		while (win.pollEvent(evn))
		{

			switch (evn.type)
			{
			case sf::Event::Closed:
				win.close();
				break;

			default:
				break;
			}

		}
		std::cout << si::collison(si::Segment(si::Vector2f(0, 0), si::Vector2f(1, 1)), si::Segment(si::Vector2f(2, 2), si::Vector2f(3, 6))) << std::endl;
		win.clear();

		win.display();

	}

}