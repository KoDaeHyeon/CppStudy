#include <iostream>

using namespace std;

int main()
{
	int age(0);
	char name[50], gender[10];
	cout << "1. [이름 나이 성별]을 입력해주세요" << endl;
	cout << "성별은 'Male' 'Female'로 입력 바랍니다." << endl;
	if (cin >> name && cin >> age && cin >> gender)
	{
		if (!strcmp("Female", gender) || !strcmp("Male", gender))
		{
			cout << "이름 : " << name << endl;
			cout << "나이 : " << age << endl;
			cout << "성별 : " << gender << endl << endl;
		}
		else
		{
			cout << "성별을 제대로 작성해주세요" << endl;
			return 0;
		}
	}
	else
	{
		cout << "입력 내용을 다시 확인해 주세요" << endl;
		return 0;
	}

	int a(0), b(0);
	cout << "2. 두개의 정수를 입력해 주세요" << endl;
	if (cin >> a && cin >> b)
	{
		if (a > b)
		{
			cout << "큰수 : " << a << endl << endl;
		}
		else if (a < b)
		{
			cout << "큰수 : " << b << endl << endl;
		}
		else
		{
			cout << "동일한 수 : " << a << endl << endl;
		}
	}
	else
	{
		cout << "정수를 입력해 주세요" << endl;
		return 0;
	}
	
	int score(0);
	cout << "3. 0~100 사이의 숫자를 입력하세요" << endl;
	if (cin >> score)
	{
		if (score >= 0 && score <= 100)
		{
			if (score >= 50)
				cout << "합격!" << endl << endl;
			else
				cout << "불합격!" << endl << endl;
		}
		else {
			cout << "점수를 제대로 입력하세요" << endl;
		}
	}
	else
	{
		cout << "정수로 입력하세요" << endl;
	}

	int c(0);
	cout << "4. 정수를 입력해 주세요" << endl;
	if (cin >> c)
	{
		if (c % 2 == 0)
		{
			cout << "이 수는 짝수 입니다." << endl <<endl;
		}
		else
		{
			cout << "이 수는 홀수 입니다." << endl<<endl;
		}
	}
	else
	{
		cout << "정수를 입력해 주세요" << endl;
		return 0;
	}

	cout << "5. 정수를 5개 입력해 주세요" << endl;
	int d(0), sum(0);
	float avg(0);
	for (int i = 0; i < 5; i++)
	{
		cin >> d;
		sum += d;
	}
	avg = float(sum) / 5;
	cout << "평균은 " << avg << " 입니다."<< endl;
}