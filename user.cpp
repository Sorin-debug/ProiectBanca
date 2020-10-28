#include "user.h"

user::user(const std::string& user,const  std::string& password):m_userName(&user), m_password(&password)
{
}

user::~user()
{
}

bool user::verificare(std::string& user, std::string& password)
{
	if(user == *m_userName && password == *m_password)
	{
		return true;
	}
	else
	{
		std::cout << "Username sau parola gresita!" << std::endl;
		std::cout << "Apasati Enter pentru a reincerca.. " << std::endl;

		_getch();
		return false;
	}
	
}
