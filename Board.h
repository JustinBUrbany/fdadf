#ifndef BOARD_H
#define BOARD_H
#include "OpenCells.h"
#include "HomeCells.h"
#include "PlayCells.h"
#include "deck.h"

class Board
{
public:
	Board();
	~Board();
	void Deal();
	void PlayGame();
	void PrintBoard();
	bool CheckWin();
private:
	HomeCells m_home_cells;
	OpenCells m_open_cells;
	PlayCells m_play_cells;
	Deck m_deck;
};

#endif BOARD_H
