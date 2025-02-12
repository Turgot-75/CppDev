#include <iostream>
#include "Player.hpp"



int main()
{
	Player p1;
	Player p2;
	p1.n_name = "albert";
	p1.n_pv = 20;

	std::cout << p1.n_name << std::endl;

	if (p1.isDead())
	{
		std::cout << "p1 is dead by a dragon" << std::endl;
	}

	p1.n_damage = 2;
	p2.n_pv = 5;

	p1.Attack(p2);

	std::cout << p2.n_pv << std::endl;

	std::cin.ignore();
	return 0;
}