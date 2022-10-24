#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
#include "SBS4WEEKConsumer.h"

using namespace std;

void Sum(int *s)
{
	int n = 0;
	while (*s <= 450)
	{
		*s += ++n;
	}
	cout << "합은 " << *s << "이고, 마지막에 더해진 수는 " << n << "이다." <<endl;
}


int main()
{
	//1. text.txt 파일을 만들고, Hello World를 입력해서 text에 저장한다. 그리고 text.txt를 출력해보기
	FILE* fp;
	char file_buf[100];
	if (fp = fopen("text.txt", "w")) {
		fputs("Hello World", fp);
		fclose(fp);
		cout << "파일 쓰기 완료" << endl;
	}
	else {
		cout << "파일 쓰기 실패 " << endl;
	}


	if (fp = fopen("text.txt", "r")) {
		while (fgets(file_buf, sizeof(file_buf), fp) != NULL) {
			cout << file_buf << endl;
			memset(file_buf, 0, sizeof(file_buf));
		}
		fclose(fp);
	}
	else {
		cout << "파일 읽기 실패" << endl;
	}


	//2. 1부터 계속 더해지는 sum 변수를 만든다. sum이 450이 넘으면 중지하고 그 때 까지 합과 마지막 더해진 값을 구하는 함수를 만드세요.
	//ex) 합은 465 이고, 마지막 더해진 수는 30이다.
	int sum = 0;
	Sum(&sum);

	//3. Consumer Class 만들기: 이름과 생일, 핸드폰 번호,나이를 입력 받고 생성자에서 초기화 시키세요. 
	Consumer* consumer = new Consumer("홍길동","1월 18일", "1234-1234-4444", 18);
	
	//4. public에서 Conumer의 모든 정보(이름,생일,핸드폰,나이)를 출력하는 함수를 만드세요
	consumer->PrintInfo();

	//5. public에서 이름과 생일, 핸드폰 번호, 나이를 수정할 수 있는 함수를 만드세요
	consumer->EditName("김홍도");
	consumer->EditBirth("5월 7일");
	consumer->EditPhoneNumber("4321-1234-3321");
	consumer->EditAge(34);
	consumer->PrintInfo();


	delete(consumer);
}