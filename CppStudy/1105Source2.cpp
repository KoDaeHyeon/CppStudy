#include <iostream>

using namespace std;

template<typename T, int length> //탬플릿을 이용해 파라미터처럼 length를 사용함
class Vector {
private:
	T* comp;
public:
	Vector(int length) {
		comp = new T[length];
	}
	~Vector()
	{
		delete[] comp;
	}

	T GetComp(int index) const { if(comp[index]) return comp[index]; }
	void SetCopm(int index, T value)
	{
		comp[index] = value;
	}

	Vector operator+(const Vector& rhs)
	{
		Vector res;
		for (int index = 0; index < length; index++)
		{
			res.SetCopm(index, this -> GetComp(index) + rhs.GetComp(index));
		}

		return res;
	}
};

template <typename A>

class Vector2
{
private:
	A x, y;
public:
	Vector2(const A x, const A y) : x(x), y(y) {}

	Vector2& operator+=(const Vector2& rhs) //rhs = right hand side lhs= left hand side
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}
	Vector2& operator>(const Vector2& rhs) 
	{
		if (this->x + this->y > rhs.x + rhs.y)
		{
			this->x = rhs.x;
			this->y = rhs.y;
		}
		return *this;
	}

	A GetX() const { return x; }
	A GetY() const { return y; }
};

template<typename T, typename L>

T getArraySum(const T arr[], const L length)
{
	//vector에서 0을 넣으면 에러가뜨니 0번째를 초기값 1부터 더하기
	T sum = arr[0];

	for (int i = 1; i < length; i++)
	{
		sum += arr[i];
	}

	return sum;
}

template<typename T>
Vector2<T> getArrayMin(const Vector2<T> arr[], const int length)
{
	Vector2<T> min = arr[0];
	for (int i = 1; i < length; i++)
	{ 
		min > arr[i];
	}
	
	return min;
}

//템플릿 특수화
template<>
string getArraySum<string>(const string arr[], const int length)
{
	string sum = arr[0];

	for (int index = 1; index < length; index++)
	{
		sum += ' ' + arr[index];
	}

	return sum;
}

int main()
{
	Vector2<int> vecArray[3] = { Vector2<int>(1,3), Vector2<int>(2,4), Vector2<int>(3,5) };
	Vector2<float> FvecArray[3] = { Vector2<float>(1.5f,3.2f), Vector2<float>(2.6f,4.3f), Vector2<float>(3.5f,5.7f) };
	int arr[5] = { 3,1,4,1,5 };
	float farray[5] = { 3.3f,2.1f,2.5f,1.1f,7.5f };

	cout << getArraySum(arr, 5) << endl;
	cout << getArraySum<float, int>(farray, 5) << endl << endl;
	
	Vector2<int> sum = getArraySum<Vector2<int>, int>(vecArray, 3);
	cout << "sum" << endl << sum.GetX() << endl << sum.GetY() << endl << endl;
	//에러! += 연산자가 정의되지않음 그래서 Vector2클래스에서 정의

	Vector2<float> fsum = getArraySum<Vector2<float>, int>(FvecArray, 3);
	cout << "fsum" << endl << fsum.GetX() << endl << fsum.GetY() << endl << endl;

	Vector2<int> min = getArrayMin(vecArray, 3);
	cout << "min" << endl <<  min.GetX() << endl << min.GetY() << endl;

	std::string sArray[3] = { "hello", "my", "name" };
	std::string ssum = getArraySum(sArray, 3);
	std::cout << ssum;

	return 0;
}