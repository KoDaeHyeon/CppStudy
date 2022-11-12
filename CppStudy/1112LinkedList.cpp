#include "1112LinkedList.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
}

Node* LinkedList::InsertNode(const int nData)
{
	Node *n = new Node;
	n->nData = nData;
	Node *temp = this->Root;
	if (this->Root == NULL)
	{
		this->Root = n;
	}
	else
	{
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = n;
	}
	return nullptr;
}
//삭제부분 2개이하일때 제대로 안됨 손봐야함
Node* LinkedList::DeleteNode(int nData)
{
	Node* ptemp = this->Root;
	while (ptemp->pNext != nullptr)
	{
		if (ptemp->pNext->nData == nData)
		{
			cout << ptemp->pNext->nData << " 삭제" << endl;
			Node* d = ptemp->pNext;
			ptemp->pNext = ptemp->pNext->pNext;
			delete d;
			return nullptr;
		}else
			ptemp = ptemp->pNext;
	}

	return nullptr;
}

Node* LinkedList::DeleteNode(Node* pNode)
{
	Node* ptemp = this->Root;
	while (ptemp->pNext != nullptr)
	{
		if (ptemp->pNext == pNode)
		{
			cout << ptemp->pNext->nData << " 삭제" << endl;
			Node* d = ptemp->pNext;
			ptemp->pNext = ptemp->pNext->pNext;
			delete d;
			break;
		}
		else
			ptemp = ptemp->pNext;
	}

	return nullptr;
}

void LinkedList::PrintNode()
{
	if (Node* ptemp = this->Root)
	{
		while (ptemp != NULL)
		{
			cout << ptemp->nData << endl;
			ptemp = ptemp->pNext;
		}
	}
	else 
	{
		cout << "노드 없음" << endl;
	}
}

Node* LinkedList::FindNode(int nData)
{
	Node* ptemp = this->Root;
	while (ptemp != NULL)
	{
		if (ptemp->nData == nData)
		{
			return ptemp;
			break;
		}
		else
			ptemp = ptemp->pNext;
	}
	return nullptr;
}
