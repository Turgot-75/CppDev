#include <iostream>
#include <string>
#include <vector>
#include "Animals.hpp"

int main()
{
	std::vector<Animal*> zoo = {};
	int choix = 0;

	while (choix != 5)
	{
		std::cout << "Bienvenue dans le Zoo de Paris !" << std::endl;
		std::cout << "Bonjour Chef que voulez vous faire ?" << std::endl;

		std::cout << "1. Ajouter un Lion" << std::endl;
		std::cout << "2. Ajouter un Perroquet" << std::endl;
		std::cout << "3. Afficher tous les animaux" << std::endl;
		std::cout << "4. Faire du bruit dans le zoo" << std::endl;
		std::cout << "5. Quitter" << std::endl;
		std::cout << "-> ";
		std::cin >> choix;

		std::string nom = "";
		int age = 0;
		int criniere = 0;
		std::string couleur ="";

		switch (choix)
		{
		case 1:
			std::cout << "Entrez le nom du lion : ";
			std::cin >> nom;
			std::cout << "Entrez l'âge du lion : ";
			std::cin >> age;
			std::cout << "Entrez le nombre de poils dans la crinière : ";
			std::cin >> criniere;
			ajouterAnimal(zoo, false, nom, age, "Savanne", criniere);
			break;
		case 2:
			std::cout << "Entrez le nom du perroquet : ";
			std::cin >> nom;
			std::cout << "Entrez l'âge du perroquet : ";
			std::cin >> age;
			std::cout << "Entrez la couleur du perroquet : ";
			std::cin >> couleur;
			ajouterAnimal(zoo, true, nom, age, couleur, 0);
			break;
		case 3:
			afficherTousLesAnimaux(zoo);
			break;
		case 4:
			faireBruitsDansLeZoo(zoo);
			break;
		}
		choix = 0;
	}
	
	std::cout << "Au revoir" << std::endl;

	bool debug = true;
	for (Animal* an : zoo)
	{
		delete an;
	}
	zoo.clear();
	return 0;
}