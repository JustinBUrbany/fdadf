#define _CRTDBG_MAP_ALLOC
#include "FreeCell.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //memory leak checker

	FreeCell Game;

	return 0;
}