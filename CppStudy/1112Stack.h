#pragma once
#include <iostream>
using namespace std;
class Stack
{

private:
	int* m_pStack;
	int m_nTop = 0;
	int m_nMax = 0;

	void Resize(); //스택에 계속들어갈 수 있게 해줌
public:
	Stack(int nSize);
	~Stack();

	void Push(int nData);
	void Pop();
	int GetTop();
};

