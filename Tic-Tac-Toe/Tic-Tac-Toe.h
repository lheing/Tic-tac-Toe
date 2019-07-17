#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "board.h"
enum role{man, mac};

static const int macWin = 2;
static const int tie = 1;
static const int manWin = 0;

class TicTacToe {
public:
	void start();
	bool result();
	bool gameOver(bool &tie, role &win);
	role whoFirst();
	void macPutChess();
	int getBestMove();
	void manPutChess();
	int getPos();
	void macAlphaBeta(int& bestMove, int& value, int alpha, int beta);
	void manAlphaBeta(int& bestMove, int& value, int alpha, int beta);

private:
	Board board;
};
#endif // !TICTACTOE_H

