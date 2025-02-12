#include <vector>
#include <iostream>
#include "Metroid.hpp"

/*enum class Weaks
{
	BEAM, WAVE_BEAM, PLASMA_BEAM, ICE_BEAM, MISSILE, SUPER_MISSILE, POWER_BOMB
};*/

void useWeaponable(Mob& mob, Weaks weak, double damage)
{
	for (Weaks w : mob.getWeaks())
	{
		if (w == weak)
		{
			mob.damaged(damage);
		}
	}
}

//SAMUS
Samus::Samus() {}

void Samus::useBeam(Mob& mob)
{
	useWeaponable(mob, Weaks::BEAM, 0.5);
}

void Samus::useIce(Mob& mob)
{
	Metroid* metroid = dynamic_cast<Metroid*>(&mob);

	if (metroid != nullptr)
	{
		metroid->freeze();
	}
	else
	{
		useWeaponable(mob, Weaks::ICE_BEAM, 1.0);
	}
}

void Samus::useWave(Mob& mob)
{
	useWeaponable(mob, Weaks::WAVE_BEAM, 1.5);
}

void Samus::usePlasma(Mob& mob)
{
	useWeaponable(mob, Weaks::PLASMA_BEAM, 2.0);
}

void Samus::useMissile(Mob& mob)
{
	useWeaponable(mob, Weaks::MISSILE, 2.5);
}

void Samus::useSuperMissile(Mob& mob)
{
	useWeaponable(mob, Weaks::SUPER_MISSILE, 5.0);
}

void Samus::usePowerBomb(Mob& mob)
{
	useWeaponable(mob, Weaks::POWER_BOMB, 10.0);
}

void Samus::attacked(Mob& mob)
{
	energie = energie - mob.getDamage();
}

double Samus::getEnergie()
{
	return energie;
}

void Samus::addEnergie()
{
	if (energie <= maxEnergie)
	{
		energie = energie + 100.0;
	}
}

bool Samus::isDead() const
{
	return energie <= 0;
}

Metroid::Metroid(double hp, double damage) : a_hp(hp), a_damage(damage), a_isFrozen(false), a_listed({ Weaks::ICE_BEAM }) {}

void Metroid::damaged(double damage)
{
	if (!a_isFrozen)
	{
		std::cout << "Le Metroid n'a recu aucun degats car il n'est pas geler." << std::endl;
	}
	else
	{
		std::cout << "Le Metroid a recu " << damage << " degats car il est geler." << std::endl;
		a_hp = a_hp - damage;
	}
}

std::vector<Weaks> Metroid::getWeaks()
{
	return a_isFrozen ? std::vector<Weaks>{Weaks::MISSILE, Weaks::SUPER_MISSILE, Weaks::POWER_BOMB} : a_listed;
}

double Metroid::getDamage()
{
	return this->a_damage;
}

double Metroid::getHp()
{
	return this->a_hp;
}

bool Metroid::isDead()
{
	return a_hp <= 0;
}

void Metroid::freeze()
{
	a_isFrozen = true;
	std::cout << "Le Metroid est maintenant gelé !" << std::endl;
}

Pirate::Pirate(double hp, double damage, std::initializer_list<Weaks> weaks) : a_hp(hp), a_damage(damage), a_listed(weaks) {}

Pirate::Pirate() : Pirate(20.0, 5.0, { Weaks::BEAM, Weaks::ICE_BEAM, Weaks::MISSILE, Weaks::PLASMA_BEAM, Weaks::POWER_BOMB,
Weaks::SUPER_MISSILE, Weaks::WAVE_BEAM }) {}

void Pirate::damaged(double damage)
{
	this->a_hp = this->a_hp - damage;
}

double Pirate::getDamage()
{
	return this->a_damage;
}

double Pirate::getHp()
{
	return a_hp;
}

std::vector<Weaks> Pirate::getWeaks()
{
	return a_listed;
}

bool Pirate::isDead()
{
	return a_hp <= 0.0;
}

Mob::Mob(double hp, double damage, std::initializer_list<Weaks> weaks) : a_hp(hp), a_damage(damage), a_listed(weaks), a_isFrozen(false) {}

Mob::Mob() : Mob(20.0, 2.0, { Weaks::BEAM, Weaks::ICE_BEAM, Weaks::MISSILE, Weaks::PLASMA_BEAM, Weaks::POWER_BOMB,
	Weaks::SUPER_MISSILE, Weaks::WAVE_BEAM }) {}

Mob::~Mob()
{
	std::cout << "delete obj Mob" << std::endl;
}

void Mob::damaged(double damage)
{
	a_hp -= damage;
}

double Mob::getDamage()
{
	return a_damage;
}

double Mob::getHp()
{
	return a_hp;
}

bool Mob::isDead()
{
	return a_hp <= 0;
}

std::vector<Weaks> Mob::getWeaks()
{
	return a_listed;
}