#pragma once
#include "ContBancar.h"
#include <vector>
#include <string>
#include <conio.h>
#define PRINT(x) std::cout << x << std::endl;
class Banca
{

private:
	std::vector<ContBancar> m_Conturi;
	void print(std::string message);

public:
	Banca();
	//Metoda de adaugat cont.
	void AdaugareCont();
	//Metoda de afisare cont.
	void PrintConturi();
	//Metoda de cautare cont.
	bool CautareCont();
	ContBancar CautareCont(std::string& nume,std::string& prenume);
	//Deschidere cont.
	void ContNou();
	//Metoda de modificare cont.
	bool ModificareCont();
	//Metoda de operatii pe sold.
	void OperatiiSold();

};

