#include <iostream>
#include <memory>

using namespace std;
//������ �Լ�
//���� �Ű������� ������ ��
bool compara(int a, int b)
{
	return a == b;
}

int pow(int x) { return x * x; }
int myFunc(int x) { return (x % 10) * 5 ; }

int arrMin(const int arr[], int length,int (*f)(int))
{
	int min = f(arr[0]);
	cout << " index : " << 0 << "  " << "�� : " << min << endl;
	for (int i = 1; i < length; i++)
	{
		int temp = f(arr[i]);
		if (min > temp)
			min = temp;
		cout << " index : " << i << "  " << "�� : " << temp << endl;

	}
	return min;
}

int arrMins(const int arr[], const int arr1[], int length, int (*f)(int, int))
{
	int min = f(arr[0], arr1[0]);
	cout << " index : " << 0 << "  " << "�� : " << min << endl;
	for (int i = 1; i < length; i++)
	{
		int temp = f(arr[i], arr1[i]);
		if (min > temp)
			min = temp;
		cout << " index : " << i << "  " << "�� : " << temp << endl;

	}
	return min;
}

class Equals {
private:
	int value;
public:
	Equals(int value) : value(value) {}
	//�Լ� ��ü
	bool operator()(int x) const {
		return x == value;
	}
	int operator()(int x, int y) const{
		return x + y == value;
	}
};

//Ŭ���� ������
class Test
{
private:
	int a;
public:
	Test(int a):a(a) { std::cout << a <<"����" << std::endl; }
	~Test() { std::cout << a << "�Ҹ�" << std::endl; }
};


int main() {
	//�Լ������� ������, ����
	bool(*fpp)(int, int);
	fpp = &compara;
	bool res = fpp(2, 2);
	cout << res << endl;

	int arr[7] = { 3,1,4,1,5,9,2 };
	cout << "min : " << arrMin(arr, 7,myFunc) << endl << endl;
	cout << "min : " << arrMin(arr, 7,pow) << endl << endl;

	//�Լ� ��ü
	Equals equals(123);
	//������ 1�̳����� �ٸ��� 0�̳���
	cout << equals(23) << endl;
	cout << equals(100, 23) << endl << endl;

	//�̸� ���� �Լ�(���ٽ�) �̶��� ��, ������ ���ð����͵鿡 ����
	//arrMin(arr, 7,pow)�� ���� ���
	cout << "min : " << arrMin(arr, 7, [](int x) -> int {return x * x; }) << endl;
	//���� ���� ���
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
	auto b = a; //auto�� �˾Ƽ� �ڷ����� �ٲ���

	//����Ʈ ������
	//unique_ptr, shared_ptr, weak_ptr

	unique_ptr<Test> t(new Test(1));
	cout << "����� Main" << std::endl;
	//delete�� ���� ���ص� ����-> ����� main ��� -> ���� �� �˾Ƽ� Ŭ������ �Ҹ������
	//��� ����ũ ����Ʈ�� �ϳ��� �����͸� ������ �ְ�����
	//unique_ptr<Test> a(t); �ϳ��� �����Ͱ� �ƴ϶� ��������
	unique_ptr<Test> c(t.release()); //t���ּҸ� a�� ��ȯ����

	//shared_ptr<Test> d(new Test); //���������� ����� ���۷����� �ν��ϰ����� ���۷��� ī���Ͱ� 0�� ������ ������
	//������ ���ִ��� ����� �Ⱦ����� ������ �÷���
	shared_ptr<Test> g(new Test(5));
	{
		shared_ptr<Test> f = g;
		cout << f.use_count() << endl; //2
		cout << g.use_count() << endl; //2
	}
	cout << g.use_count() << endl; //1 g�� ������ ������鼭 count�� �ϳ� �����
	cout << "����� Main1" << std::endl;

	weak_ptr<Test> q;
	{
		shared_ptr<Test> f(new Test(6));
		q = f;
		cout << f.use_count() << endl;
		cout << q.use_count() << endl;
	}

	cout << q.use_count() << endl;
	cout << "����� Main2" << std::endl;
	//shared ptr�� ������� weaked ptr�� ����� 
	//�ܹ������� �����ö� ����ϱ� ����
}