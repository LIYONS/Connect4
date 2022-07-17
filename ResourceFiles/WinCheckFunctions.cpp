#include "../HeaderFiles/Game.h"

void Connect4::CheckForWin(int i, int j)
{
	if (Horizontal(i, j) || Vertical(i, j) || LeftDiagonal(i, j) || RightDiagonal(i, j))
	{
		gameOver = true;
		return;
	}
}

bool Connect4::Horizontal(int i, int j)
{
	int horizontal = 0;
	for (int k = 0; k < n; k++)
	{
		if (horizontal + (n - k) >= 4)
		{
			if (board[i][k] == board[i][j])
			{
				horizontal++;
				if (horizontal == 4)
				{
					return true;
				}
			}
			else
			{
				horizontal = 0;
			}
		}
		else
		{
			break;
		}
	}
	return false;
}

bool Connect4::Vertical(int i, int j)
{
	int vertical = 0;
	for (int k = 0; k < m; k++)
	{
		if (vertical + m - k >= 4)
		{
			if (board[k][j] == board[i][j])
			{
				vertical++;
				if (vertical == 4)
				{
					return true;
				}
			}
			else
			{
				vertical = 0;
			}
		}
		else
		{
			break;
		}
	}
	return false;
}

bool Connect4::LeftDiagonal(int i, int j)
{
	int count = 0, dRow = i, dCol = j;
	while (dRow != 0 && dCol != 0)
	{
		dRow--;
		dCol--;
	}
	while (dRow <= 5 && dCol <= 6)
	{
		if (board[dRow][dCol] == board[i][j])
		{
			count++;
			if (count == 4)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
		dRow++;
		dCol++;
	}
	return false;
}
bool Connect4::RightDiagonal(int i, int j)
{
	int count = 0, dRow = i, dCol = j;
	while (dRow != 0 && dCol != n)
	{
		dRow--;
		dCol++;
	}

	while (dRow <= 5 && dCol >= 0)
	{
		if (board[dRow][dCol] == board[i][j])
		{
			count++;
			if (count == 4)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
		dRow++;
		dCol--;
	}

	return false;
}