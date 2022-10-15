#pragma once
class Animal
{
private:
	const int Length = 20;
	char Name[20] = {};
	int Age;

public:
	Animal(char* Name, int Age);

	~Animal();

	int GetAge();
	void SetAge(int number);
	char* GetName();
	void SetName(char*name);
	void PrintInfo();
};
