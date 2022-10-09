#include <iostream>

using namespace std;

int evenOdd(int num)
{
	if (num < 0)
		num = num * -1;

	if (num % 2 == 0)
		return num;
	else
		return -num;
}

void printEvenOdd(int numArray[])
{
	int even[10] = { 0 }, odd[10] = { 0 };
	int evenNum(0), oddNum(0);

	for (int i = 0; i < 10; i++)
	{
		if (numArray[i] % 2 == 0)
		{
			even[evenNum] = numArray[i];
			evenNum++;
		}
		else
		{
			odd[oddNum] = numArray[i];
			oddNum++;
		}
	}
	cout << "홀수" << endl;
	for (int i = 0; i < oddNum; i++)
	{
		cout << odd[i] << " ";
	}
	
	cout << endl << "짝수" << endl;
	for (int i = 0; i < evenNum; i++)
	{
		cout << even[i] << " ";
	}
}

void minMax()
{
	int min(0), max(0);

	int numArray[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> numArray[i];
	}

	for (int i = 0; i < 10; i++)
	{
		if (i != 0)
		{
			if (numArray[i] > max)
				max = numArray[i];
			if (numArray[i] < min)
				min = numArray[i];
		}
		else
		{
			min = numArray[i];
			max = numArray[i];
		}
	}
	cout << "min : " << min << endl << "max : " << max << endl;
}

int main()
{
	cout << endl << "1번 -----------------------------" << endl;
	int num = 0;
	if (!(cin >> num))
		cout << "정수로 입력해주세요" << endl;
	else
		cout << evenOdd(num) << endl;

	cout << endl << "2번 -----------------------------" << endl;
	int score(0), sum(0);
	for (int i = 0; i < 10; i++)
	{
		cin >> score;
		sum += score;
	}
	cout << "평균 : " << sum / 10 << endl;

	cout << endl << "3번 -----------------------------" << endl;
	int numArray[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> numArray[i];
	}
	printEvenOdd(numArray);
	cout << endl;

	cout << endl << "4번 -----------------------------" << endl;
	int numArray2[3][3] = { {1,11,3}, {8,5,4}, {10,6,7} };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << numArray2[j][i] << " ";
		}
		cout << endl;;
	}

	cout << endl << "5번 -----------------------------" << endl;
	minMax();
}