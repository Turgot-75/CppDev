#include "Animals.hpp"

#include<iostream>
#include<string>

Animal::Animal(std::string n, int a) : a_nom(n), a_age(a) {}

void Animal::afficherInfo()
{
	std::cout << "Nom : " << a_nom << ", Age : " << a_age << std::endl;
}

std::string Animal::faireDuBruit()
{
	return "GrrGrr";
}

Lion::Lion(std::string n, int a, int poils) : Animal(n, a), l_nombre_de_criniere(poils) {}

void Lion::afficherInfo()
{
	std::cout << "Nom : " << a_nom << ", Age : " << a_age << ", Criniere : " << l_nombre_de_criniere << std::endl;
}

std::string Lion::faireDuBruit()
{
	return "Roar";
}

Perroquet::Perroquet(std::string n, int a, std::string c) : Animal(n, a), p_couleur(c) {}

void Perroquet::afficherInfo()
{
	std::cout << "Nom : " << a_nom << ", Age : " << a_age << ", Couleur : " << p_couleur << std::endl;
}

std::string Perroquet::faireDuBruit()
{
	return "Koui";
}

void ajouterAnimal(std::vector<Animal*>& animalsVec, bool isParrot, std::string n, int a, std::string c, int poils)
{
	if (isParrot)
	{
		Perroquet* Ptrparrot = new Perroquet(n, a, c);
		animalsVec.push_back(Ptrparrot);
	}
	else
	{
		Lion* Ptrlion = new Lion(n, a, poils);;
		animalsVec.push_back(Ptrlion);
	}
}

void afficherTousLesAnimaux(const std::vector<Animal*>& animalsVec)
{
	for (Animal* PtrAnimaux : animalsVec)
	{
		PtrAnimaux->afficherInfo();
	}
}

void faireBruitsDansLeZoo(const std::vector<Animal*>& animalsVec)
{
	for (Animal* PtrAnimaux : animalsVec)
	{
		std::cout << PtrAnimaux->faireDuBruit() << std::endl;
	}
}