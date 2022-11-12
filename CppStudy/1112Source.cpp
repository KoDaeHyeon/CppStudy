#include <iostream>
#include "1112LinkedList.h"
#include "1112DLinkedList.h"

using namespace std;

struct node
{
	int nData;
	node* nextNode;
};

int main()
{
	// 자료구조 단순 연결 리스트 선형 리스트
	node a;
	node b;
	node c;
	node d;
	node e;
	a.nData = 10;
	a.nextNode = &b;
	b.nData = 20;
	b.nextNode = &c;
	c.nData = 5;
	c.nextNode = &d;
	d.nData = 50;
	d.nextNode = &e;
	e.nData = 3;
	e.nextNode = NULL;

	node *temp = &a;
	while (temp != NULL)
	{
		cout << temp->nData << endl;
		temp = temp->nextNode;
	}
	cout << endl << endl;
	//클래스로 구현
	LinkedList* nList = new LinkedList();
	nList->InsertNode(10);
	nList->InsertNode(15);
	nList->InsertNode(50);
	nList->InsertNode(70);
	nList->InsertNode(90);
	nList->PrintNode();
	cout << endl << endl;

	nList->DeleteNode(50);
	nList->DeleteNode(15);
	nList->DeleteNode(nList->FindNode(90));
	nList->PrintNode();
	cout << endl << endl;

	nList->DeleteNode(10);
	nList->DeleteNode(nList->FindNode(70));
	nList->PrintNode();
	cout << endl << endl;


	cout << "===========================================" << endl;
	DLinkedList* dList = new DLinkedList();
	dList->pushFront(10);
	dList->pushFront(20);
	dList->pushFront(30);
	dList->pushBack(40);
	dList->pushBack(50);
	dList->pushBack(60);

	dList->printNode();
}