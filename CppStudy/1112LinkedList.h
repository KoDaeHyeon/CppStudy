#pragma once
#include <iostream>

struct Node {
	int nData; //int���� n+�빮�� ������
	Node* pNext=NULL; // ������ p+�빮�� ������
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
