#include <iostream>
#include "Animal.h"

using namespace std;

int main()
{
	char c[20] = "duggy";
	Animal* animal = new Animal(c,10);
	
	cout << "현재 정보" << endl;
	animal->PrintInfo();

	cout << "변경할 이름 : ";
	cin >> c;
	animal->SetName(c);

	int a;
	cout << "변경할 나이 : ";
	cin >> a;

	animal->SetAge(a);

	cout << "=================================" << endl;
	animal->PrintInfo();
	cout << "=================================" << endl;

	delete animal;
}