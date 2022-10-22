#include "1022Guest.h"
#include "1022Store.h"
#include <iostream>

using namespace std;

Guest::Guest(const char* name, int money):money(money){
	EditName(name);
}

Guest::~Guest(){

}

void Guest::EditName(const char* name)
{
	this->name = new char[strlen(name)];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Guest::EditMoney(const int money)
{
	this->money = money;
}

const int Guest::GetMoney()
{
	return this->money;
}

void Guest::PerchaseObject(Store* store, const char* string, int cost)
{
	
	cout << "------------------------------------------------" << endl;
	store->CellProducts(this, string, cost);
	cout << "------------------------------------------------" << endl;
		
}

