#pragma once
class Guest;
class Store
{
private:
	char* vegetable;
	char* toy;
	char* pencil;
	char* food;
	int cellcount;

public:
	//문자열 매개변수에서 const를 해줘야함
	Store(const char* v, const char* t, const char* p, const char* f, int c);
	~Store();
	void EditVetableName(const char*v);
	void EditToyName(const char*t);
	void EditPencilName(const char*p);
	void EditFoodName(const char* f);
	void EditCount(const int c);

	void PrintInfo();
	void CopyString(char** dest, const char* src);

	const char* getVetableName() { return vegetable; };
	const char* getToyName() { return toy; };
	const char* getPencilName() { return pencil; };
	const char* getFoodName() { return food; };
	const int getCount() { return cellcount; };
	
	bool Cell(Guest* guest, const int cost);
	void CellProducts(Guest* guest, const char *string, const int cost);
};

