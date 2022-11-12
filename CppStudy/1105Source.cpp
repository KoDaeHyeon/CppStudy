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

	//업캐스팅 Shape -> Triangle
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
	//delete는 배열의 수만큼하고 delete를 해야한다
	delete vec0;

	//=================================================================================================================//

	Vector2* vec2 = new Vector2();
	Vector3* vec3 = new Vector3();
	int a = 10;
	double b = (double)a;

	Vector2* vec1 = (Vector2*)a;
	//int형 a가 vecotr형으로 변환. 허용은하지만 쓰면 안됨

	//Vector2* vec = static_cast<Vector2*>(a);
	//static_cast 형변환할때 아예 잘못된 형변환이라고 말해줌

	Vector2* vec = static_cast<Vector2*>(vec3);


	//=================================================================================================================//

	// 다운 캐스팅
	Base* b = new Drv1(); // 이부분에서 클래스 간접 참조 수준이 'double'과(와) 다릅니다 에러.. 문제 확인 필요

	//Drv2* d2 = static_cast<Drv2*>(b);
	//Drv2* d1 = dynamic_cast<Drv2*>(b);
	//Drv1* d2 = (Drv1*)(a); // 에러는 안뜨나 잘못된 형변환
	//d2->f();
	//static_cast의 에러는 안뜨나 3.14가 binary code로 변해서 출력됨
	//static_cast나 dynamic_cast를 이용하여 형변환을 명시적으로 문법에 맞게 할 수 있도록
	//[ 유도 클래스의 포인터 및 참조형 데이터 -> 기초 클래스의 포인터 및 참조형 데이터 ] 형 변환할 경우에는 dynamic_cast 연산자를 사용한다.
	//[ 기초 클래스의 포인터 및 참조형 데이터 -> 유도 클래스의 포인터 및 참조형 데이터 ] 형 변환할 경우에는 static_cast 연산자를 사용한다.
	return 0;
}