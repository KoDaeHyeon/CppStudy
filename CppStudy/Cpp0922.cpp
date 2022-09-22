#include <iostream>

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
}