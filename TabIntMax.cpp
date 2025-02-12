#include <iostream>
#include <string>

#define String std::string

int main()
{
	std::cout << "Combien de valeur voulez vous entrer : ";
	int max;
	std::cin >> max;
	int* tab = new int[max];
	int nbGrand = 0;

	for (int i = 0; i < max; i++)
	{
		std::cout << "Entrez la valeur " << (i+1) << " : ";
		std::cin >> tab[i];
	}

	for (int i = 0; i < max; i++)
	{
		if (tab[i] > nbGrand)
		{
			nbGrand = tab[i];
		}
	}

	std::cout << "La valeur max est : " << nbGrand << std::endl;
	delete[] tab;
	std::cin.ignore();
	return 0;
}