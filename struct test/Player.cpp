#include "Player.hpp"

bool Player::isDead()
{
	return n_pv <= 0;
}

void Player::Attack(Player& other)
{
	other.n_pv -= n_damage;
}
