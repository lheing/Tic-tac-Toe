// Tic-Tac-Toe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Tic-Tac-Toe.h"

void TicTacToe::start(){
	role firstPut = whoFirst();
	if (firstPut == mac) {
		macPutChess();
	}
	

	while (true) {
		board.print();
		if (result()) break;
		manPutChess();
		board.print();
		if (result()) break;
		macPutChess();
	}
}

role TicTacToe::whoFirst() {
	int who;
	while (true) {
		cout << "who First ? human(press 0) : machine(press 1)." << endl;
		cin >> who;
		if (who == 0 || who == 1) {
			cout << endl;
			break;
		}
		else
		{
			cout << "please press the right number(0 or 1)." << endl;
		}
	}
	return (role)who;
}

int TicTacToe::getPos() {
	int pos;
	while (true)
	{
		int m, n;
		cout << "input position  m n  , m∈[1, 3], n∈[1, 3]." << endl;
		cin >> m >> n;
		if (m > 3 || m < 1 || n>3 || n < 1)
			cout <<"out of range!"<< endl;
		else
		{
			pos = (m - 1) * 3 + n - 1;
			if (board.isEmpty(pos))
				break;
			else
				cout <<"position has been put!"<< endl;
		}
	}
	return pos;
}

void TicTacToe::manPutChess() {
	int pos = getPos();
	board.manMakeMove(pos);
}

void TicTacToe::macPutChess() {
	int bestMove = getBestMove();
	board.macMakeMove(bestMove);
}

int TicTacToe::getBestMove() {
	int bestMove = 0, value = 0;
	macAlphaBeta(bestMove, value, manWin, macWin);
	return bestMove;
}

void TicTacToe::macAlphaBeta(int& bestMove, int& value, int alpha, int beta) {
	if (board.isFull())
		value = tie;
	else if (board.macWin(bestMove))
		value = macWin;
	else {
		value = alpha;
		for (int i = 0; i < gridNumber&&value < beta; i++)
		{
			if (board.isEmpty(i)) {
				board.macMakeMove(i);
				int tmp = -1, response = -1;
				manAlphaBeta(tmp, response, value, beta);
				board.undoMakeMove(i);
				if (response > value) {
					value = response;
					bestMove = i;
				}
			}
		}
	}
}

void TicTacToe::manAlphaBeta(int& bestMove, int& value, int alpha, int beta) {
	if (board.isFull())
		value = tie;
	else if (board.manWin(bestMove)) {
		value = manWin;
	}
	else
	{
		value = beta;
		for (int i = 0; i < gridNumber&&value < alpha; i++) {
			if (board.isEmpty(i)) {
				board.manMakeMove(i);
				int tmp = -1, response = -1;
				macAlphaBeta(tmp, response, alpha, value);
				board.undoMakeMove(i);
				if (response < value) {
					value = response;
					bestMove = i;
				}
			}
		}
	}
}

bool TicTacToe::gameOver(bool &tie, role &win) {
	if (board.isWin(macChar)) {
		win = mac;
		tie = false;
		return true;
	}
	else if (board.isWin(manChar)) {
		win = man;
		tie = false;
		return true;
	}
	else if (board.isFull()) {
		tie = true;
		return true;
	}
	return false;
}

bool TicTacToe::result() {
	bool tie = false;
	role whoWin = man;
	if (gameOver(tie, whoWin)) {
		if (tie) {
			cout << "Tie!"<< endl;
		}
		else {
			if (whoWin == mac) {
				cout << "you lose!"<< endl;
			}
			else if (whoWin == man) {
				cout << "you win!" << endl;
			}
		}
		return true;
	}
	return false;
}
int main()
{
	while (true)
	{
		TicTacToe game;
		game.start();
		cout << "play again(yes or no ? )" << endl;
		string s;
		cin >> s;
		if (s == "yes" || s == "y")
			continue;
		else {
			cout << "thanks for you play*^____^* byebye！" << endl;
			break;
		}
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
