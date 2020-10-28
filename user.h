#pragma once
#include <string>
#include "iostream"
#include <conio.h>
//Am creat o clasa ce reprezinta utilizatorul programului.
class user
{
private:
	const std::string* m_userName;
	const std::string* m_password;
public:
	//Constructor clasa user;
	user(const std::string& user,const std::string& password);
	//Destructor;
	~user();
	//Functie de verificare user si parola;
	//Return TRUE  #Check user/parola incorect;
	bool verificare(std::string& user, std::string& password);
	


};

