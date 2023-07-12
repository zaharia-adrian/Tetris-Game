#include <iostream>
#include <SFML/Graphics.hpp>
#include<cstdlib>
using namespace std;

const float margin_top = 100;
const float margin_left = 200;
const float square_size = 50.f;
const float gap = 7.f;

const int nr_row = 15;
const int nr_col = 14;


class Board {
	int board[100][100];

public:
	void draw_board(sf::RenderWindow& window);

	void move_row(int row, int nr_rows);

	bool row_is_full(int row);

	void new_piece();

};