#include <iostream>
#include "Animal.h"

using namespace std;

int main()
{
	char c[20] = "duggy";
	Animal* animal = new Animal(c,10);
	
	cout << "���� ����" << endl;
	animal->PrintInfo();

	cout << "������ �̸� : ";
	cin >> c;
	animal->SetName(c);

	int a;
	cout << "������ ���� : ";
	cin >> a;

	animal->SetAge(a);

	cout << "=================================" << endl;
	animal->PrintInfo();
	cout << "=================================" << endl;

	delete animal;
}