#ifndef FREECELL_H
#define FREECELL_H
#include "Board.h"
class FreeCell
{
public:
	FreeCell();
	~FreeCell();
	void Deal();
	void PlayAgain();
private:
	Board * m_board;

};


#endif // !FREECELL_H
