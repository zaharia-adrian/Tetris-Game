#include <iostream>
#include <SFML/Graphics.hpp>

#include "board/board.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tetris Game");

	Board b;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//if(event.type== sf::Event::)
		}

		window.clear(sf::Color(26, 26, 26, 255));

		b.new_piece();
		b.draw_board(window);
		
		window.display();
	}


	return 0;
}

