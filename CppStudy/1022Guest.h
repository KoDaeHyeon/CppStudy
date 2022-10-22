#pragma once
class Store;

class Guest
{
private:
	char* name;
	int money;
public:
	Guest(const char* name, int money);
	~Guest();
	void EditName(const char * name);
	void EditMoney(const int money);
	const int GetMoney();
	void PerchaseObject(Store *store, const char* string, int cost);

};

