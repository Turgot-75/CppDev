#pragma once
#include <vector>

enum class Weaks
{
	BEAM, WAVE_BEAM, PLASMA_BEAM, ICE_BEAM, MISSILE, SUPER_MISSILE, POWER_BOMB
};

class Mob {
protected:
	double a_hp;
	std::vector<Weaks> a_listed;
	double a_damage;
public:
	bool a_isFrozen;
	Mob();
	Mob(double hp, double damage, std::initializer_list<Weaks> weaks);
	virtual ~Mob();
	virtual std::vector<Weaks> getWeaks();
	virtual void damaged(double damage);
	virtual double getDamage();
	virtual double getHp();
	virtual bool isDead();
};

class Metroid : public Mob
{
	double a_hp;
	double a_damage;
	std::vector<Weaks> a_listed;
public:
	bool a_isFrozen;

	Metroid(double hp, double damage);
	std::vector<Weaks> getWeaks() override;
	void damaged(double damage) override;
	void freeze();
	double getDamage() override;
	double getHp() override;
	bool isDead() override;
};

class Pirate : public Mob
{
	double a_hp;
	std::vector<Weaks> a_listed;
	double a_damage;
public:
	Pirate();
	Pirate(double hp, double damage, std::initializer_list<Weaks> weaks);
	std::vector<Weaks> getWeaks() override;
	void damaged(double damage) override;
	double getDamage() override;
	double getHp() override;
	bool isDead() override;
};

class Samus { 
	double energie = 100.0;
	double maxEnergie = 600.0;
public:
	Samus();
	void useBeam(Mob& mob);
	void useWave(Mob& mob);
	void usePlasma(Mob& mob);
	void useIce(Mob& mob);
	void useMissile(Mob& mob);
	void useSuperMissile(Mob& mob);
	void usePowerBomb(Mob& mob);
	void attacked(Mob& mob);
	double getEnergie();
	void addEnergie();
	bool isDead() const;
};
