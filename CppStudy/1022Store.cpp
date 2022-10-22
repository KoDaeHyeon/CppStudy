#include "1022Store.h"
#include "iostream"
#include "1022Guest.h"
using namespace std;
Store::Store(const char* v, const char* t, const char* p, const char* f, int c) {
	EditVetableName(v);
	EditToyName(t);
	EditPencilName(p);
	EditFoodName(f);
	EditCount(c);
}
Store::~Store() {
	//제거하면 에러? 해결책 찾기
	free(this->vegetable); //동적 할당을 했으면 끝날때 풀어줘야함
	free(this->toy);
	free(this->pencil);
	free(this->food);
	cout << "Store 삭제 " << endl;
}

void Store::EditVetableName(const char* v) {
	CopyString(&this->vegetable, v);
}

void Store::EditToyName(const char*t) {
	CopyString(&this->toy, t);
}

void Store::EditPencilName(const char*p) {
	CopyString(&this->pencil, p);
}

void Store::EditFoodName(const char* f) {
	CopyString(&this->food, f);
}

void Store::EditCount(const int c) {
	this->cellcount = c;
}

void Store::CopyString(char** dest, const char* src)
{	//value의 주소값이 아닌 (this->value)의 주소값을 가져오기때문에 이중 포인터를 쓴다
	//Edit함수에 직접 넣을때는 일반 포인터로 가능
	//배열은 바로 안들어가서 따로 strcpy_s해줘야함 
	
	*dest = new char[strlen(src)];
	strcpy_s(*dest, strlen(src) + 1, src);
}

void Store::PrintInfo() {
	cout << "------------------------------------------------" << endl;
	cout << "vegetable : " << getVetableName() << endl;
	cout << "Toy : " << getToyName() << endl;
	cout << "Pencil : " << getPencilName() << endl;
	cout << "Food : " << getFoodName() << endl;
	cout << "CellCount : " << getCount() << endl;
	cout << "------------------------------------------------" << endl;
}

bool Store::Cell(Guest* guest, const int cost) {
	if (guest->GetMoney() < cost)
		return false;
	cellcount++;
	guest->EditMoney(guest->GetMoney() - cost);
	return true;
}

void Store::CellProducts(Guest* guest, const char *string, const int cost) {

	if (!strcmp(getVetableName(), string)||
		!strcmp(getToyName(), string)||
		!strcmp(getPencilName(), string)||
		!strcmp(getPencilName(), string)||
		!strcmp(getFoodName(), string))
	{
		if (Cell(guest, cost))
		{
			cout << string << "를 샀다." << endl;
			cout << "가격 : " << cost << endl;
			cout << "남은 돈 : " << guest->GetMoney() << endl;
		}
		else
		{
			cout << "돈이 " << guest->GetMoney() - cost << "원이 부족하다." << endl;
			cout << "물품 : " << string << endl;
			cout << "가격 : " << cost << endl;
			cout << "남은 돈 : " << guest->GetMoney() << endl;
		}
	}
	else
	{
		cout << "물품을 제대로 입력해 주세요!" << endl;
	}
}