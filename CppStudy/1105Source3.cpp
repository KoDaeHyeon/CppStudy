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
		cout << "sum의 값이 5500을 넘긴 인덱스는 " << e << "입니다." << endl;
	}
	
}