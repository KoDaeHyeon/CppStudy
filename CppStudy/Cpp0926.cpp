#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << 'a' << endl;
	cout.put('a');
	cout.put('\n');
	cout.write("hello world", 5);//5개만 출력 hello까지만 출력
	cout.put('\n');
	cout.width(10);//폭 10칸 지정
	cout << 1; //^^^^^^^^^1 출력

	cout.put('\n');
	cout.width(10);
	cout.fill('#');
	cout << 1; //#########1 출력

	cout.put('\n');
	float num = 0.1234567f;
	cout << num << endl; // 0.123457 출력 소수점 6자리까지 표현이 디폴트

	cout.precision(10); //정밀도 10자리
	cout << num << endl; //0.123457016

	cout.put('\n');
	cout.setf(ios_base::showpos);//플래그 세팅 setf -> set format, showpos -> show positive
	cout << 1 << endl; //+1출력

	cout.unsetf(ios_base::showpos); // 언셋, 헤제
	cout << 2 << endl; // 2출력

	cout.put('\n');
	cout << true << endl; //1출력
	cout << false << endl; // 0출력

	cout.setf(ios_base::boolalpha);

	cout << true << endl; //true 출력
	cout << false << endl; //false 출력

	cout.put('\n');
	cout.setf(ios_base::left, ios_base::adjustfield); //left,right,internal 좌측정렬 우측정렬 부호가 양끝으로
	cout.width(10);
	cout.fill(' ');
	cout << -10 << 20;//-10     20 출력

	cout.put('\n');
	cout.setf(ios_base::hex, ios_base::basefield);// 진수 설정 dec oct hex
	cout << 16 << endl; // 10출력
	cout.setf(ios_base::dec, ios_base::basefield);

	oct(cout); //이렇게도 가능
	cout << 16 << endl; // 20출력
	cout << hex << 16 << endl; //이렇게도 가능 10출력
	dec(cout);

	cout << setw(10) << setfill('#') << setprecision(10) << showpos << 1.1f << endl; // setw -> width , +1.100000024 출력
	cout << setw(10) << setfill('#') << setprecision(1) << showpos << 0.1f << endl; //+0.1######

	cout.unsetf(ios_base::showpos);
	cout << "\n\n\n" << endl;

	int a;
	if (cin >> a) //입력 scanf와 동일 &a를 하지 않아도 되는 이유 , 참조를 이용해서 밖에있는 변수도 함수 내부에서 변경 가능
		cout << a << endl;
	
	char ch;
	cin >> ch;
	cout << ch << endl;

	cin.ignore(3); //위에서 ab를 입력시 밑의 cin까지 같이 입력되는거를 방지
				  //무시할수 있는 길이 지정 디폴트는 1
	cin >> ch;
	cout << ch << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //numeric_limits<streamsize>::max()는 최대값-> 무한이 무시, 뒤의 문자는 어떤 문자가 나올때까지 무시한다
														//개행문자가 나올때까지 무시 -> 최댓값까지 무시 -> absdfdgf에서 맨앞의 a빼고 다 무시
	cin >> ch;
	cout << ch << endl;

	int num;
	cin >> num;
	cout << num << endl;
	if (cin.fail()) //입력의 실패유무 체크 실패하면 1
		cin.clear(); //입력을 실패할때 다음 입력이 넘어가지는 현상 방지
	cin >> num;
	cout << num << endl;

	cout << "\n\n\n" << endl;

	bool b;
	cin.setf(ios_base::boolalpha); //원래 bool형을 숫자로 받지만 ,true false로 받을수 있게 해줌
	cin >> b; //true 입력
	cout << b; //1 출력

	int num2;
	cin.setf(ios_base::hex, ios_base::basefield); //16진수로 받음
	cin >> num2; //10입력
	//cin >> hex >> num2 도 가능
	cout << num2; //16출력

	//위의 cin, cout 예제 모두 파일 읽고 쓰기 할때 사용 가능

}