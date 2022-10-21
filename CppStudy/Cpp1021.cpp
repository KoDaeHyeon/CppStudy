#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str0("abc");
	string str1("abc");

	//char 에서는 strcmp를 썼지만 string은 ==로 된다
	if (str0 == str1)
		cout << "True" << endl;
	
	vector<int> vec(5); // 10개의 int
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl; // 0\n 0\n 0\n.... 벡터는 자동초기화
	}

	vector<int> vec1(5, 2); // 전부다 2로 초기화됨
	vec1.resize(3); //앞의 3자리만 남고 2개짤림
	vec1.resize(10, 9); // 3자리->10자리로 늘리고 새로 생기는 값은 9로 초기화

	//벡터는 사이즈가 가변
	vector<int> vec2; // 이 vec2는 사이즈가 0이다
	vec2.push_back(10); //vec2에 10을추가 이러면 vec2[0]=10이 되고 vec2.size() = 1 이된다.
	vec2.pop_back(); // 10을 빼서 vec2.size()=0으로 돌아간다.

	for (int i = 0; i < 10; i++)
	{
		vec2.push_back(i);
		cout << vec2.data() << endl; //벡터의 주솟값 출력, 벡터의 크기를 늘릴때마다 주소값이 달라짐-> 계속 할당이 일어남
		//vec2.data()[2];//는 3번째의 있는 데이터 3을 출력
	} 
	vec2.reserve(10000); //이걸 해두면 값이 커질때 할당이 안일어남.

	cout << vec.front() << endl; //가장 앞의값 출력
	cout << vec.back() << endl; //가장 뒤의값 출력

	vec1.swap(vec2); // vec1과 vec2의 값을 서로 바꿈

	vec = vec1; //벡터의 경우 사이즈가 서로 다른경우에도 assigned가 됨

	for (int num : vec)
		cout << num; //vec은 크기가 5였는데 크기아 10인 vec2의 값이 다 들어갔음

	cout << endl;
	vector<int> vec3{ 3,2,1 };
	vector<int> vec4{ 3,2,1,0 };
	vector<int> vec5{ 3,1,1 };

	if (vec3 > vec5)
		cout << "vec3 > vec5" << endl; //서로의 값을 비교하고 더 큰게 많은쪽이 출력
	if (vec4 > vec3)
		cout << "vec5 > vec3" << endl; //서로 같은 값일 경우에는 길이가 긴쪽을 출력
}