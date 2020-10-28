
#include <iostream>
#include "ContBancar.h"
#include "Banca.h"
#include "user.h"

int main()
{
	// Start Here.	
	bool running = true;
	// Instantiere obiect itBank de tip banca pe memoria Heap.
	Banca* itBank = new Banca();  
	//Setare userName si password pentru utilizatorul programului.
	std::string userName = "Admin";
	std::string password = "LetMeIn";
	// Instantiere obiect user cu username si parola.
	user* User = new user(userName, password);
	// Variabila globala in care tinem optiunea selectata de utilizator.
	int optiuneUser = 0;
	// Variabile pentru a stoca user si parola introdus de utilizator in consola.
	std::string user;
	std::string pass;

	// Se verifica userul si parola; Daca nu sunt corecte se repeta bucla.
	do {
		PRINT("Bine ati venit!")
		PRINT("###########################");
		PRINT("-> Introduceti username: ");
		std::cin >>user;
		PRINT("-> Introduceti parola: ");
		std::cin >> pass;

	} while (!(User->verificare(user,pass)));
		
	/* Bucla cu meniul principal, optiunile disponibile pentru utilizator */
	do
		{
			system("cls");
			std::cout << "Panou de Lucru:" << std::endl;
			std::cout << "############################" << std::endl;
			std::cout << "MAIN MENU" << std::endl;
			std::cout << "0: Creare cont nou. " << std::endl;
			std::cout << "1: Numar de conturi inregistrate." << std::endl;
			std::cout << "2: Vizualizare Cont." << std::endl;
			std::cout << "3: Modificare Cont. " << std::endl;
			std::cout << "4: Operatii Sold." << std::endl;
			std::cout << "" << std::endl;
			std::cout << "9: Exit." << std::endl;
			std::cout << "############################" << std::endl;
			
			std::cout << "Va rugam selectati o optiune" << std::endl;
			std::cin >> optiuneUser;
			std::cin.ignore();
			system("cls");

			// In functie de optiunea utilizatorului folosim metoda dorita (Switch).
			switch (optiuneUser)
			{
			case 0:
				itBank->AdaugareCont();
				break;
			case 1:
				itBank->PrintConturi();
				break;
			case 2:
			// Functie cautare cont dorit de utilizator, daca nu exista exista optiune creare cont nou.

				if (itBank->CautareCont())
				{ std::cout << "Cont gasit:" << std::endl; }
				else
				{					
					PRINT("Numele nu a fost gasit!");
					PRINT("############################");
					PRINT("Pentru creare cont apasati tasta 0.");
					PRINT("Pentru intoarcerea la meniul principal apasati tasta 1.");
					itBank->ContNou();
					break;
				}
				break;
			case 3:
				itBank->ModificareCont();
				break;
			case 4:
				itBank->OperatiiSold();
				break;
				case 9:
				std::cout << "O zi buna sa aveti!\n";
				running = false;
				break;

			default:
				break;
			}			
		} while (running);

	delete itBank;	
}









	





