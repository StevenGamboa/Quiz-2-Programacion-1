#pragma once
#include <iostream>
using namespace std;
class Mineweeper {
private:
	int** board = nullptr;
	int rows;
	int cols;
public:
	Mineweeper(int rows, int cols);
	~Mineweeper();
	void initializeBoard();
	void completeBoardClues();
	void setConditions(int i, int j);
};