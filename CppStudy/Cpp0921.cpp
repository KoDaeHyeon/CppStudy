#include <iostream>

using namespace std; //네임스페이스인 std를 항상 쓰겠다고 선언, std::cout -> cout
int main()
{
	std::cout << "Hello World";

	int x=1, y=2, z(3);//z(3)은 cpp타입의 초기화

	//std::cout -> std안에 있는 cout을 쓰겠다
	cout << endl << x << endl;//std::endl 줄바꿈
	cout << y << z << endl << endl;

	//리터럴= 값을 직접 입력, 위의hello world도 같음
	int num0 = 11;
	int num1 = 011;//앞에 0이 달리면 8진수
	int num2 = 0b11;//0b가 달리면 2진수
	int num3 = 0x11;//0x가 달리면 16진수

	cout << "num0 " << num0 << endl;
	cout << "num1 " << num1 << endl;
	cout << "num2 " << num2 << endl;
	cout << "num3 " << num3 << endl << endl;

	int8_t num8b = 0;//어느 플랫폼을 가도 8비트
	int16_t num16b = 0; //어느 플랫폼을 가도 16비트
	int32_t num32b = 0; //어느 플랫폼을 가도 32비트
	uint8_t uNum8b = 0; //unsigned 8bit

	cout << sizeof(num8b) << endl;
	cout << sizeof(num16b) << endl;
	cout << sizeof(num32b) << endl << endl;

	unsigned int a = 11; //11은 int라 내부적으로 타입변환이 일어남 성능에 안좋음
	unsigned int au = 11u; //뒤에 u를 명시하면 확실하게 unsigned 리터럴이 됨
	long int longNum = 0L; //Long으로
	long long longLongNum = 0LL; //LongLong
	unsigned long long ulongLongNum = 0uLL;//0LLu도 가능하다


	return 0; //종료코드 0
}