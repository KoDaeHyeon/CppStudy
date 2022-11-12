#include "1112Stack.h"

Stack::Stack(int nSize) : m_pStack{}
{
	m_pStack = new int[nSize];
	m_nTop = -1;
	m_nMax = nSize;
}

Stack::~Stack()
{
}

void Stack::Resize() // 줄어드는 경우도 있다.
{
	const int* nTempArray = m_pStack;
	m_pStack = new int[m_nMax * 2]{};

	for (int i = 0; i < m_nMax; i++)
	{
		m_pStack[i] =nTempArray[i];
	}

	m_nMax *= 2;

}

void Stack::Push(int nData)
{
	if (m_nTop+1 > m_nMax)
	{
		//cout << "stack overflow" << endl;
		Resize();
		m_pStack[++m_nTop] = nData;
		cout << "Push : " << m_pStack[m_nTop] << endl;
	}
	else {
		m_pStack[++m_nTop] = nData;
		cout << "Push : " << m_pStack[m_nTop] << endl;
	}
}

void Stack::Pop()
{
	if (m_nTop < 0 )
	{
		cout << "stack underflow" << endl;
	}
	else
	{
		cout << "Pop : " << m_pStack[m_nTop] << endl;
		m_pStack[m_nTop--] = NULL;
	}
	//if(m_nTop <= m_nMax /2)용량을 줄이는 경우
}

int Stack::GetTop()
{
	return m_pStack[m_nTop];
}
