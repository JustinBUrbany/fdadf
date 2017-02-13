#ifndef OPENCELLS_H
#define OPENCELLS_H
#include "Array.h"
#include "card.h"

class OpenCells
{
public:
	OpenCells();
	void PrintOpen();
	int GetOpen();
	void SetCard(Card & card, int column);
	Card & GetCard(int column);
private:
	Array<Card> m_Open_Cells;
	int m_open = 4;
};

#endif OPENCELLS_H
