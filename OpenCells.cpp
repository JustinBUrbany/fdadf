#include "OpenCells.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;

OpenCells::OpenCells()
{
	m_Open_Cells.setLength(4);
}

void OpenCells::PrintOpen()
{
	
	for (int i = 0; i<4; ++i)
	{
		//if(m_Open_Cells[i].GetSuit==Diamond)
		if (m_Open_Cells[i].GetRank() == 15)
		{
			cout << setw(10) << "Open";
		}
		else
		{
			m_Open_Cells[i].DisplayCard();
		}
	}
	
		
	
}

int OpenCells::GetOpen()
{
	return m_open;
}

void OpenCells::SetCard(Card & card, int column)
{
	if (m_Open_Cells[column].GetRank() == 15)
	{
		m_Open_Cells[column] = card;
		m_open--;
	}
	else
	{
		cout << "Already a Card in that cell\n";
	}
}

Card & OpenCells::GetCard(int column)
{
	Card temp = m_Open_Cells[column];
	m_Open_Cells[column].SetRank(m_Open_Cells[column].INVALID);
	if (temp.GetRank() != 15)
	{
		m_open++;
	}

	return temp;
}
