#include <iostream>
using namespace std;

int intsum(int a, int b)
{
	int iSum = 0;
	if (a + b < 0)
	{
		iSum = a + b;
		throw iSum;
	}

	return a + b;
}

int main()
{

	int sum = 0;

	try {
		for (int i = 1; i < 200; i++)
		{
			sum += i;
			if (sum > 5500)
				throw i;
		}
	}
	catch (int e) {
		cout << "sum�� ���� 5500�� �ѱ� �ε����� " << e << "�Դϴ�." << endl;
	}
	
}