#include<iostream>
#include<vector>

class Connect4
{
public:
	Player* p1;
	Player* p2;

	int turn;
	bool gameOver;

	std::vector<std::vector<char>> board;

	Connect4(std::string name1,std::string name2)
	{
		p1 = new Player(name1, 'X');
		p2 = new Player(name2, 'O');
		gameOver = false;
		int m = 6, n = 7;
		std::vector<std::vector<char>> _board(m,std::vector<char>(n,' '));
		this->board = _board;

		GameLoop();
	}

	void GameLoop()
	{
		turn = 0;
		int choice;

		while (!gameOver || !BoxFull())
		{
			PrintBoard();
			if (turn % 2 == 0)
			{
				std::cout << "\n" << p1->name << " :Input(1-7) :\n";
				std::cin >> choice;
				choice--;
				PlacePiece(choice, p1->piece);
				turn++;
			}
			else
			{
				std::cout << "\n" << p2->name << " :Input(1-7) :\n";
				std::cin >> choice;
				choice--;
				PlacePiece(choice, p2->piece);
				turn++;
			}
		}

	}
	bool BoxFull()
	{
		for (int i = 0; i < board[0].size(); i++)
		{
			if (board[0][i] == ' ')
			{
				return false;
			}
			return true;
		}
	}
	void CheckForWin(int i, int j)
	{
		bool flag = false;
		//implement

		if (flag == true)
		{
			GameWin();
			gameOver = true;
		}
	}

	void GameWin()
	{
		PrintBoard();
		if (turn % 2 == 0)
		{
			std::cout << "\n" << p1->name << "Won!" << std::endl;
		}
		else
		{
			std::cout << "\n" << p2->name << "Won!" << std::endl;
		}
	}
	void PlacePiece(int choice, char piece)
	{
		if (isCoulmnFull(choice))
		{
			return;
		}
		for (int i = board.size()-1; i != 0; i--)
		{
			if (board[i][choice] == ' ')
			{
				board[i][choice] = piece;
				CheckForWin(i, choice);
				break;
			}
		}
	}
	bool isCoulmnFull(int column)
	{
		return board[0][column] != ' ';
	}

	void PrintBoard()
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				std::cout << board[i][j]<<" ";
			}
			std::cout << std::endl;
		}
	}
};






class Player
{
	public:
	std::string name;
	char piece;

	Player(std::string _name, char _piece)
	{
		this->name = _name;
		this->piece = _piece;
	}
};


int main()
{
	std::string name1, name2;
	std::cout << "\nEnter name of the first Player\n";
	std::cin >> name1;
	std::cout << "\nEnter name of the second Player\n";
	std::cin >> name2;

	Connect4* connect4 = new Connect4(name1, name2);
}