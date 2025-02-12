#include <iostream>

int main()
{
	std::cout << "Entrez un entier pour voir sa factoriel : ";
	int input = 0;
	std::cin >> input;

	if (input == 0) {
		std::cout << "0! = 1" << std::endl;
		return 0;
	}
	else
	{
		int result = input;
		std::cout << "!" << input << " = " << input << " x ";

		for (int i = input - 1; i > 1; i--)
		{
			std::cout << i << " x ";
			result = result * i;
		}

		std::cout << "1 = " << result << std::endl;
	}
	return 0;
}