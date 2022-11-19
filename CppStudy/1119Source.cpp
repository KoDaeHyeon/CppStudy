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
	// ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
	for (i = 1; i < length; i++) {
		key = arr[i];  // ���� ���Ե� ������ i��° ������ key ������ ����

		// ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
		// j ���� ������ �ƴϾ�� �ǰ�
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) // key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
				arr[j + 1] = arr[j];// ���ڵ��� ���������� �̵�
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
		if (i<j) //if(Pivot < arr[i] && Pivot > arr[j]) �� �����Ҷ� ������ ���µ� �� 
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



//�ð� ���⵵ ���������� ������// ���� 1�� ����������� ������
//O(1) : ����, �迭
//O(logn) : ����Ʈ��
//O(n) : for��
//O(n*logn) = ������
//O(n^2) = ���� ����, ���� ��Ʈ, ������
//(2^n) = �Ǻ���ġ
//n^2

//�������⵵ �޸�

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