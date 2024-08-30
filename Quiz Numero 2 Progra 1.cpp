#include <iostream>
#include "Minesweeper.h"
using namespace std;
int main()
{
	int rows = 10;
	int cols = 10;
	Mineweeper mineweeper(rows, cols);
	mineweeper.initializeBoard();
	mineweeper.completeBoardClues();
}