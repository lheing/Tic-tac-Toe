#include "board.h"

Board::Board() {
	boardSingleDimen.resize(gridNumber+1);
	for (int i = 0; i < gridNumber; i++)
		boardSingleDimen[i] = blankChar;
	vector<string> tmp = {
		"- - - - - - - - - - - - -",
		"|       |       |       |",
		"|       |       |       |",
		"|       |       |       |",
		"- - - - - - - - - - - - -",
		"|       |       |       |",
		"|       |       |       |",
		"|       |       |       |",
		"- - - - - - - - - - - - -",
		"|       |       |       |",
		"|       |       |       |",
		"|       |       |       |",
		"- - - - - - - - - - - - -"
	};
	board = tmp;
}

bool Board::isEmpty(int pos) {
	return boardSingleDimen[pos] == blankChar;
}

bool Board::isFull() {
	for (int i = 0; i < gridNumber; i++) {
		if (boardSingleDimen[i] == blankChar)
			return false;
	}
	return true;
}

bool Board::isWin(char c) {
	//every row
	for (int i = 0; i <= 6; i += 3) {
		if (boardSingleDimen[i] == c &&
			boardSingleDimen[i + 1] == c &&
			boardSingleDimen[i + 2] == c)
		{
			return true;
		}
			
	}

	//every col
	for (int i = 0; i < 3; i++)
	{
		if (boardSingleDimen[i] == c &&
			boardSingleDimen[i+3] == c &&
			boardSingleDimen[i+6] == c )
		{
			return true;
		}
			
	}

	//every diagonal
	if (boardSingleDimen[0] == c &&
		boardSingleDimen[4] == c &&
		boardSingleDimen[8] == c)
	{
		return true;
	}
		

	if (boardSingleDimen[2] == c &&
		boardSingleDimen[4] == c &&
		boardSingleDimen[6] == c)
	{
		return true;
	}
		

	return false;
}

bool Board::macWin(int & bestMove) {
	for (int i = 0; i < gridNumber; i++) {
		if (isEmpty(i)) {
			macMakeMove(i);
			bool win = isWin(macChar);
			undoMakeMove(i);
			if (win) {
				bestMove = i;
				return true;
			}
		}
	}
	return false;
}

bool Board::manWin(int & bestMove) {
	for (int i = 0; i < gridNumber; i++) {
		if (isEmpty(i)) {
			manMakeMove(i);
			bool win = isWin(manChar);
			undoMakeMove(i);
			if (win) {
				bestMove = i;
				return true;
			}
		}
	}
	return false;
}

void Board::macMakeMove(int pos)
{
	boardSingleDimen[pos] = macChar;
}

void Board::manMakeMove(int pos)
{
	boardSingleDimen[pos] = manChar;
}

void Board::undoMakeMove(int pos)
{
	boardSingleDimen[pos] = blankChar;
}

void Board::print() {
	int cnt = 0;
	for (int i = 2; i <= 10; i += 4)
	{
		for (int j = 4; j <= 20; j += 8)
		{
			board[i][j] = boardSingleDimen[cnt++];
		}
	}

	for (int i = 0; i < row; i++)
	{
		cout << board[i] << endl;
	}

}

