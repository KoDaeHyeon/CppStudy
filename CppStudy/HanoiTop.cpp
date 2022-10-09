#include <iostream>

using namespace std;

void ViewHanoi(int first[5], int second[5], int third[5])
{
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (first[i] != 0)
			cout << "       " << first[i] << "           ";
		else
			cout << "                   ";
		if (second[i] != 0)
			cout << second[i] << "         ";
		else
			cout << "          ";
		if (third[i] != 0)
			cout << third[i];
		cout << "         " << endl;
	}
	cout << "     first      second     third" << endl;
}

int main() {
	int first[5] = { 1,2,3,4,5 };
	int second[5] = { 0,0,0,0,0 };
	int third[5] = { 0,0,0,0,0 };

	cout << "first = 1, second = 2, third = 3" << endl;

	int move = 0, here = 0, hanoi = 0, under = 0;
	while (1)
	{
		bool succes = false;
		cout << endl;

		ViewHanoi(first, second, third);

		cout << " 무엇을 옮기시겠습니까?" << endl;
		cin >> move;
		cout << " 어디로 옮기시겠습니까?" << endl;
		cin >> here;

		hanoi = 0, under = 0;
		switch (move)
		{
		case 1:
			for (int i = 0; i < 5; i++)
			{
				if (first[i] != 0)
				{
					hanoi = first[i];
					break;
				}
			}
			break;
		case 2:
			for (int i = 0; i < 5; i++)
			{
				if (second[i] != 0)
				{
					hanoi = second[i];
					break;
				}
			}
			break;
		case 3:
			for (int i = 0; i < 5; i++)
			{
				if (third[i] != 0)
				{
					hanoi = third[i];
					break;
				}
			}
			break;
		}

		switch (here)
		{
		case 1:
			for (int i = 4; i >= 0; i--)
			{
				if (first[i] == 0)
				{
					if (i != 4)
						under = first[i + 1];
					break;
				}
			}
			break;
		case 2:
			for (int i = 4; i >= 0; i--)
			{
				if (second[i] == 0)
				{
					if (i != 4)
						under = second[i + 1];
					break;
				}
			}
			break;
		case 3:
			for (int i = 4; i >= 0; i--)
			{
				if (third[i] == 0)
				{
					if (i != 4)
						under = third[i + 1];
					break;
				}
			}
			break;
		}
		if (hanoi > under && under != 0) {
			cout << "밑에보다 큰 수가 위로 갈 수 없습니다!" << endl;
			cout << "---------------------------------------" << endl;
		}
		else
		{
			succes = true;
		}

		under = 0, hanoi = 0;
		if (succes)
		{
			switch (move)
			{
			case 1:
				for (int i = 0; i < 5; i++)
				{
					if (first[i] != 0)
					{
						hanoi = first[i];
						first[i] = 0;
						break;
					}
				}
				break;
			case 2:
				for (int i = 0; i < 5; i++)
				{
					if (second[i] != 0)
					{
						hanoi = second[i];
						second[i] = 0;
						break;
					}
				}
				break;
			case 3:
				for (int i = 0; i < 5; i++)
				{
					if (third[i] != 0)
					{
						hanoi = third[i];
						third[i] = 0;
						break;
					}
				}
				break;
			}

			switch (here)
			{
			case 1:
				for (int i = 4; i >= 0; i--)
				{
					if (first[i] == 0)
					{
						first[i] = hanoi;
						break;
					}
				}
				break;
			case 2:
				for (int i = 4; i >= 0; i--)
				{
					if (second[i] == 0)
					{
						second[i] = hanoi;
						break;
					}
				}
				break;
			case 3:
				for (int i = 4; i >= 0; i--)
				{
					if (third[i] == 0)
					{
						third[i] = hanoi;
						break;
					}
				}
				break;
			}

			cout << "---------------------------------------" << endl;

			if (third[4] == 5 && third[3] == 4 && third[2] == 3 && third[1] == 2 && third[0] == 1)
			{
				cout << endl << "성공했습니다!" << endl;
				ViewHanoi(first, second, third);
				cout << endl << "성공했습니다!" << endl;
				cout << "---------------------------------------" << endl;
				return 0;
			}

		}
	}
}