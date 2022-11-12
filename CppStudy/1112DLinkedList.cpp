#include "1112DLinkedList.h"
#include <iostream>
using namespace std;

DLinkedList::DLinkedList() :m_pHead{}, m_pTail{}, m_pHeadDummy{}, m_pTailDummy{} // 더미 주소값이 들어가지 않도록 초기화
{
	m_pHeadDummy = &m_pHead;
	m_pTailDummy = &m_pTail;

	m_pHeadDummy->pNext = m_pTailDummy;
	m_pTailDummy->pPrev = m_pHeadDummy;
}

DLinkedList::~DLinkedList()
{
}

S_Node* DLinkedList::erase(S_Node* pDeleteNode)
{
	S_Node* pNew = pDeleteNode->pPrev;
	pNew->pNext = pDeleteNode->pNext;
	pDeleteNode->pNext->pPrev = pNew;

	delete pDeleteNode;

	return pNew;
}

S_Node* DLinkedList::CreateNode(int nData)
{
	S_Node* pNode = new S_Node{};
	pNode->nData = nData;
	return pNode;
}

void DLinkedList::InsertNode(S_Node* pPrevNode, S_Node* pCurrentNode, S_Node* pNextNode)
{
	pCurrentNode->pNext = pPrevNode->pNext;
	pCurrentNode->pPrev = pNextNode->pPrev;
	pPrevNode->pNext = pCurrentNode;
	pNextNode->pPrev = pCurrentNode;
}

void DLinkedList::pushFront(int nData)
{
	S_Node* pNewNode = CreateNode(nData);
	InsertNode(m_pHeadDummy, pNewNode, m_pHeadDummy->pNext);
}

void DLinkedList::pushBack(int nData)
{
	S_Node* pNewNode = CreateNode(nData);
	InsertNode(m_pTailDummy->pPrev, pNewNode, m_pTailDummy);
}

void DLinkedList::printNode()
{
	S_Node* pTemp = m_pHeadDummy->pNext; //Head는 빈공간이므로 진짜 Head는 Head의 Next
	while (pTemp->pNext != nullptr)
	{
		cout << pTemp->nData << endl;
		pTemp = pTemp->pNext;
	}
}


