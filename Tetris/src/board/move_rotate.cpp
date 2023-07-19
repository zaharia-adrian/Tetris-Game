#include "board.h"

int offset[8][4][4] = {
	{},
	{///1st piece
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}
	},
	{///2nd piece
		{1,0,2,0},
		{0,1,0,2},
		{2,0,1,0},
		{0,2,0,1}
	},
	{///3th piece
		{0,1,2,0},
		{0,1,1,1},
		{1,1,1,0},
		{0,2,1,0}
	},
	{///4th piece
		{0,1,2,0},
		{0,1,1,1},
		{1,1,1,0},
		{0,2,1,0}
	},
	{///5th piece
		{0,1,2,0},
		{0,1,1,1},
		{1,1,1,0},
		{0,2,1,0}
	},
	{///6th piece
		{0,1,2,0},
		{0,1,1,1},
		{1,1,1,0},
		{0,2,1,0}
	},
	{///7th piece
		{0,1,2,0},
		{0,1,1,1},
		{1,1,1,0},
		{0,2,1,0}
	}
};

void Board::move_left() {
	if (offset_col + offset[piece][orientation][3] > 0) {
		bool ok = true;
		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4; col++)
				if (Pieces[piece][orientation][row][col] && board[offset_row + row + 1][offset_col + col])
					ok = false;
		if (ok)
			offset_col--;
	}
}

void Board::move_rigth() {
	if (offset_col + 4 - offset[piece][orientation][1] < nr_col) {
		bool ok = true;
		for (int row = 0; row < 4; row++)
			for (int col = 0; col < 4; col++)
				if (Pieces[piece][orientation][row][col] && board[offset_row + row + 1][offset_col + col + 2])
					ok = false;
		if (ok)
			offset_col++;
	}

}

void Board::rotate_cw() {
	int new_orientation = (orientation + 1) % 4;
	bool ok = true;
	for (int row = 0; row < 4; row++) 
		for (int col = 0; col < 4; col++) 
			if (Pieces[piece][new_orientation][row][col])
				if (row + offset_row + 1 > nr_row ||
					row + offset_row + 1 < 1 ||
					col + offset_col + 1 > nr_col ||
					col + offset_col + 1 < 1 ||
					board[row+offset_row+1][col+offset_col+1]
					) ok = false;
	if (ok)
		orientation = new_orientation;
}

void Board::rotate_ccw() {
	int new_orientation = (orientation - 1 + 4) % 4;
	bool ok = true;
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (Pieces[piece][new_orientation][row][col])
				if (row + offset_row + 1 > nr_row ||
					row + offset_row + 1 < 1 ||
					col + offset_col + 1 > nr_col ||
					col + offset_col + 1 < 1 ||
					board[row + offset_row + 1][col + offset_col + 1]
					) ok = false;
	if (ok)
		orientation = new_orientation;
}

void Board::drop() {
	period = 0;
}