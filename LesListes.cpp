#include <iostream>
#include <list>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8); //Permet les accents

	std::list<int> myList = {};
	std::list<int>::iterator it = myList.begin();

	int saisie = 0;
	std::cout << "Bonjour veuillez entrer une note entre 0 et 20 : ";
	std::cin >> saisie;

	while (saisie >= 0 && saisie <= 20)
	{
		myList.insert(it, saisie);
		std::cout << "Bonjour veuillez entrer une note entre 0 et 20 : ";
		std::cin >> saisie;
	}
	std::cout << "Nombre négatif saisis, arrêt de la saisie" << std::endl;
	std::cout << "Nombres saisie dans l'ordre : " << std::endl;

	for (int i : myList)
	{
		std::cout << i << " | ";
	}

	std::cout << std::endl;
	std::cout << "Saissisez un nombre à supprimer";
	int supression = 0;
	std::cin >> supression;
	std::cout << "Supression..." << std::endl;
	myList.remove(supression);
	std::cout << "Affichage apres supression..." << std::endl;
	for (int i : myList)
	{
		std::cout << i << " | ";
	}

	std::cout << "Nombres saisie dans l'ordre inverse : " << std::endl;
	for (std::list<int>::reverse_iterator rit = myList.rbegin(); rit != myList.rend(); ++rit)
	{
		std::cout << *rit << " | ";
	}
}