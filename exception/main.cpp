#include <iostream>

class MontantInvalideException : public std::runtime_error
{
public:
	MontantInvalideException() : std::runtime_error("Le Montant du depot ou du retrait ne peut pas etre negatif") {}
};

class SoldeInsuffisantException : public std::runtime_error
{
public:
	SoldeInsuffisantException() : std::runtime_error("Le solde est insuffisant") {}
};

class CompteBancaire
{
	double solde;
public:
	CompteBancaire(double s)
	{
		this->solde = s;
	}

	void depot(double montant)
	{
		if (montant < 0)
		{
			throw MontantInvalideException();
		}
		this->solde = this->solde + montant;
	}

	void retrait(double montant)
	{
		if (montant < 0)
		{
			throw MontantInvalideException();
		}
		if (this->solde - montant < 0)
		{
			throw SoldeInsuffisantException();
		}
		this->solde = this->solde - montant;
	}

	void afficherSolde()
	{
		std::cout << "Solde du compte bancaire : " << this->solde << std::endl;
	}
};

int main() {
    CompteBancaire compte(100.0);  // Compte initialisé avec 100 euros
    int choix;
    double montant;

    std::cout << "Bienvenue dans votre compte bancaire !" << std::endl;

    do {
        std::cout << "\nMenu : " << std::endl;
        std::cout << "1. Déposer de l'argent" << std::endl;
        std::cout << "2. Retirer de l'argent" << std::endl;
        std::cout << "3. Afficher le solde" << std::endl;
        std::cout << "4. Quitter" << std::endl;
        std::cout << "Entrez votre choix : ";
        std::cin >> choix;

        try {
            switch (choix) {
            case 1:
                std::cout << "Entrez le montant à déposer : ";
                std::cin >> montant;
                compte.depot(montant);
                std::cout << "Dépôt réussi !" << std::endl;
                break;

            case 2:
                std::cout << "Entrez le montant à retirer : ";
                std::cin >> montant;
                compte.retrait(montant);
                std::cout << "Retrait réussi !" << std::endl;
                break;

            case 3:
                compte.afficherSolde();
                break;

            case 4:
                std::cout << "Merci d'avoir utilisé notre service bancaire." << std::endl;
                break;

            default:
                std::cout << "Choix invalide, veuillez réessayer." << std::endl;
                break;
            }
        }
        catch (const MontantInvalideException& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const SoldeInsuffisantException& e) {
            std::cerr << e.what() << std::endl;
        }
    } while (choix != 4);

    return 0;
}