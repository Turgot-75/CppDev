#pragma once
#include <string>

struct Player
{
	std::string n_name;
	double n_pv;
	double n_damage;
	double n_exp;

	bool isDead();
	void Attack(Player& other);
};