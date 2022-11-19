#include <iostream>

using namespace std;

void boubleSort(int *arr,int length)
{
	//int counti = 0;
	//int countj = 0;
	//int activej = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				//activej++;
			}
			//countj++;

			//for (int k = 0; k < 7; k++)
			//{
			//	cout << arr[k] <<"    ";
			//}
			//cout << endl;
		}
		//cout << "--------------------------------------" << endl;
		//counti++;
	}

	//cout << "i: " << counti << "j: " << countj << " ActiveJ: " << activej << endl; // 7 49 8
}

void selectSort(int* arr, int length)
{
	int min = 0;
	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i; j < length; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

void insertionSort(int *arr, int length)
{
	int i, j, key;
	// 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
	for (i = 1; i < length; i++) {
		key = arr[i];  // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		// 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
		// j 값은 음수가 아니어야 되고
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
				arr[j + 1] = arr[j];// 레코드의 오른쪽으로 이동
			else break;
		}

		arr[j + 1] = key;
	}


}

int partition(int* arr, int left, int right)
{
	int Pivot = arr[left];
	int i = left+1, j = right;
	do
	{
		if (Pivot > arr[i])
			i++;
		if (Pivot < arr[j])
			j--;
		if (i<j) //if(Pivot < arr[i] && Pivot > arr[j]) 는 교차할때 에러를 내는듯 함 
		{
			swap(arr[i], arr[j]);
			//cout << arr[i] <<" to " << arr[j] << endl;
		}
	} while (i < j);
	
	swap(arr[left], arr[j]);
	//cout << arr[left] << " to " << arr[j] << endl;

	//for (int k = 0; k < 7; k++)
	//{
	//	cout << arr[k] << ", ";
	//}
	//cout << endl;
	return j;
}

void quickSort(int *arr, int left, int right)
{
	if (left >= right)
		return;

	int p = partition(arr, left, right);

	//cout << "P: " << p << endl;
	quickSort(arr, left, p-1);
	quickSort(arr, p +1, right);
}



//시간 복잡도 내려갈수록 느려집// 값이 1에 가까워질수록 빨라짐
//O(1) : 스택, 배열
//O(logn) : 이진트리
//O(n) : for문
//O(n*logn) = 퀵정렬
//O(n^2) = 이중 포문, 버블 소트, 힙정렬
//(2^n) = 피보나치
//n^2

//공간복잡도 메모리

void swap(int* a, int* b)
{
	int *temp = a;
	a = b;
	b = temp;
	delete temp;
}

void main()
{
	int cArr[] = { 10, 111, 20, 1, 4, 200, -1 };

	boubleSort(cArr, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << cArr[i] << "    ";
	}
	cout << endl;
	cout << "================================================" << endl;;

	int cArr1[] = { 10, 111, 20, 1, 4, 200, -1 };
	selectSort(cArr1, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << cArr1[i] << "    ";
	}
	cout << endl;
	cout << "================================================" << endl;

	int cArr2[] = { 10, 111, 20, 1, 4, 200, -1 };
	insertionSort(cArr2, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << cArr2[i] << "    ";
	}
	cout << endl;
	cout << "================================================" << endl;

	int cArr3[] = { 10, 111, 20, 1, 4, 200, -1 };
	quickSort(cArr3, 0, 6);

	for (int i = 0; i < 7; i++)
	{
		cout << cArr3[i] << "    ";
	}
	cout << endl;

}