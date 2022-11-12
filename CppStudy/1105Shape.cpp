#include "1105Shape.h"
#include <iostream>
using namespace std;
Shape::Shape(const float x, const float y){
	this->x = x, this->y = y;
}

Shape::~Shape()
{
	cout << "Shape ����" << endl;
};

float Rectangle::GetArea() const
{
	return x * y;
}

Rectangle::~Rectangle()
{
	cout << "Rectangle ����" << endl;
}

float Triangle::GetArea() const
{
	return (x*y)/2;
}

Triangle::~Triangle()
{
	cout << "Triangle ����" << endl;
}