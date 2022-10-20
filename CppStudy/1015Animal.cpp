#include "Animal.h"
#include <iostream>
Animal::Animal(char *Name,int Age) : Age(Age)
{
	for (int i = 0; i < Length; i++)
	{
		this->Name[i] = Name[i];
	}
	std::cout << "생성";
}
Animal::~Animal()
{
	 std::cout << "삭제";
}
int Animal::GetAge()
{
	return Age;
}
void Animal::SetAge(int Age)
{
	this->Age = Age;
}
char* Animal::GetName() 
{
	return Name;
}

void Animal::SetName(char *Name)
{
	for (int i = 0; i < Length; i++)
	{
		this->Name[i] = Name[i];
	}
}
void Animal::PrintInfo()
{
	std::cout << "이름 : " << Name << std::endl;
	std::cout << "나이 : " << Age << std::endl;
}