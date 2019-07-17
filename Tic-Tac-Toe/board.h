#ifndef BOARD_H
#define BOARD_H
#include<vector>
#include<iostream>
#include<string>
using namespace std;

const int row = 13;
const int col = 26;
const int gridNumber = 9;
const int macChar = 'X';
const int manChar = 'O';
const int blankChar = ' ';

class Board {
public:
	Board();

	bool isEmpty(int pos);
	bool isFull();
	bool isWin(char c);
	bool macWin(int & bestMove);
	bool manWin(int & bestMove);
	void macMakeMove(int pos);
	void manMakeMove(int pos);
	void undoMakeMove(int pos);
	void print();

private:
	vector<char> boardSingleDimen;
	vector<string> board;
};

#endif // !BOARD_H
