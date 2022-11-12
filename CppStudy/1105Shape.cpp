#include "1105Shape.h"
#include <iostream>
using namespace std;
Shape::Shape(const float x, const float y){
	this->x = x, this->y = y;
}

Shape::~Shape()
{
	cout << "Shape ťčÁŚ" << endl;
};

float Rectangle::GetArea() const
{
	return x * y;
}

Rectangle::~Rectangle()
{
	cout << "Rectangle 삭제" << endl;
}

float Triangle::GetArea() const
{
	return (x*y)/2;
}

Triangle::~Triangle()
{
	cout << "Triangle 삭제" << endl;
}
