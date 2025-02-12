#include <iostream>

int main()
{
	unsigned size = 0;
	const char fir = '*';
	const unsigned min = 5;
	const unsigned max = 25;

	std::cout << "Entrez la taille du sapin souhaiter : ";
	std::cin >> size;

	if (size < min || size > max)
	{
		std::cout << "Taille incorrecte" << std::endl;
		return -1;
	}

	char** tab = new char* [size];

	for (int i = 0; i < size; i++)
	{
		tab[i] = new char[size];
	}

	for (int i = 0; i < size; i++)
	{
		int othersize = size - (i + i);
		unsigned a = 2 * i;
		unsigned b = size - i - 1;

		for (unsigned k = 0; k < b; k++)
		{
			std::cout << ' ';
		}

		for (unsigned k = 0; k < a; k++)
		{
			std::cout << fir;
		}
		std::cout << std::endl;
	}

	std::cin.ignore();
	for (int i = 0; i < size; ++i) {
		delete[] tab[i];
	}
	delete[] tab;
	return 0;
}