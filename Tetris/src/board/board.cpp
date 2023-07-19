#include "board.h"

int Pieces[8][4][4][4] = {
		{/// **0th piece in all 4 forms
			{
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
			{
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			},
		},	
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
	{255,0,0},
	{255,128,0},
	{0,0,153},
	{0,255,0},
	{102,0,51},
	{153,255,153},
	{255,51,255}
};

Board::Board() {
	playing = true;

	for (int row = 0; row <= nr_row; row++)
		for (int col = 0; col <= nr_col; col++)
			board[row][col] = 0;

	piece = orientation = 0;
	offset_col = offset_row = 0;
	score = 0;
}

void Board::play() {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 7);
	piece = dis(gen);
	period = 1000;

	orientation = 0;
	offset_col = (nr_col - 4) / 2;
	offset_row = 0 - offset[piece][orientation][0];

	///verifying if still playing or game over
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (Pieces[piece][orientation][row][col] && board[row+offset_row+1][col+offset_col+1]) {
				playing = false;
				return;
			}

	thread t([this]() {

		bool down = true;
		while (down) {

			for (int row = 0; row < 4; row++)
				for (int col = 0; col < 4; col++) 
					if (Pieces[piece][orientation][row][col] &&
						board[row + offset_row + 2][col + offset_col+1])
						down = false;

			if (offset_row + 4 - offset[piece][orientation][(2+orientation)%4] >= nr_row)
				down = false;
			if (down)
				offset_row++;

			std::this_thread::sleep_for(std::chrono::milliseconds(period));
		}
		///drawing the new piece on the board when already down
		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4; col++)
				if(Pieces[piece][orientation][row][col])
					board[row + offset_row+1][col + offset_col+1] = Pieces[piece][orientation][row][col] * piece;
		verify();
		play();

		});
	t.detach();
}
void Board::move_row(int row, int nr_rows) {
	if (row - nr_rows < 1)
		return;
	for (int col = 1; col <= nr_col; col++) {
		board[row][col] = board[row - nr_rows][col];
		board[row - nr_rows][col] = 0;
	}
}


bool  Board::row_is_full(int row) {
	for (int col = 1; col <= nr_col; col++)
		if (board[row][col] == 0)
			return false;
	return true;
}

void Board::verify() {
	int nr_row_deleted=0;
	for(int row = nr_row; row >= 1; row--){
		if (row_is_full(row)) {
			 nr_row_deleted++;
			 score += nr_col;
		}
		if(nr_row_deleted>0)
			move_row(row, nr_row_deleted);
	}
}


void Board::draw_board(sf::RenderWindow& window,sf::Font f) {

	float pos_x = (float)((square_size + gap) * nr_col + gap);
	float pos_y = (float)((square_size + gap) * nr_row + gap);

	sf::RectangleShape b(sf::Vector2f(pos_x, pos_y));

	///Score
	sf::Text Score(to_string(score), f);
	Score.setFillColor(sf::Color(255, 255, 255, 255));
	Score.setPosition(sf::Vector2f(100.f, 100.f));
	window.draw(Score);

	float margin_left = window.getSize().x / 2 - pos_x / 2;

	b.setFillColor(sf::Color(122, 63, 33, 255));
	b.setPosition(sf::Vector2f(margin_left, margin_top));

	window.draw(b);


	for (int row = 1; row <= nr_row; row++) {
		for (int col = 1; col <= nr_col; col++) {

			int p = board[row][col];

			if (piece && p == 0)
				if (row >= offset_row + 1 &&
					row <= offset_row + 4 &&
					col >= offset_col + 1 &&
					col <= offset_col + 4
					)
					p = Pieces[piece][orientation][row - offset_row - 1][col - offset_col - 1] * piece;
			sf::RectangleShape square(sf::Vector2f(square_size, square_size));

			square.setFillColor(sf::Color(colors[p][0], colors[p][1], colors[p][2], 255));

			float pos_x = (float)(square_size + gap) * (col - 1) + gap + margin_left;
			float pos_y = (float)(square_size + gap) * (row - 1) + gap + margin_top;
			square.setPosition(sf::Vector2f(pos_x, pos_y));

			window.draw(square);
		}
	}

	///GAME OVER
	if (!playing) {
		sf::Text game_over("GAME OVER", f, 100U);
		game_over.setPosition(sf::Vector2f(640.f, 500.f));
		window.draw(game_over);
	}

}
