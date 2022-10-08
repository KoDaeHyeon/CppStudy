#include <iostream>

using namespace std;

struct Human
{
	char spec='c';
};


int main()
{
	cout << " c = 식인종, p = 선교사, B = 보트, 빈공간 - or c p 외 다른문자 " << endl << endl;
	Human Left[6] = { {'c'},{'c'},{'c'},{'p'},{'p'},{'p'}};
	Human Right[6] = { {'-'},{'-'},{'-'},{'-'},{'-'},{'-'} };

	int boat = 0;

	char move[3];

	while (1) {
		for (int i = 0; i < 6; i++)
			cout << Left[i].spec;

		if (boat == 0)
			cout << "  B ";

		cout << "    ~~~~~~~~~~~~~~~~    ";

		if (boat == 1)
			cout << "  B ";

		for (int i = 0; i < 6; i++)
			cout << Right[i].spec;

		cout << endl<<endl;

		if (boat == 0)
		{
			cout << "보낼 수 있는 사람" << endl <<endl;
			for (int i = 0; i < 6; i++)
				cout << Left[i].spec;
			cout << endl;
		}
		else
		{
			cout << "보낼 수 있는 사람" << endl << endl;
			for (int i = 0; i < 6; i++)
				cout << Right[i].spec;
			cout << endl;
		}

		bool success = false;
		cin >> move[0] >>move[1]>>move[2];
		for (int i = 0; i < 3; i++)
		{
			if (move[i] == 'c' || move[i] == 'p')
				success = true;
		}

		if (success)
		{
			if (boat == 0)
			{
				for (int k = 0; k < 3; k++)
				{
					char a = move[k];
					for (int i = 0; i < 6; i++)
					{
						if (Left[i].spec == a)
						{
							for (int j = 0; j < 6; j++)
								if (Right[j].spec == '-')
								{
									Right[j].spec = a;
									break;
								}
							Left[i].spec = '-';
							break;
						}
					}
				}
				boat = 1;
			}
			else
			{
				for (int k = 0; k < 3; k++)
				{
					char a = move[k];
					for (int i = 0; i < 6; i++)
					{
						if (Right[i].spec == a)
						{
							for (int j = 0; j < 6; j++)
								if (Left[j].spec == '-')
								{
									Left[j].spec = a;
									break;
								}
							Right[i].spec = '-';
							break;
						}
					}
				}
				boat = 0;
			}

			cout << endl << endl;

			int c(0), p(0);
			for (int i = 0; i < 6; i++)
			{
				if (Left[i].spec == 'c')
					c++;
				if (Left[i].spec == 'p')
					p++;
			}
			if (c > p && p != 0)
			{
				cout << "선교사가 식인종에게 잡아먹혔습니다!" << endl;
				return 0;
			}

			c = 0, p = 0;
			for (int i = 0; i < 6; i++)
			{
				if (Right[i].spec == 'c')
					c++;
				if (Right[i].spec == 'p')
					p++;
			}
			if (c > p && p != 0)
			{
				cout << "선교사가 식인종에게 잡아먹혔습니다!" << endl;
				return 0;
			}
			else if (c == 3 && p == 3)
			{
				cout << "무사히 다리를 건넜습니다!" << endl;
				return 0;
			}
		}
		else
		{
			cout << "건너갈 사람을 정확히 입력해 주세요." << endl;
		}
	}
}