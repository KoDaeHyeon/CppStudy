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
	virtual float GetArea() const =0;//���������Լ��� ��Ÿ���� =0
	//���� �����ռ��� ������ ��� �޾ƾ߸� ���� ����
	//ex) Shape *s = new Shape() �Ұ���
	//ex) Shape *s = new Triangle() or Triangle *s = new Triangle() ����
};

class Rectangle : public Shape
{
public:
	Rectangle(const float x, const float y) : Shape(x, y) {};
	~Rectangle();
	virtual float GetArea() const override; 
	//virtual�� �ᵵ �������̵尡 ������ override���� ���� ������ ��Ȯ�� ������
};

class Triangle : public Shape
{
public:
	Triangle(const float x, const float y) : Shape(x, y) {};
	~Triangle();
	virtual float GetArea() const override;
};
