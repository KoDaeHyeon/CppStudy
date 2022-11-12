#pragma once
struct Q_Node
{
	Q_Node* pPrev;
	int nData;
	Q_Node* pNext;
};

class Queue
{
private:
	Q_Node m_pBegine;;
	Q_Node m_pEnd;
	Q_Node* m_pBeginDummy;
	Q_Node* m_pEndDummy;
private:
	void InsertNode(Q_Node *pPrevNode, Q_Node *pCurrentNode, Q_Node *pNextNode);
	Q_Node* CreateNode(int nData);
	Q_Node* erase(Q_Node * pDelteNode);
public:
	Queue();
	~Queue();

	Q_Node* Enqueue(int nData);
	Q_Node* Dequeue();
	Q_Node* getEnd() { return m_pEndDummy->pPrev; };
};

