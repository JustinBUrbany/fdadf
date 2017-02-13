#include "PlayCells.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;



PlayCells::PlayCells()
{
	m_Play_Cells.setLength(8);
}

void PlayCells::PopulatePlaycells(Deck & deck)
{
	int j = 0;
	for (int i = 0; i < 52; ++i)
	{
		m_Play_Cells[j].Push(deck.Deal());
		if (j == 7)
		{
			j = 0;
		}
		else
		{
			j++;
		}
	}
}


int PlayCells::checkFreePlayCells()
{
	return 0;
}

void PlayCells::PrintPlayCells()
{
	Array<Stackll<Card>> temp;// = m_Play_Cells;
	temp.setLength(8);
	Array<Stackll<Card>> copy = m_Play_Cells;
	Card tempcard;
	for (int i = 0; i < 8; i++)
	{
		while (!m_Play_Cells[i].isEmpty())
		{
			tempcard = m_Play_Cells[i].Pop();
			temp[i].Push(tempcard);
		}
	}
	//Array<Stackll<Card>> temp;
	//Card tempcard;
	for (int i = 0; i < 19; ++i)
	{
		if (i == 0)
		{
			int n = 1;
			while (n < 9)
			{
				cout << setw(9) << "Play" << n;
				++n;
			}
			cout << "\n";
		}
		int j = 0;
		while (j < 8)
		{
			
			if (temp[j].Size() > 0)
			{
				tempcard = temp[j].Pop();
				tempcard.DisplayCard();
			}
			else
			{
				cout << setw(10)<<" ";
			}
			++j;
		}
		cout << "\n";
		m_Play_Cells = copy;

	}
}

bool PlayCells::MoveCardPlay(Card & card, int column)
{
	bool validmove = false;
	if (m_Play_Cells[column].isEmpty())
	{
		validmove = true;
		m_Open_Play_Cells--;
		m_Play_Cells[column].Push(card);
	}
	else 
	{
		Card tempcard = m_Play_Cells[column].Peek();

		if ((card.GetRank() + 1) == tempcard.GetRank())
		{
			if (card.GetSuit() == card.HEART && (tempcard.GetSuit() == tempcard.SPADE || tempcard.GetSuit() == tempcard.CLUB))
			{
				validmove = true;
				m_Play_Cells[column].Push(card);
			}
			else if (card.GetSuit() == card.DIAMOND && (tempcard.GetSuit() == tempcard.SPADE || tempcard.GetSuit() == tempcard.CLUB))
			{
				validmove = true;
				m_Play_Cells[column].Push(card);
			}
			else if (card.GetSuit() == card.SPADE && (tempcard.GetSuit() == tempcard.HEART || tempcard.GetSuit() == tempcard.DIAMOND))
			{
				validmove = true;
				m_Play_Cells[column].Push(card);
			}
			else if (card.GetSuit() == card.CLUB && (tempcard.GetSuit() == tempcard.HEART || tempcard.GetSuit() == tempcard.DIAMOND))
			{
				validmove = true;
				m_Play_Cells[column].Push(card);
			}
			else
			{
				validmove = false;
				cout << "Can't move ";
				card.DisplayCard();
				cout << " Onto ";
				card.DisplayCard();
				cout << "\n";
			}
		}
	}
	return validmove;
}

void PlayCells::Reset(Card & card, int column)
{
	m_Play_Cells[column].Push(card);
}

bool PlayCells::PlayCellEmpty(int column)
{
	bool emptycell = false;
	if (m_Play_Cells[column].isEmpty())
	{
		emptycell = true;
	}

	return emptycell;
}

Card PlayCells::MoveCardOut(int column)
{
	return m_Play_Cells[column].Pop();
}

void PlayCells::MoveCardHome()
{
}

