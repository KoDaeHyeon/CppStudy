#pragma once

struct S_Node {
	int nData;
	S_Node* pPrev;
	S_Node* pNext;
};
class DLinkedList
{
private:
	S_Node m_pHead;
	S_Node m_pTail;

	S_Node* m_pHeadDummy;// Head을 가르키는 역할
	S_Node* m_pTailDummy;// Tail을 가르키는 역할
private:
	S_Node* CreateNode(int nData);
	void InsertNode(S_Node* pPrevNode, S_Node* pCurrentNode, S_Node* pNextNode);
public:
	DLinkedList();
	~DLinkedList();
	void pushFront(int nData);
	void pushBack(int nData);
	void printNode();

	S_Node* GetHead() const { return m_pHeadDummy; };
	S_Node* GetTail() const { return m_pTailDummy; };
	S_Node* erase(S_Node* pDeleteNode);
};

