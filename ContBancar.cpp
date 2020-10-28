#include "ContBancar.h"
#include <iostream>

ContBancar::ContBancar()
{
	m_nume = "Necunoscut";
	m_prenume = "Prenume Necunoscut";
	m_IBAN = 0;
	m_tipCont = RON;
	m_Sold = 0;
}

ContBancar::ContBancar(std::string nume, std::string prenume, int iban, TIPMONEDA tipCont) : m_nume(nume), m_prenume(prenume), m_IBAN(iban), m_tipCont(tipCont),m_Sold(0)
{
	
}

bool ContBancar::VerificareNume(const std::string& numeCautat, const std::string& prenumeCautat)
{
	if (numeCautat == m_nume && prenumeCautat == m_prenume)		
		return true;
	else 
		return false;
}

void ContBancar::AfisareInfo()

{
	std::cout << "############################" << std::endl;
	std::cout << "Nume: " << m_nume << std::endl;
	std::cout << "PreNume: " << m_prenume << std::endl;
	std::cout << "Iban: " << m_IBAN << std::endl;
	std::cout << "Tip Cont: " << m_tipCont << std::endl;
	std::cout << "############################" << std::endl;

}

void ContBancar::DepunereNumerar()
{
	int suma=0;
	std::cout << "Introduceti suma de depunere: ";
	std::cin >> suma;
	m_Sold += suma;
	std::cout << "Apasati orice tasta pentru a va intoarce la meniu." << std::endl;
	_getch();
}

void ContBancar::RetragereNumerar()
{
	int suma = 0;
	std::cout << "Introduceti suma de retragere: ";
	std::cin >> suma;
	m_Sold -= suma;
	std::cout << "Apasati orice tasta pentru a va intoarce la meniu." << std::endl;
	_getch();
}

void ContBancar::VizualizareSold()
{
	std::cout << "Sold curent: " << m_Sold << std::endl;
	std::cout << "Apasati orice tasta pentru a va intoarce la meniu." << std::endl;
	_getch();
}

