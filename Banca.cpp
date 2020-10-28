#include "Banca.h"
#include <string>
#include <iostream>
#include "ContBancar.h"


void Banca::print(std::string message)
{
	std::cout << message << std::endl;
}
Banca::Banca()

{	
}


void Banca::AdaugareCont()
{
	// Userul trebuie sa introduca un prenume, nume , iban, tipcont
	
	std::string nume, prenume;
	int iban;
	int tipCont;
	TIPMONEDA tipMoneda;

	//Nume de introdus 
	print("Introduceti un nume :");
	std::cin >> nume;
	std::cin.ignore();
	
	//Prenume de introdus 
	print("Introduceti un prenume :");
	std::cin >> prenume;
	std::cin.ignore();
	
	//IBan de introdus 
	print("Introduceti un IBan :");
	std::cin >> iban;
	std::cin.ignore();

	//Tip de cont de introdus 
	print("Introduceti un tip de cont: 0 = RON; 1 = EURO ");
	std::cin >> tipCont;
	std::cin.ignore();
		   
	if (tipCont == 0) 
	{
		tipMoneda = RON; 
	}
	else
	{
		tipMoneda = EUR;
	}


	ContBancar cont = ContBancar(nume, prenume, iban, tipMoneda);
	m_Conturi.push_back(cont);

}

void Banca::PrintConturi()
{

	int numarConturi = m_Conturi.size();
	PRINT("Numarul de conturi active este: ");
	PRINT(numarConturi);
	int returnValue = -1;
	do {
		PRINT("Apasati tasta 0 pentru intoarcere la meniul principal");
		std::cin >> returnValue;

	} while (returnValue != 0);

	
}

bool Banca::CautareCont()
{
	std::string numeCautat;
	PRINT("Va rugam introduceti numele dorit: ");
	std::cin >> numeCautat;
	std::string prenumeCautat;
	PRINT("Va rugam introduceti prenumele dorit: ");
	std::cin >> prenumeCautat;

	for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
	{
		if (it->VerificareNume(numeCautat,prenumeCautat))
		{
			it->AfisareInfo();
			PRINT("Apasati enter pentru a va intoarce la meniul anterior..");
			_getch();
			return true;
		}
		
	}

	return false;
}

void Banca::ContNou()
{	//Variabila pentru a prelua user input.
	int creareCont = 1;
	std::cin >> creareCont;
	//Verificam daca userul vrea sa adauge un cont nou.
	if (creareCont == 0) {

		//Adaugam cont nou.
		AdaugareCont();		
	}
	else
	{
		PRINT("Ne intoarcem la meniul principal.");		
	}
		 
}

ContBancar Banca::CautareCont(std::string& nume,std::string& prenume)
{
	// Un cont in care vom tine informatiile cautate.
	ContBancar contCautat;
	//Cautam contul cu numele dat.

	for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
	{
		//Daca exista contul cautat it va deveni cont cautat.
		if (it->VerificareNume(nume,prenume))
		{
			contCautat = *it;
			break;
		}

	}

	return contCautat;
	
}

	bool Banca::ModificareCont()
{
	PRINT("Introduceti numele contului ce doriti sa il modificati:");

	std::string nume;
	std::cin >> nume;
	PRINT("Introduceti prenume contului ce doriti sa il modificati:");

	std::string prenume;
	std::cin >> prenume;
	ContBancar contEditat = CautareCont(nume,prenume);
	if(contEditat.getNume() != "Necunoscut")
	{
	PRINT("Contul a fost gasit: ");
	contEditat.AfisareInfo();

	PRINT("Modificati numele:");
	std::string numeNou;
	std::cin >> numeNou;
	contEditat.modificareNume(numeNou);

	for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
	{
		if (it->getNume() == nume)
		{
			it->modificareNume(numeNou);
			return true;
		}

	}
	   
	}
	else
	{
		PRINT("Contul nu a fost gasit:");
		return false;
	}
	
}

	void Banca::OperatiiSold()
	{   /* Pasul 1. Cerem Operatorului numele si prenumele pentru soldul care vrem sa facem modificari.
		   Pasul 2. (Daca contul a fost gasit) sa cerem operatorului ce modificari vrea sa faca _
		   si sa le facem cu ajutorul functiilor din clasa Sold ). */
		std::string nume;
		std::string prenume;
		PRINT("Introduceti numele clientului: ")
			std::cin >> nume;
		PRINT("Introduceti prenumele clientului:")
			std::cin >> prenume;

		for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
		{

			int optiune;
			if(it->VerificareNume(nume,prenume))
			{					
				PRINT("Operatii Sold posibile: ");
				PRINT("Tasta 0: Afisare Sold.");
				PRINT("Tasta 1: Depunere numerar.");
				PRINT("Tasta 2: Retragere numerar. ");
				std::cin >> optiune;
				switch (optiune)
				{
				case 0:
					it->VizualizareSold();
					break;					
				case 1:
					it->DepunereNumerar();
					break;		
				case 2: 
					it->RetragereNumerar();
					break;										
				default:
					break;
				}
			
			}

		}

	}





