#pragma once
class Consumer
{
private:
	char* name;
	char* birth;
	char* phoneNumber;
	int age;

public:
	Consumer(const char* name, const char*birth, const char *phoneNumber, int age);
	~Consumer();

	void EditName(const char* n);
	void EditBirth(const char* b);
	void EditPhoneNumber(const char* p);
	void EditAge(int a);

	void CopyString(char** st, const char* c);
	void PrintInfo();

};

