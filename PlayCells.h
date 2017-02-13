#ifndef PLAYCELLS_H
#define PLAYCELLS_H
#include "Array.h"
#include "Stackll.h"
#include "card.h"
#include "deck.h"



class PlayCells
{
public:
	PlayCells();
	void PopulatePlaycells(Deck & deck);
	int checkFreePlayCells();
	void PrintPlayCells();
	bool MoveCardPlay(Card & card, int column);
	void Reset(Card & card, int column);
	bool PlayCellEmpty(int column);
	Card MoveCardOut(int column);
	void MoveCardHome();
	void MoveMultipleCards(int column, int openspaces);
	bool GameOver();
	int Get_Open_Play_Cells();
private:
	Array<Stackll<Card>> m_Play_Cells;
	int m_Open_Play_Cells = 0;
};

#endif
