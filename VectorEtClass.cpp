#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#define String std::string

class Etudiant
{
private:
	String nom;
	int age;
	double moyenne;
public:
	Etudiant(String n, int a, double moy)
	{
		this->nom = n;
		this->age = a;
		this->moyenne = moy;
	}

	void afficher()
	{
		std::cout << "l'Etudiant : " << std::endl << "Nom : " << nom << std::endl << "Age : " << age << std::endl << "Moyenne : " << moyenne << std::endl;
	}
};

int main()
{
	SetConsoleOutputCP(CP_UTF8); //Permet les accents
	int maxEtu;
	std::cout << "Combien d'Etudiant souhaitez vous entrer : ";
	std::cin >> maxEtu;

	std::vector<Etudiant> vecEtu = {};
	for (int i = 0; i < maxEtu; i++)
	{
		String nom;
		std::cout << "Entrez le nom de l'Etudiant " << i + 1 << ": ";
		std::cin >> nom;
		std::cout << "Entrez le l'age de l'Etudiant " << i + 1 << " : ";
		int age;
		std::cin >> age;
		std::cout << "Entrez la moyenne de l'Etudiant " << i + 1 << " : ";
		double moyenne;
		std::cin >> moyenne;

		Etudiant etu = Etudiant(nom, age, moyenne);
		etu.afficher();

		vecEtu.push_back(etu);
	}

	std::cout << "Affichage de tout les Etudiants stocker : " << std::endl;

	for (Etudiant e : vecEtu)
	{
		e.afficher();
	}
}