void PlayCells::MoveMultipleCards(int column, int openspaces)
{
	int numberofcardmove = 0;
	int movetocolumn = 0;
	while (numberofcardmove < 1 || numberofcardmove >(openspaces + 1))
	{
		cout << "How many Cards do you want to Move?";
		cin >> numberofcardmove;
		if (numberofcardmove < 1)
		{
			cout << "Must have at least 1 card to move.\n\n";
		}
		else if( numberofcardmove>(openspaces+1))
		{
			cout << "Can only move " << openspaces + 1 << " when you have " << openspaces << "\n\n";
		}
	}
	if (numberofcardmove == 1)
	{
		while (movetocolumn < 1 || movetocolumn >8)
		{
			cout << "What column do you want to move too?(1,2,3....8)";
			cin >> movetocolumn;
			if (movetocolumn < 1 || movetocolumn >8)
			{
				cout << "Invalid column Select \n";
			}
		}
		if ((column + 1) != movetocolumn)
		{
			Card temp = m_Play_Cells[column].Pop();
			if (!MoveCardPlay(temp, movetocolumn - 1))
			{
				Reset(temp, column);
			}
		}

	}
	else
	{
		bool valid = true;
		Stackll<Card> tempstack;
		Card temp1;
		Card temp2;

		for (int i = 0; i < (numberofcardmove-1) && valid == true; ++i)
		{
			temp1 = m_Play_Cells[column].Pop();
			tempstack.Push(temp1);
			temp2 = m_Play_Cells[column].Peek();
			if ((temp1.GetRank() + 1) == temp2.GetRank())
			{
				if (temp1.GetSuit() == temp1.HEART && ((temp2.GetSuit() == temp2.SPADE) || (temp2.GetSuit() == temp2.CLUB)))
				{

				}
				else if (temp1.GetSuit() == temp1.DIAMOND && ((temp2.GetSuit() == temp2.SPADE) || (temp2.GetSuit() == temp2.CLUB)))
				{

				}
				else if (temp1.GetSuit() == temp1.SPADE && ((temp2.GetSuit() == temp2.HEART) || (temp2.GetSuit() == temp2.DIAMOND)))
				{

				}
				else if (temp1.GetSuit() == temp1.CLUB && ((temp2.GetSuit() == temp2.HEART) || (temp2.GetSuit() == temp2.DIAMOND)))
				{

				}
				else
				{
					valid = false;
					cout << "Cant move ";
					temp1.DisplayCard();
					cout << " and ";
					temp2.DisplayCard();
					cout << " at the same time since they are not offseting Colors\n\n";
					while (!tempstack.isEmpty())
					{
						temp2 = tempstack.Pop();
						m_Play_Cells[column].Push(temp2);
					}
				}
			
			}
			else
			{
				valid = false;
				cout << "Cant move ";
				temp1.DisplayCard();
				cout << " and ";
				temp2.DisplayCard();
				cout << " at the same time since they are not numerically ordered\n\n";
				while (!tempstack.isEmpty())
				{
					temp2 = tempstack.Pop();
					m_Play_Cells[column].Push(temp2);
				}
			}
		};
		if (valid == true)
		{
			temp2 = m_Play_Cells[column].Pop();
			tempstack.Push(temp2);
			while (movetocolumn < 1 || movetocolumn>8)
			{
				cout << "What Column Do you want to move selected Cards?(1,2,3...8)";
				cin >> movetocolumn;
				if (movetocolumn < 1 || movetocolumn >8)
				{
					cout << "Invalid column Select \n";
				}
			}
			if ((column + 1) == movetocolumn)
			{
				while (!tempstack.isEmpty())
				{
					temp2 = tempstack.Pop();
					m_Play_Cells[column].Push(temp2);
				}
			}
			else if (m_Play_Cells[movetocolumn - 1].isEmpty())
			{
				while (!tempstack.isEmpty())
				{
					temp2 = tempstack.Pop();
					m_Play_Cells[movetocolumn-1].Push(temp2);
				}
			}
			else
			{
				temp1 = tempstack.Peek();
				temp2 = m_Play_Cells[movetocolumn-1].Peek();
				if ((temp1.GetRank() + 1) == temp2.GetRank())
				{
					if (temp1.GetSuit() == temp1.HEART && ((temp2.GetSuit() == temp2.SPADE) || (temp2.GetSuit() == temp2.CLUB)))
					{
						while (!tempstack.isEmpty())
						{
							temp2 = tempstack.Pop();
							m_Play_Cells[movetocolumn-1].Push(temp2);
						}
					}
					else if (temp1.GetSuit() == temp1.DIAMOND && ((temp2.GetSuit() == temp2.SPADE) || (temp2.GetSuit() == temp2.CLUB)))
					{
						while (!tempstack.isEmpty())
						{
							temp2 = tempstack.Pop();
							m_Play_Cells[movetocolumn-1].Push(temp2);
						}
					}
					else if (temp1.GetSuit() == temp1.SPADE && ((temp2.GetSuit() == temp2.HEART) || (temp2.GetSuit() == temp2.DIAMOND)))
					{
						while (!tempstack.isEmpty())
						{
							temp2 = tempstack.Pop();
							m_Play_Cells[movetocolumn-1].Push(temp2);
						}
					}
					else if (temp1.GetSuit() == temp1.CLUB && ((temp2.GetSuit() == temp2.HEART) || (temp2.GetSuit() == temp2.DIAMOND)))
					{
						while (!tempstack.isEmpty())
						{
							temp2 = tempstack.Pop();
							m_Play_Cells[movetocolumn-1].Push(temp2);
						}
					}
					else
					{
						cout << "ERROR PUSHING STACK\n\n";
						while (!tempstack.isEmpty())
						{
						temp2 = tempstack.Pop();
						m_Play_Cells[column].Push(temp2);
						}
					}
				}
			}
		}
	}

}


bool PlayCells::GameOver()
{
	bool gameover = true;
	for (int i = 0; i < 8 && gameover==true; ++i)
	{
		if (!m_Play_Cells[i].isEmpty())
		{
			gameover = false;
		}
	}
	return gameover;
}

int PlayCells::Get_Open_Play_Cells()
{
	m_Open_Play_Cells = 0;
	for (int i = 0; i < 8; ++i)
	{
		if (m_Play_Cells[i].isEmpty())
		{
			m_Open_Play_Cells++;
		}
	}
	return m_Open_Play_Cells;
}
