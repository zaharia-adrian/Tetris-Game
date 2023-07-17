#include <iostream>
#include <SFML/Graphics.hpp>

#include "board/board.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tetris Game");
	sf::Font f;
	f.loadFromFile("res/Fonts/Century.TTF");

	Board b;
	b.play();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Left:
					b.move_left();
					break;
				case sf::Keyboard::Right:
					b.move_rigth();
					break;
				case sf::Keyboard::Up:
					b.rotate_cw();
					break;
				case sf::Keyboard::Down:
					b.rotate_ccw();
					break;
				case sf::Keyboard::Space:
					b.drop();
					break;
				default:
					break;
				}
			}
		}

		window.clear(sf::Color(26, 26, 26, 255));
	
		b.draw_board(window,f);

		window.display();
	}
	return 0;
}

