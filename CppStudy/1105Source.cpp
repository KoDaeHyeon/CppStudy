#include <iostream>
#include "1105Shape.h"
using namespace std;

//RTTI (Run Time Type Informantion/ Identificion);

class Vector2 {
public:
	float xpos = 1.0f;
	float ypos = 2.0f;
};

class Vector3 : public Vector2 {
public:
	float zpos = 3.0f;
};

void printVector(Vector2 **vec, int length)
{
	for (int index = 0; index < length; index++)
	{
		std::cout << "(" << vec[index]->xpos << ", "
			<< vec[index]->ypos << " ) " << std::endl;
	}
}

//=================================================================================================================//

class Base 
{
public:
	int a = 1;
	virtual void f() {}
};

class Drv1 : public Base
{
public:
	virtual void f() {
		cout << "Drv1 :: f()" << endl;
		cout << b << endl;
	}
	float b = 3.14;
	//01000000 01001000 11110101 11000011
};

class Drv2 : public Base
{
public:
	virtual void f() {
		cout << "Drv1 :: f()" << endl;
		cout << c << endl;
	}
	int c = 3;
};

//=================================================================================================================//
//=================================================================================================================//

int main()
{
	Shape* s = new Triangle(10.0f, 5.0f);
	cout << s->GetArea() << endl;

	Shape* r = new Rectangle(10.0f, 5.0f);
	cout << r->GetArea() << endl;

	//=================================================================================================================//

	//��ĳ���� Shape -> Triangle
	Triangle* tri = (Triangle*)s;

	//=================================================================================================================//

	Vector2 **vec0 = new Vector2 * [10];
	for (int i = 0; i < 10; i++)
	{
		vec0[i] = new Vector3();
	}

	printVector(vec0, 10);

	for (int i = 0; i < 10; i++)
	{
		delete vec0[i];
	} 
	//delete�� �迭�� ����ŭ�ϰ� delete�� �ؾ��Ѵ�
	delete vec0;

	//=================================================================================================================//

	Vector2* vec2 = new Vector2();
	Vector3* vec3 = new Vector3();
	int a = 10;
	double b = (double)a;

	Vector2* vec1 = (Vector2*)a;
	//int�� a�� vecotr������ ��ȯ. ����������� ���� �ȵ�

	//Vector2* vec = static_cast<Vector2*>(a);
	//static_cast ����ȯ�Ҷ� �ƿ� �߸��� ����ȯ�̶�� ������

	Vector2* vec = static_cast<Vector2*>(vec3);


	//=================================================================================================================//

	// �ٿ� ĳ����
	Base* b = new Drv1(); // �̺κп��� Ŭ���� ���� ���� ������ 'double'��(��) �ٸ��ϴ� ����.. ���� Ȯ�� �ʿ�

	//Drv2* d2 = static_cast<Drv2*>(b);
	//Drv2* d1 = dynamic_cast<Drv2*>(b);
	//Drv1* d2 = (Drv1*)(a); // ������ �ȶ߳� �߸��� ����ȯ
	//d2->f();
	//static_cast�� ������ �ȶ߳� 3.14�� binary code�� ���ؼ� ��µ�
	//static_cast�� dynamic_cast�� �̿��Ͽ� ����ȯ�� ��������� ������ �°� �� �� �ֵ���
	//[ ���� Ŭ������ ������ �� ������ ������ -> ���� Ŭ������ ������ �� ������ ������ ] �� ��ȯ�� ��쿡�� dynamic_cast �����ڸ� ����Ѵ�.
	//[ ���� Ŭ������ ������ �� ������ ������ -> ���� Ŭ������ ������ �� ������ ������ ] �� ��ȯ�� ��쿡�� static_cast �����ڸ� ����Ѵ�.
	return 0;
}