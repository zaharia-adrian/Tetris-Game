#include "board.h"


int Pieces[8][4][4][4] = {
		{/// 1st piece in all 4 forms
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{0,1,1,0},
				{0,0,0,0}
			},
		},
		{/// 2nd piece in all 4 forms
			{
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,0,1,0},
				{0,0,1,0},
				{0,0,1,0},
				{0,0,1,0}
			},
			{
				{0,0,0,0},
				{0,0,0,0},
				{1,1,1,1},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,1,0,0}
			},
		},
		{/// 3th piece in all 4 forms
			{
				{1,0,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,1,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{0,0,1,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{1,1,0,0},
				{0,0,0,0}
			},
		},
		{///4th piece with all 4 forms
			{
				{0,0,1,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,0,0},
				{0,1,1,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{1,0,0,0},
				{0,0,0,0}
			},
			{
				{1,1,0,0},
				{0,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
		},
		{///5th piece with all 4 forms
			{
				{0,1,0,0},
				{1,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{1,1,1,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
		},
		{///6th piece with all 4 forms
			{
				{1,1,0,0},
				{0,1,1,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,0,1,0},
				{0,1,1,0},
				{0,1,0,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
		},
		{ ///7th piece with all its 4 forms 
			{
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,1,0,0},
				{0,1,1,0},
				{0,0,1,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,1,1,0},
				{1,1,0,0},
				{0,0,0,0}
			},
			{
				{1,0,0,0},
				{1,1,0,0},
				{0,1,0,0},
				{0,0,0,0}
			},
		},
};
int colors[8][4] = {
	{0,0,0},
	{16,16,16},
	{26,26,26},
	{36,36,36},
	{46,46,46},
	{56,56,56},
	{66,66,66},
	{76,76,76}
};

void Board::new_piece() {
	int piece = rand() % 8;
	int offset_col = (nr_col - 4) / 2;
	int offset_lin = 0;

	for (int lin = 0; lin < 5; lin++)
		for (int col = 0; col < 5; col++) {
			board[lin + 1][col + 1] = Pieces[piece][0][lin][col] * piece;
			cout << board[lin + 1][col + 1];
		}
}
void Board::move_row(int row, int nr_rows) {
	for (int col = 1; col <= nr_col; col++) {
		board[row + nr_rows][col] = board[row][col];
		board[row + nr_rows][col] = 0;
	}
}


bool  Board::row_is_full(int row) {
	for (int col = 1; col <= nr_col; col++)
		if (board[row][col] > 0)
			return false;
	return true;
}


void Board::draw_board(sf::RenderWindow& window) {

	float pos_x = (float)((square_size + gap) * nr_col + gap);
	float pos_y = (float)((square_size + gap) * nr_row + gap);

	sf::RectangleShape b(sf::Vector2f(pos_x, pos_y));

	b.setFillColor(sf::Color(122, 63, 33, 255));
	b.setPosition(sf::Vector2f(margin_left, margin_top));


	window.draw(b);

	for (int lin = 1; lin <= nr_row; lin++) {
		for (int col = 1; col <= nr_col; col++) {

			int piece = board[lin][col];

			sf::RectangleShape square(sf::Vector2f(square_size, square_size));

			square.setFillColor(sf::Color(colors[piece][0], colors[piece][1], colors[piece][2], 255));

			float pos_x = (float)(square_size + gap) * (col - 1) + gap + margin_left;
			float pos_y = (float)(square_size + gap) * (lin - 1) + gap + margin_top;
			square.setPosition(sf::Vector2f(pos_x, pos_y));

			window.draw(square);
		}
	}

}
