#include "../HeaderFiles/Game.h"

Connect4:: Connect4(std::string name1, std::string name2)
{
	p1 = new Player(name1, 'X');
	p2 = new Player(name2, 'O');
	gameOver = false;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			board[i][j] = ' ';
		}
	}
	GameLoop();
}

void Connect4::GameLoop()
{
	turn = 0;
	int choice;
	Player* currentPlayer = new Player();

	while (!gameOver && !BoxFull())
	{
		PrintBoard();
		if (turn % 2 == 0)
		{
			currentPlayer = p1;
		}
		else if (turn % 2 == 1)
		{
			currentPlayer = p2;
		}
		std::cout << "\n" << currentPlayer->name << " :Input(1-7) :\n";
		do
		{
			std::cin >> choice;
			choice--;
			if (choice < 1 || choice >7)
			{
				std::cout << "Invalid Input.Your turn is lost\n";
			}
		} while (choice < 1 || choice >7);
		PlacePiece(choice, currentPlayer->piece);
		if (!gameOver)
		{
			turn++;
		}
	}
	if (gameOver)
	{
		GameWin();
	}
	if (BoxFull())
	{
		std::cout << "\nBox Full.Game Draw";
	}

}
bool Connect4::BoxFull()
{
	for (int i = 0; i < 7; i++)
	{
		if (board[0][i] == ' ')
		{
			return false;
		}
	}
	return true;
}
void Connect4::GameWin()
{
	PrintBoard();
	if (turn % 2 == 0)
	{
		std::cout << "\nHurray! Player " << p1->name << "  Won!" << std::endl;
	}
	else
	{
		std::cout << "\nHurray! Player " << p2->name << "  Won!" << std::endl;
	}
}
void Connect4::PlacePiece(int choice, char piece)
{
	if (isColumnFull(choice))
	{
		return;
	}
	for (int i = 5; i >= 0; i--)
	{
		if (board[i][choice] == ' ')
		{
			board[i][choice] = piece;
			CheckForWin(i, choice);
			break;
		}
	}
}
bool Connect4::isColumnFull(int column)
{
	return board[0][column] != ' ';
}

void Connect4::PrintBoard()
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << "|";
		for (int j = 0; j < 7; j++)
		{
			std::cout << board[i][j] << " |";
		}
		std::cout << std::endl;
	}
}
