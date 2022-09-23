#pragma warning(disable: 4996)
#include <iostream>
#include <limits>
#include <cstdio> //c에서 stdio.h -> printf 사용가능

using namespace std;
int main()
{
	printf("--1-- \n");
	cout << (int)numeric_limits<uint8_t>::max() << endl; //255이지만 아스키 코드표에 127까지 잇어서 아무것도 출력안됨 
			//int로 형병환 해야 255 출력되
	cout << '\x61' << endl; //a
	cout << '\141' << endl; // 8진수라 a출력
	printf("\n\n");


	printf("--2-- \n");
	bool b0 = 0 < 1; //1
	cout.setf(ios_base::boolalpha); //bool형을 0이나 1이아닌 true false로 출력하게해줌 
	cout << "b0 : " << b0 << endl; // 원래 1 이지만 -> true로 출력

	printf("My True False : %d \n", b0); //1
	printf("%hhu \n", -1); //255

	printf("%-10da\n",1); //변수 뒤 여백 10
	printf("%10da\n\n",1); //변수 앞 여백 10
	printf("\n\n");


	printf("--3-- \n");
	// freopen("output.txt", "w", stdout); //파일에 쓰기를 하겠다
	// printf("파일을 쓰겠습니다");
	printf("\n\n");


	printf("--4-- \n");
	int num;
	char ch;
	int n = scanf("%d %c", &num, &ch); //n은 성공적으로 받은 변수개수
	printf("%d \n", n); //두개 다 잘 받았으면 2, 하나만 잘 받았으면 1, 둘다 못받았으면 0 출력

	int numm;
	if (scanf("%d", &numm)) //if에 쓸수 있다
		printf("입력이 완료 되었습니다 %d \n\n", numm);
	printf("\n\n");


	printf("--5-- \n");
	int num0, num1, num2;
	scanf("%d + %d = %d", &num0, &num1, &num2);// 입력할때 a + b = c 로 입력해야한다, a b c 로 입력하면 b c 에 쓰레기 값이 들어감 a + b c 로 입력하면 c 에 쓰레기 값이 들어감
	printf("%d, %d, %d \n", num0, num1, num2);

	scanf("%i", &num0);// 어떻게 입력하느냐에 따라 진수가 달라짐 0x10 -> 16 , 010 -> 8
	printf("%i\n\n", num0);
	printf("\n\n");


	printf("--6-- \n");
	char ch1;
	getchar();
	scanf("%c", &ch1); 
	printf("1, %c \n", ch1);

	getchar(); //위 scanf를 입력하고 엔터를 하면 엔터가 밑의 scanf에 입력되는 것을 방지, 버퍼의 남아있는 엔터를 소비

	scanf("%c", &ch1);
	printf("2, %c \n", ch1);
	printf("\n\n");


	printf("--7-- \n");
	freopen("input.txt", "r", stdin); //파일 읽기 input.txt -> 내용 : 1234
	
	int fnum;
	scanf("%d", &fnum); // txt파일의 1234 를 fnum에 넣음
	printf("%d", fnum); //1234 출력
}