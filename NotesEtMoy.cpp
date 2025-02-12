#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8); //Permet les accents
	int maxNotes;
	std::cout << "Combien de notes souhaitez vous entrer : ";
	std::cin >> maxNotes;

	double* notes = new double[maxNotes];
	double somme = 0;

	for (int i = 0; i < maxNotes; i++)
	{
		double noteCin = -1;
		do {
			std::cout << "Veuillez entrer une note entre 0 et 20 : ";
			std::cin >> noteCin;
		} while (noteCin < 0 || noteCin > 20);
		notes[i] = noteCin;
		somme = somme + noteCin;
	}

	double moyenne = somme / maxNotes;
	std::cout << "La Moyenne de ces notes est : " << moyenne << std::endl;

	delete[] notes;
}