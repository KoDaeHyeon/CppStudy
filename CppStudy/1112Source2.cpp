#include<iostream>
#include"1112Queue.h"

using namespace std;

int main()
{
	Queue *queue = new Queue();
	queue->Enqueue(1);
	queue->Enqueue(2);
	queue->Enqueue(3);
	queue->Enqueue(4);
	queue->Enqueue(5);
	Q_Node* back = queue->getEnd();
	while (back->pPrev != nullptr)
	{
		cout << back->nData << endl;
		back = back->pPrev;
	}
	cout << endl << endl;
}