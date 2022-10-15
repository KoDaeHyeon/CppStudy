#include "Animal.h"
#include <iostream>
Animal::Animal(char *Name,int Age) : Age(Age)
{
	for (int i = 0; i < Length; i++)
	{
		this->Name[i] = Name[i];
	}
	std::cout << "����";
}
Animal::~Animal()
{
	 std::cout << "����";
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
	std::cout << "�̸� : " << Name << std::endl;
	std::cout << "���� : " << Age << std::endl;
}