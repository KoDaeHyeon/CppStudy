#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int main()
{
	//cpp에서 초기화를 안하면 쓰레기값이 나온다.
	int num[3]{ 1 };//num[0]부분 1 나머지 0으로 초기화
	cout << num[0] << num[1] << num[2] << endl; //1 0 0 출력

	int nums[]{ 1,2 }; //nums[1]까지만 정의 nums[2]를 출력하면 이상한 값 출력
	int sizes = sizeof(nums) / sizeof(int); //nums의 크기는 int크기 * 2이므로  배열개수 = nums크기/int크기 이다.

	for (int i = 0; i < sizes; i++)
	{
		cout << nums[i] << endl; // 1\n 2\n 출력
	}

	cout << size(nums) << endl; //2출력 size는 std함수로 배열의 사이즈를 반환


	int nums0[3] = { 0,1,2 };
	int nums1[3];
	//memcpy(nums0, nums1, sizeof(nums0)); // 배열 복사 (&nums0, &nums1, sizeof(nums0))랑 동일 nums0과 nums1에는 주소값이 나오기 떄문
	copy(nums0, nums0 + 3, nums1);//std::copy이다 3을 더하는 이유는 integerPointer이기때문 integerPointer는 더할때 int의 크기만큼 더한다
	//&nums0부터 &nums + 3*int크기 만큼 nums1에 copy한다.
	cout << nums0 << endl; //000000B3112FF788
	cout << nums0 + 1 << endl; //000000B3112FF78C , 주소값이 4만큼 더해짐

	//버블쇼트 5,4,3,1,7 -> 4,3,1,5,7 -> 3,1,4,5,7 -> 1,3,4,5,7
	int anums[] = { 5,4,3,1,7 };

	for (int i = 0; i < size(anums); ++i)
	{
		for (int j = 0; j < size(anums) - i -1; ++j) //진행될수록 뒤에 큰값이 정렬되는 방식이기때문에 반복된 횟수만큼의 뒷부분은 검사 불필요
		{
			if (anums[j] > anums[j + 1])
			{
				int temp = anums[j];
				anums[j] = anums[j + 1];
				anums[j + 1] = temp;
			}
		}
	}

	cout << "bubble : ";

	for (int i = 0; i < size(anums); ++i)
	{
		cout << anums[i];
	}

	cout << '\n';

	char str[] = "abc";

	cout << (int)str[0] << endl; //a의 int형 97출력
	cout << (int)str[2] << endl; //c의 int형 99출력
	cout << (int)str[3] << endl; //abc 다음인 널문자인 0이 출력

	//char에서 0은 널문자
	str[1] = 0; //b부분을 0(널문자)로 바꿈
	cout << sizeof(str) << endl; //4출력 str[3]은 0인 null문자가 있어서 사이즈는 4가 나온다
	cout << strlen(str) << endl; //1출력 배열의 사이즈는 변함없지만 문자열의 사이즈는 1로 바뀐다

	cout << str << endl; //a만 출력됨

	char astr[] = "abc";
	astr[3] = 'd'; //str0의 null문자 부분을 d로 바꿈

	cout << astr << endl; //abcd'9p...출력 abcd출력후 우연히 null문자가 출력될때까지 랜덤문자 출력	

	astr[3] = '\0';
	cout << astr << endl; //abc 정상적으로 출력

	char str0[50] = "hello";
	char str1[] = "hello";

	if (str0 == str1)//str0과 str1의 주솟값을 비교하기때문에 false다
		cout << "True" << endl;

	int result = strcmp(str0, str1);
	cout << result << endl; //0출력 0이 나오면 같은것

	char str2[6];

	strcpy(str2, str0); //str0을 str2에 복사 복사할 크기가 복사할 장소보다 크면 다른 메모리 영역을 침범할 수 있으니 주의
	cout << str2 << endl;

	char str3[] = "world";

	strcat(str0, str3); //str0의 문자와 str3의 문자를 붙여서 str0에 넣음, 이때 str0의 배열크기에 주의 합친 문자가 str0의 배열크기보다 크면 에러가뜸

	cout << str0 << endl; //helloworld 출력

	//atoi, atof 문자열을 정수,실수로 변환

	char strIn[6];
	//크기가 6을 초과하여 입력하면 error가 나옴 바로 에러가 안나오더라도 strIn을 사용할때 에러가뜰 수있음
	cin >> strIn; //a b를 입력했을경우
	cout << strIn << endl;//스페이스 null값때문에 a만 입력됨 그리고 나머지는 다음 입력으로 감

	getchar();
	
	cin.getline(strIn, 6); //a b 가 입력이됨 라인을 입력받기때문임
	//helloWorld를 입력하면 6까지인 Hello까지만 입력이됨 배열크기보다 많이 입력해도 에러 없음
	cout << strIn << endl; //a b 출력
}