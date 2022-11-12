#include <iostream>
#include <memory>

using namespace std;
//포인터 함수
//모통 매개변수로 받을때 씀
bool compara(int a, int b)
{
	return a == b;
}

int pow(int x) { return x * x; }
int myFunc(int x) { return (x % 10) * 5 ; }

int arrMin(const int arr[], int length,int (*f)(int))
{
	int min = f(arr[0]);
	cout << " index : " << 0 << "  " << "값 : " << min << endl;
	for (int i = 1; i < length; i++)
	{
		int temp = f(arr[i]);
		if (min > temp)
			min = temp;
		cout << " index : " << i << "  " << "값 : " << temp << endl;

	}
	return min;
}

int arrMins(const int arr[], const int arr1[], int length, int (*f)(int, int))
{
	int min = f(arr[0], arr1[0]);
	cout << " index : " << 0 << "  " << "값 : " << min << endl;
	for (int i = 1; i < length; i++)
	{
		int temp = f(arr[i], arr1[i]);
		if (min > temp)
			min = temp;
		cout << " index : " << i << "  " << "값 : " << temp << endl;

	}
	return min;
}

class Equals {
private:
	int value;
public:
	Equals(int value) : value(value) {}
	//함수 객체
	bool operator()(int x) const {
		return x == value;
	}
	int operator()(int x, int y) const{
		return x + y == value;
	}
};

//클래스 포인터
class Test
{
private:
	int a;
public:
	Test(int a):a(a) { std::cout << a <<"생성" << std::endl; }
	~Test() { std::cout << a << "소멸" << std::endl; }
};


int main() {
	//함수포인터 변수명, 인자
	bool(*fpp)(int, int);
	fpp = &compara;
	bool res = fpp(2, 2);
	cout << res << endl;

	int arr[7] = { 3,1,4,1,5,9,2 };
	cout << "min : " << arrMin(arr, 7,myFunc) << endl << endl;
	cout << "min : " << arrMin(arr, 7,pow) << endl << endl;

	//함수 객체
	Equals equals(123);
	//같으면 1이나오고 다르면 0이나옴
	cout << equals(23) << endl;
	cout << equals(100, 23) << endl << endl;

	//이름 없는 함수(람다식) 이때만 씀, 간단한 루팅같은것들에 쓰임
	//arrMin(arr, 7,pow)와 같은 결과
	cout << "min : " << arrMin(arr, 7, [](int x) -> int {return x * x; }) << endl;
	//위와 같은 결과
	int(*sp)(int) = [](int x) -> int {return x * x; };
	cout << "min : " << arrMin(arr, 7, sp) << endl << "--------------------------" << endl;


	int arr1[7] = { 5,8,9,10,2,1,2 };
	int(*fp1)(int, int) = [](int a, int b)-> int {return a + b; };
	cout << "min : " << arrMins(arr, arr1, 7, fp1) << endl;
	int(*fp2)(int, int) = [](int a, int b)-> int {return a - b; };
	cout << "min : " << arrMins(arr, arr1, 7, fp2) << endl;
	int(*fp3)(int, int) = [](int a, int b)-> int {return a * b; };
	cout << "min : " << arrMins(arr, arr1, 7, fp3) << endl;
	int(*fp4)(int, int) = [](int a, int b)-> int {return a / b; };
	cout << "min : " << arrMins(arr, arr1, 7, fp4) << endl;


	int a = 10;
	auto b = a; //auto는 알아서 자료형을 바꿔줌

	//스마트 포인터
	//unique_ptr, shared_ptr, weak_ptr

	unique_ptr<Test> t(new Test(1));
	cout << "여기는 Main" << std::endl;
	//delete를 따로 안해도 생성-> 여기는 main 출력 -> 삭제 됨 알아서 클래스를 소멸시켜줌
	//대신 유니크 포인트는 하나만 포인터를 가질수 있게해줌
	//unique_ptr<Test> a(t); 하나의 포인터가 아니라 에러가뜸
	unique_ptr<Test> c(t.release()); //t의주소를 a로 반환해줌

	//shared_ptr<Test> d(new Test); //내부적으로 연결된 래퍼런스를 인식하고있음 레퍼런스 카운터가 0이 됬을때 없애줌
	//연결이 되있는한 절대로 안없어짐 가비지 컬렉터
	shared_ptr<Test> g(new Test(5));
	{
		shared_ptr<Test> f = g;
		cout << f.use_count() << endl; //2
		cout << g.use_count() << endl; //2
	}
	cout << g.use_count() << endl; //1 g의 연결이 사라지면서 count가 하나 사라짐
	cout << "여기는 Main1" << std::endl;

	weak_ptr<Test> q;
	{
		shared_ptr<Test> f(new Test(6));
		q = f;
		cout << f.use_count() << endl;
		cout << q.use_count() << endl;
	}

	cout << q.use_count() << endl;
	cout << "여기는 Main2" << std::endl;
	//shared ptr이 사라지면 weaked ptr도 사라짐 
	//단발적으로 가져올때 사용하기 편함
}