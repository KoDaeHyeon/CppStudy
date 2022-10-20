#include <iostream>

using namespace std;

enum Color
{
	Red,
	Blue,
	Green,
	Black
};

struct Student
{
	char name[10]={'-'};
	float height=0.0f, weight=0.0f;

};

struct xy
{
	int x = 0, y = 0;
};

void threeInt(int *a,int *b,int *c)
{
	if (*c > *b && *c > *a)
	{
		*a = 0, *b = 0;
	}
	else if (*b > *c && *b > *a)
	{
		*a = 0, *c = 0;
	}
	else
	{
		*b = 0, *c = 0;
	}
}

void sortPrint(int arr[], int len)
{
	int temp = 0;
	for (int i = 0; i < len/2 + 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			temp = 0;
			if (arr[j] > arr[j + 1] && j + 1 < len)
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void sortStudents(Student arr[], int len)
{
	Student temp;
	for (int i = 0; i < len / 2 + 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (arr[j].height > arr[j + 1].height && j + 1 < len)
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "--------------------------------------------------" << endl;
	for (int i = len-1; i >= 0; i--)
	{
		cout << "이름 : " <<arr[i].name << endl;
		cout << "키 : " << arr[i].height << endl;
		cout << "몸무게 : " << arr[i].weight << endl;
		cout << "--------------------------------------------------" << endl;
	}
	cout << endl;
}

xy xyFunction(xy *x1, xy *x2)
{
	xy result;
	result.x = x1->x + x2->x;
	result.y = x1->y + x2->y;
	return result;
}

int main()
{
	cout << "1. 세 개의 숫자를 포인터 매개변수로 받는 함수를 만들고, 가장 큰 숫자를 제외한 나머지 숫자를 0으로 만드는 함수를 만드세요." << endl;
	cout << "숫자 a b c 입력" << endl;
	int a(0), b(0), c(0);
	cin >> a;
	cin >> b;
	cin >> c;
	threeInt(&a, &b, &c);
	cout << " a : " << a <<", b : " << b <<", c : " << c << endl << endl;


	cout << "2. 배열 { 1, 4, 10, 3, 20, 2, 4, 5, 6, 8} 을 만들고 숫자가 작은 순서대로 출력하세요." << endl;
	int arr[] = { 1,4,10,3,20,2,4,5,6,8 };
	int len = 10;
	sortPrint(arr,len);
	cout << endl << endl;
	
	cout << "3. Student 이름, 키 , 몸무게를 구조체로 만들고 3명을 입력 받아 키가 큰 순서대로 출력 하세요." << endl;
	const int slen = 3;
	Student students[slen];
	for (int i = 0; i < slen; i++)
	{
		cout << "이름 : ";
		cin >> students[i].name;
		cout << "키 : ";
		cin >> students[i].height;
		cout << "몸무게 : ";
		cin >> students[i].weight;
	}
	
	sortStudents(students, slen);
	cout << endl << endl;

	cout << "4-1 int형 x,y를 가지고 있는 구조체 Point를 만든다." << endl;
	cout << "4-2 두 개의 Point 매개변수를 포인터로 받고 두 Point의 x,y를 각각 더한 Point를 리턴하는 함수를 만든다. ex) x1 + x2 , y1 + y2" << endl;
	xy x1{ 0,0 }, x2{ 0,0 };
	cin >> x1.x;
	cin >> x1.y;
	cin >> x2.x;
	cin >> x2.y;
	xy x3 = xyFunction(&x1, &x2);
	cout << "x1.x : " << x1.x << ", x1.y : " << x1.y << endl;
	cout << "x2.x : " << x2.x << ", x2.y : " << x2.y << endl;
	cout << "x3.x : " << x3.x << ", x3.y : " << x3.y << endl << endl;

	cout << "5. Enum 변수안에 Red, Blue, Green, Black을 선언하고, Switch문에 Enum을 입력받아 Red면 Red, Blue면 Blue, Green이면 Green, Black이면 Black이 출력되게 하세요." << endl;

	Color color=Red;
	string col="";

	cin >> col;

	if (!col.compare("Red"))
		color = Red;
	else if (!col.compare("Blue"))
		color = Blue;
	else if (!col.compare("Green"))
		color = Green;
	else if (!col.compare("Black"))
		color = Black;

	switch (color)
	{
	case Red:
		cout << "Red" << endl;
		break;
	case Blue:
		cout << "Blue" << endl;
		break;
	case Green:
		cout << "Green" << endl;
		break;
	case Black:
		cout << "Black" << endl;
		break;
	}
}