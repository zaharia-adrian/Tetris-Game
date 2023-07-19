#include <iostream>
#include<random>

#include <SFML/Graphics.hpp>
#include <thread>
using namespace std;

const float margin_top = 50;
const float margin_left = 200;
const float square_size = 25.f;
const float gap = 5.f;

const int nr_row = 30;
const int nr_col = 20;

extern int Pieces[8][4][4][4];
extern int offset[8][4][4];


class Board {
	int score;
	int period;
	bool playing;

	int piece,orientation;
	int offset_row, offset_col;
	int board[nr_row+1][nr_col+1];

	void move_row(int row, int nr_rows);
	bool row_is_full(int row);
	void verify();
public:
	Board();

	void draw_board(sf::RenderWindow& window,sf::Font);

	void play();

	void move_rigth();
	void move_left();
	void rotate_ccw();
	void rotate_cw();
	void drop();
};