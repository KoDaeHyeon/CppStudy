#pragma once
#include <iostream>

struct Node {
	int nData; //int형은 n+대문자 변수명
	Node* pNext=NULL; // 포인터 p+대문자 변수명
	//Node ** ppNext; float fData;
};

class LinkedList
{
private:
	Node *Root= NULL;
public:
	LinkedList();
	~LinkedList();

	Node* InsertNode(int nData);
	Node* DeleteNode(int nData);
	Node* DeleteNode(Node *pNode);
	Node* FindNode(int nData);
	void PrintNode();
};
