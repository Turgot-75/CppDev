#pragma once
#include <string>
#include <vector>

class Animal {
protected:
	std::string a_nom;
	int a_age;
public:
	Animal(std::string n, int a);
	virtual ~Animal() {}
	virtual void afficherInfo();
	virtual std::string faireDuBruit();
};

class Lion : public Animal {
private:
	int l_nombre_de_criniere;
public:
	Lion(std::string n, int a, int poils);
	void afficherInfo() override;
	std::string faireDuBruit() override;
};

class Perroquet : public Animal {
private:
	std::string p_couleur;
public:
	Perroquet(std::string n, int a, std::string c);
	void afficherInfo() override;
	std::string faireDuBruit() override;
};

void ajouterAnimal(std::vector<Animal*>& animalsVec, bool isParrot, std::string n, int a, std::string c, int poils);

void afficherTousLesAnimaux(const std::vector<Animal*>& animalsVec);

void faireBruitsDansLeZoo(const std::vector<Animal*>& animalsVec);