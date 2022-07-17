#include "../HeaderFiles/Game.h"

int main()
{
	std::string name1, name2;
	std::cout << "\nEnter name of the first Player\n";
	std::cin >> name1;
	std::cout << "\nEnter name of the second Player\n";
	std::cin >> name2;

	Connect4* connect4 = new Connect4(name1, name2);
}