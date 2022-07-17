#pragma once
#include "../HeaderFiles/Player.h"

class Connect4
{
public:
	Player* p1;
	Player* p2;

	int turn;
	bool gameOver;

	int m;
	int n;
	char board[6][7];

	Connect4(std::string name1,std::string name2);
	void GameLoop();
	void GameWin();
	void PlacePiece(int choice, char piece);
	void PrintBoard();
	bool BoxFull();
	bool isColumnFull(int column);

	//Win-Check
	void CheckForWin(int i, int j);
	bool Horizontal(int i, int j);
	bool Vertical(int i, int j);
	bool LeftDiagonal(int i, int j);
	bool RightDiagonal(int i, int j);
};
	