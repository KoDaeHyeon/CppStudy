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
	//�����ϸ� ����? �ذ�å ã��
	free(this->vegetable); //���� �Ҵ��� ������ ������ Ǯ�������
	free(this->toy);
	free(this->pencil);
	free(this->food);
	cout << "Store ���� " << endl;
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
{	//value�� �ּҰ��� �ƴ� (this->value)�� �ּҰ��� �������⶧���� ���� �����͸� ����
	//Edit�Լ��� ���� �������� �Ϲ� �����ͷ� ����
	//�迭�� �ٷ� �ȵ��� ���� strcpy_s������� 
	
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
			cout << string << "�� ���." << endl;
			cout << "���� : " << cost << endl;
			cout << "���� �� : " << guest->GetMoney() << endl;
		}
		else
		{
			cout << "���� " << guest->GetMoney() - cost << "���� �����ϴ�." << endl;
			cout << "��ǰ : " << string << endl;
			cout << "���� : " << cost << endl;
			cout << "���� �� : " << guest->GetMoney() << endl;
		}
	}
	else
	{
		cout << "��ǰ�� ����� �Է��� �ּ���!" << endl;
	}
}