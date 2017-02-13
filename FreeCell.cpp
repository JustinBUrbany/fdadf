#include "FreeCell.h"
#include <iostream>
using std::cout;
using std::cin;

FreeCell::FreeCell()
{
	m_board = new Board;
	Deal();
}

FreeCell::~FreeCell()
{
	delete m_board;
}

void FreeCell::Deal()
{
	m_board->Deal();
	PlayAgain();
}

void FreeCell::PlayAgain()
{
	char selection = '\0';
	while (selection != 'n' && selection != 'y')
	{
		cout << "would you like to play again?(y,n):";
		cin >> selection;
	}
	
	if (selection=='y')
	{
		delete m_board;
		m_board = new Board;
		Deal();
	}
}
