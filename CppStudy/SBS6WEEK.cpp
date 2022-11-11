#include <iostream>

using namespace std;

//1.  두 변수를 Swap 시키는 템플릿 함수를 만들기.
template <typename T>
void Swap(T *a, T *b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//2.  배열과 배열의 길이를 매개변수로 받고 배열의 값 중 가장 큰 값을 반환하는 MAX함수를 템플릿으로 만들기
template <typename T>
T Max(T arr[], int L)
{
	T max = arr[0];
	for (int i = 1; i < L; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

//3. Matrix라는 4개의 int 변수를 가지고 있는 클래스를 만들고 operator+, operator+=, operator== 를 오버로딩 하여 두 개의 Matrix 클래스가  +, +=, == 연산이 되도록 만들기.
//4. Matrix클래스를 템플릿으로 만들기
template <typename T>
class Matrix
{
private:
	T a, b, c, d;
public:
	Matrix(const T a, const T b, const T c, const T d) :a(a), b(b), c(c), d(d) {};
	~Matrix() {};
	Matrix operator+(Matrix& ref)
	{
		return Matrix(this->a + ref.a, this->b + ref.b, this->c + ref.c, this->d + ref.d);
	}
	Matrix operator+=(Matrix& ref)
	{
		this->a += ref.a;
		this->b += ref.b;
		this->c += ref.c;
		this->d += ref.d;
		return *this;
	}
	bool operator==(Matrix& ref)
	{
		return (this->a == ref.a && this->b == ref.b && this->c == ref.c && this->d == ref.d);
	}
	void printValue()
	{
		cout << "a : " << this->a << "  b : " << this->b << "  c : " << this->c << "  d : " << this->c << endl;
	}
};

//5. 이름과 나이를 가지고 있고 Show 라는 함수를 virtual로 갖고 있는 Human 클래스 만들기.
//그리고  student와 worker가 상속받게 만드세요.
//student는 학년과 학번이 있고, 회사원은 직급과 담당부서 있으며 Show라는 함수를 override하여 각각 정보들을 출력하게 만드세요.

class Human
{
protected:
	int age;
	char* name;
public:
	Human(const int age, const char* name) :age(age) 
	{
		this->name = _strdup(name);
	}
	virtual ~Human()
	{
		if (this->name) delete[] this->name;
		cout << "Human 삭제" << endl;
	}
	virtual void Show() const = 0;
};
class Student : public Human
{
private:
	int grade;
	char* no;
public:
	Student(const int age, const char* name, const int grade, const char* no): Human(age, name),grade(grade)
	{
		this->no = _strdup(no);
	}
	~Student()
	{
		if (this->no) delete[] this->no;
		cout << "Student 삭제" << endl;
	}
	virtual void Show() const override
	{
		cout << "나이 : " << this->age << endl;
		cout << "이름 : " << this->name << endl;
		cout << "학년 : " << this->grade << endl;
		cout << "학번 : " << this->no << endl;
	}

};

class Worker : public Human
{
private:
	char* rank;
	char* dept;
public:
	Worker(const int age, const char* name, const char* rank, const char* dept) :Human(age, name)
	{
		this->rank = _strdup(rank);
		this->dept = _strdup(dept);
	}
	~Worker() 
	{
		if (this->rank) delete[] this->rank;
		if (this->dept) delete[] this->dept;
		cout << "Worker 삭제" << endl;
	}
	virtual void Show() const override 
	{
		cout << "나이 : " << this->age << endl;
		cout << "이름 : " << this->name << endl;
		cout << "직급 : " << this->rank << endl;
		cout << "부서 : " << this->dept << endl;
	}
};
int main()
{
	float a = 5.7f, b = 3.2f;
	Swap(&a, &b);
	cout << "a: " << a << "   b : " << b << endl;

	int arr[] = { 1,8,9,10,8,7,6,5,48,77,52,10,56 }, Length =13;
	cout << "Max : " << Max(arr, Length) << endl;

	Matrix<int> m1(1,2,3,4), m2(3,4,5,6), m3(1,2,3,4);
	m1 += m2;
	Matrix<int> m4 = m2 + m3;
	cout << "m1 == m3  :  " << (m1 == m3) << endl;
	cout << "m1 == m2  :  " << (m1 == m2) << endl;
	cout << "m1 += m2  :  "; m1.printValue();
	cout << "m2 + m3   :  "; m4.printValue();
	m1.~Matrix();
	m2.~Matrix();
	m3.~Matrix();
	m4.~Matrix();

	Student* student = new Student(24, "고대현", 3, "201844037");
	Worker *worker = new Worker(25, "홍길동", "부장", "개발팀");

	student->Show();
	worker->Show();
	student->~Student();
	worker->~Worker();
}