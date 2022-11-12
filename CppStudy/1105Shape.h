#pragma once
class Shape
{
protected:
	float x, y;
public:
	Shape(const float x, const float y);
	float getX() { return this->x; };
	float getY() { return this->y; };
	virtual ~Shape();
	virtual float GetArea() const =0;//순수가상함수를 나타내는 =0
	//순수 가상합수가 있으면 상속 받아야만 쓸수 있음
	//ex) Shape *s = new Shape() 불가능
	//ex) Shape *s = new Triangle() or Triangle *s = new Triangle() 가능
};

class Rectangle : public Shape
{
public:
	Rectangle(const float x, const float y) : Shape(x, y) {};
	~Rectangle();
	virtual float GetArea() const override; 
	//virtual만 써도 오버라이드가 되지만 override까지 적는 이유는 명확성 때문에
};

class Triangle : public Shape
{
public:
	Triangle(const float x, const float y) : Shape(x, y) {};
	~Triangle();
	virtual float GetArea() const override;
};
