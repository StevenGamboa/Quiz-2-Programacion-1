#include <iostream>
#include "Minesweeper.h"
#include <cstdlib>
#include <iomanip>
using namespace std;
Mineweeper::Mineweeper(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
}
Mineweeper::~Mineweeper() {
	for (int i = 0; i < rows; i++) {
		delete[] board[i];
	}
	delete[] board;
}
void Mineweeper::initializeBoard() {
	board = new int* [rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = 0;
			int randomNumber = rand() % rows;
			int randomNumber2 = rand() % cols;
			board[randomNumber][randomNumber2] = -1;
		}
	}
}
void Mineweeper::completeBoardClues() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			setConditions(i, j);
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(3) << board[i][j] << "	";
		}
		cout << endl;
	}
}
void Mineweeper::setConditions(int i, int j) {
	int counter = 0;
	if (board[i][j] == 0) {
		if (i > 0 && board[i - 1][j] == -1) {
			counter++;
		}
		if (i > 0 && j > 0 && board[i - 1][j - 1] == -1) {
			counter++;
		}
		if (i > 0 && j < (cols - 1) && board[i - 1][j + 1] == -1) {
			counter++;
		}
		if (j > 0 && board[i][j - 1] == -1) {
			counter++;
		}
		if (j < (cols - 1) && board[i][j + 1] == -1) {
			counter++;
		}
		if (i < (rows - 1) && j > 0 && board[i + 1][j - 1] == -1) {
			counter++;
		}
		if (i < (rows - 1) && board[i + 1][j] == -1) {
			counter++;
		}
		if (i < (rows - 1) && j < (cols - 1) && board[i + 1][j + 1] == -1) {
			counter++;
		}
		board[i][j] = counter;
	}
}