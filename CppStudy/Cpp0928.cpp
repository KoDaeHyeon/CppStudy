#include <iostream>
#include <compare> //<=> 연산자를 사용하기 위해

using namespace std;

int main()
{
	int num = 10;
	cout << ++num + num++ << endl; //c++shell 사이트에서는 23이출력 한 식에서 특정변수 하나가 두번이상 변경이될때 위험하니 조심해서 작성

	printf("%d %d \n", ++num, ++num);

	//<=> spaceship 연산자
	//출력<=>은 cout으로 출력을 못하지만 0이랑 비교가능 
	//cout << ((1 <=> 1) == 0); //1(true) 왼쪽 1과 오른쪽 1이 같은값이면 0과 같다
	//cout << ((1 <=> 1) < 0); //0(false) 결과가 0보다 작으면 오른쪽에 있는 값이 크다
	//cout << ((3 <=> 1) > 0); //1(true) 결과가 0보다 크면 왼쪽에 있는 값이 크다,

	//cout << is_eq(1 <=> 1); // 결과가 같나? true 출력
	//cout << is_neq(1 <=> 1); // 결과가 같지 않은가? fals 출력

	//cout << is_lt(1 <=> 2); // 왼쪽이 오른쪽보다 작은가? true
	//cout << is_lteq(1 <=> 1); // 왼쪽이 오른쪽보다 작거나 같은가? true
	//cout << is_gteq(2 <=> 1); // 왼쪽이 오른쪽보다 크거나 같은가? true

	// cout << typeid(1 <=> 1).name(); //string_ordering 출력 완전히 같은것
	// cout << typeid(1 <=> 1.0).name(); //partial_ordering 출력 값이 동등한것

	int num0 = 10, num1(10);
	int num2 = 20, num3(20);

	if (printf("") && num2 == num3) //printf("")은 공백이기떄문에 0으로 리턴
		cout << "AND" << endl;

	bool result = printf("") && printf("ABC"); //printf("")가 0으로 false가 되기때문에 printf("ABC")는 출력이 안됨
	bool result1 = printf("1") && printf("ABC"); //1ABC 출력됨
	
	bool result2 = printf("a") || printf("ABC"); //a만 출력됨 or연산자라 이미 a에서 true임을 알았으니 오른쪽을 확인할 필요가 없어짐

	cout << '\n' << !10 << endl; // 0을 출력 10은 true이기 떄문에 !가 붙으면 false인 0이 출력

	cout << (1 && 2) << endl; // &&와 같은 연산자는 시프트연산자인 <<보다 우선순위가 낮기때문에 괄호를 해줘야함

	cout << '\n' << endl;

	int anum = -10;
	int abs = num < 0 ? -num : num;
	//(A) ? (B) : (C); A가 true면 B 실행 false면 C실행

	int anum0 = 0;
	anum0 == 0 ? (cout << "anum0 == 0 \n") : (cout << "anum0 !=0 \n"); // anum0 == 0 출력
	cout << (anum0 == 0 ? "anum0 == 0 \n" : "anum != 0 \n");//"anum0 == 0"이출력 여기서 B와 C는 타입이 같아야함 다르면 피연산자 호환이 안됨

	short sNum = std::numeric_limits<int>::max(); //01111111111111111111111111111111 에서 short 2바이트에 넣어서 앞이 짤려서 1111111111111111만 들어감
	cout << sNum; //-1 출력
}