#pragma once
#include<iostream>
#include<vector>
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