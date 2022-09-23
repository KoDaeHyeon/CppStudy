#include <iostream>
#include <cfloat> // 앱실론 사용을 위한 라이브러리

using namespace std;

int main()
{
	float num0 = 0.1f; // 0.1은 2진수로 표현할수없음 가장 가까운 근사값을 메모리에둠
	float num1 = 0.02f * 5.0f; // 이것도 마찬가지 그래서 num0 == num1이 성립이 안됨

	cout.precision(64);
	cout << num0 << endl; //0.1000000001490.... 
	cout << num1 << endl; //0.0999999994089....

	if (num0 == num1)
		cout << "Equal 1" << endl;
	if (num0 == 0.1f) //Equal 2만 출력됨
		cout << "Equal 2" << endl;
	if (num0 == 0.1) //0.1은 더블이라서 실행 안됨
		cout << "Equal 3" << endl;
	if (num0 == 0.1L) // 0.1L은 Long Double이라서 실행 안됨
		cout << "Equal 4" << endl;

	cout << 0.1f << endl; // 0.100000001490116119384765625
	cout << 0.1 << endl; // 0.1000000000000000055511151231257827021181583404541015625
	cout << 0.1L << endl;// 0.1000000000000000055511151231257827021181583404541015625
	//사실상 == 비교를 해야하는 연산에서는 부동 소수점을 쓰지 않는 것이 가장 좋음


	cout << endl << endl;

	float anum0 = 1.0f;
	float anum1 = 0.0f;
	for (int i = 0; i < 1000000; i++)
		anum1 = anum1 + 0.0000001;

	if (num0 == num1) //실행안됨
		cout << "aEqual 0" << endl;

	//앱실론을 이용하여 조건문 수행
	if (fabsf(num0 - num1) <= FLT_EPSILON)//FLT_EPSILON -> float에 관한 앱실론, 오차율이 앱실론보다 커지면 값이 달라질 수 있으니 주의
		cout << "aEqual 1" << endl; 
	

	cout << endl << endl;

	// 1 = 1.0 * 10^0(2)
	unsigned int bnum0 = 0b00111111100000000000000000000000; // 1
	float bnum1;
	memcpy(&bnum1, &bnum0, sizeof(bnum0));

	cout << "bnum1 " << bnum1 << endl; //1출력

	unsigned int bnum2 = 0b00111111100000000000000000000001; //float이 표현할수 있는 1보다 크지만 가장 작은수
	float bnum3;
	memcpy(&bnum3, &bnum2, sizeof(bnum2));

	cout << "bnum3 " << bnum3 << endl; // 1.00000011920928955078125

	cout << bnum3 - bnum1 << endl; //float이 표현할 수 있는 1보다 크지만 가장 작은수 - 1 = 앱실론
	cout << FLT_EPSILON << endl;


	cout << endl << endl;
	
	float cnum0 = 1.0f;

	unsigned int cnum1 = 0b00110011100000000000000000000000; //1.0(2) * 10^-24(2)
	float cnum2;
	memcpy(&cnum2, &cnum1, sizeof(cnum1));

	cout << cnum0 + cnum2; //1출력
	// 0011,1111,1000,0000,0000,0000,0000,0000 = 1.0(2)
	// 0011,0100,0000,0000,0000,0000,0000,0000 = 1.0(2) * 10^-23(2)
	// 0011,0011,1000,0000,0000,0000,0000,0000 = 1.0(2) * 10^-24(2)

	//어떤 정밀도를 요구하는 연사는 부동소수점을 쓰지말고, 고정소수점이나 정수형을 써야함

	cout << endl << endl;

	float fltMin = FLT_MIN; //float 최소값 0000,0000,1000,0000,0000,0000,0000,0000 = 10^-126(2)
	unsigned int ifltMin;
	memcpy(&ifltMin, &fltMin, sizeof(fltMin));

	float fltTrueMin = FLT_TRUE_MIN;  // 0000,0000,0000,0000,0000,0000,0000,0001 = 10^-126(2) * 10^-23(2) = 10^-149(2)
	unsigned int ifltTrueMin;
	memcpy(&ifltTrueMin, &fltTrueMin, sizeof(fltTrueMin));

	cout << ifltMin << endl; // 8388608
	cout << ifltTrueMin << endl; // 1

	cout << fltMin << endl; // 1.17549e-38
	cout << fltTrueMin << endl; // 1.4013e-45
}