#include "1112Queue.h"

Queue::Queue() :m_pBegine{}, m_pEnd{}, m_pBeginDummy{}, m_pEndDummy{}
{
    m_pBeginDummy = &m_pBegine;
    m_pEndDummy = &m_pEnd;

    m_pBeginDummy->pNext = m_pEndDummy;
    m_pEndDummy->pPrev = m_pBeginDummy;
}

Queue::~Queue()
{
}

void Queue::InsertNode(Q_Node *pPrevNode, Q_Node *pCurrentNode, Q_Node *pNextNode)
{
    pCurrentNode->pNext = pPrevNode->pNext;
    pCurrentNode->pPrev = pNextNode->pPrev;
    pPrevNode->pNext = pCurrentNode;
    pNextNode->pPrev = pCurrentNode;
}

Q_Node* Queue::CreateNode(int nData)
{
    Q_Node* pNode = new Q_Node;
    pNode->nData = nData;
    return pNode;
}

Q_Node* Queue::erase(Q_Node* pDelteNode)
{
    Q_Node* pNew = pDelteNode->pPrev;

    pNew->pNext = pDelteNode->pNext;
    pDelteNode->pNext->pPrev = pNew;

    delete pDelteNode;

    return pNew;
}

Q_Node* Queue::Enqueue(int nData)
{
    Q_Node* pNewNode = CreateNode(nData);
    InsertNode(m_pBeginDummy, pNewNode, m_pBeginDummy->pNext);

    return nullptr;
}

Q_Node* Queue::Dequeue()
{
    erase(m_pBeginDummy);
    return nullptr;
}
