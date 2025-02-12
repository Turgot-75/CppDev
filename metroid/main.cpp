#include <iostream>
#include <string>
#include "Metroid.hpp"

int main()
{
	Samus samus = Samus();

	Metroid metroid = Metroid(15.0, 5.0);

	Pirate pirate = Pirate();

	samus.attacked(pirate);
	std::cout << samus.getEnergie() << std::endl;
	
	samus.usePowerBomb(pirate);
	std::cout << pirate.getHp() << std::endl;
	samus.useSuperMissile(pirate);
	std::cout << pirate.getHp() << std::endl;
	samus.useSuperMissile(pirate);
	std::cout << pirate.getHp() << std::endl;

	std::cout << pirate.isDead() << std::endl;
	
	samus.addEnergie();
	std::cout << samus.getEnergie() << std::endl;

	samus.attacked(metroid);
	std::cout << samus.getEnergie() << std::endl;
	std::cout << metroid.getHp() << std::endl;

	samus.useIce(metroid);
	std::cout << metroid.a_isFrozen << std::endl;
	
	samus.useSuperMissile(metroid);
	samus.useSuperMissile(metroid);
	samus.useSuperMissile(metroid);
	std::cout << "Pv metroid : " << metroid.getHp() << std::endl;

	std::string dead = std::to_string(metroid.isDead());
	std::cout << "Le Metroid est mort ? : " << dead << std::endl;

	Metroid metroidMega = Metroid(1000.0, 200.0);

	samus.attacked(metroidMega);

	std::cout << samus.isDead() << std::endl;
	
    return 0;
}