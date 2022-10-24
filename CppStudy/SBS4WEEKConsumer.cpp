#include "SBS4WEEKConsumer.h"
#include <iostream>

using namespace std;

Consumer::Consumer(const char* name, const char* birth, const char* phoneNumber, int age) : age(age)
{
	EditName(name);
	EditBirth(birth);
	EditPhoneNumber(phoneNumber);
}

Consumer::~Consumer()
{
	if (this->name)delete[] this->name;
	if (this->birth)delete[] this->birth;
	if (this->phoneNumber)delete[] this->phoneNumber;
	cout << "Consummer 삭제" << endl;
}

void Consumer::EditName(const char* n)
{
	CopyString(&this->name, n);
}

void Consumer::EditBirth(const char* b)
{
	CopyString(&this->birth, b);
}

void Consumer::EditPhoneNumber(const char* p)
{
	CopyString(&this->phoneNumber, p);
}

void Consumer::EditAge(int a)
{
	this->age = a;
}

void Consumer::CopyString(char **st, const char * c)
{
	*st = _strdup(c);
}

void Consumer::PrintInfo()
{
	cout << "-----------------------------------------" << endl;
	cout << "이름 : " << this->name << endl;
	cout << "생일 : " << this->birth << endl;
	cout << "핸드폰 : " << this->phoneNumber << endl;
	cout << "나이 : " << this->age << endl;
	cout << "-----------------------------------------" << endl;
}
