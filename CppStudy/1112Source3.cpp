#include<iostream>
#include"1112Stack.h"

int main()
{
	Stack* stack = new Stack(3);
	stack->Push(6);
	stack->Push(3);
	stack->Push(2);
	stack->Push(9);
	stack->Push(10);
	stack->Push(8);
	cout << stack->GetTop() << endl;
	stack->Pop();
	stack->Pop();
	stack->Pop();
	stack->Pop();
	stack->Pop();
	stack->Pop();
}