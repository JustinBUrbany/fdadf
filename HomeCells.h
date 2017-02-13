#ifndef HOMECELLS_H
#define HOMECELLS_H
#include "Stack.h"
#include "Array.h"
#include "card.h"



class HomeCells
{
public:
	HomeCells();
	bool MoveHome(Card & card, int column);
	Card MoveOutofHome(int column);
	bool CheckAllCells();
	bool CheckSingleCell(int column);
	void ValidPlay();
	void PrintHomeCells();


private:
	Array<Stack<Card>> m_Home_Cells;

};


#endif
