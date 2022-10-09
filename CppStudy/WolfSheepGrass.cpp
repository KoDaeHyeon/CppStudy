#include <iostream>

using namespace std;

struct Pack {
	char type = '-';
};



int main()
{
	cout << " W = ����, S = ��, G = Ǯ ,B = ��Ʈ" << endl;
	cout << "ȥ�� ���ƿ��� - �Է�" << endl << endl;
	Pack Left[3] = { {'W'},{'S'},{'G'}};
	Pack Right[3] = { {'-'},{'-'},{'-'}};
	int boat = 0;
	char move = '-';

	while (1) {
		cout << endl ;

		for (int i = 0; i < 3; i++)
			cout << Left[i].type;

		if (boat == 0)
			cout << "  B ";

		cout << "    ~~~~~~~~~~~~~~~~    ";

		if (boat == 1)
			cout << "  B ";

		for (int i = 0; i < 3; i++)
			cout << Right[i].type;

		cout << endl << endl;

		bool w(false), s(false), g(false);
		if (boat == 0)
		{
			cout << "�ű� ��" << endl << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << Left[i].type;
				if (Left[i].type == 'W')
					w = true;
				else if (Left[i].type == 'S')
					s = true;
				else if (Left[i].type == 'G')
					g = true;
			}
			cout << endl;
		}
		else
		{
			cout << "�ű� ��" << endl << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << Right[i].type;
				if (Right[i].type == 'W')
					w = true;
				else if (Right[i].type == 'S')
					s = true;
				else if (Right[i].type == 'G')
					g = true;
			}
			cout << endl;
		}

		bool success = false;

		cin >> move;
		for (int i = 0; i < 3; i++)
		{
			if ((move == 'W'&&w) || (move == 'S'&&s) || (move =='G'&&g) || move == '-')
				success = true;
		}

		if (success)
		{
			if (boat == 0)
			{
				if (move != '-')
				{
					for (int i = 0; i < 3; i++)
					{
						if (Left[i].type == move)
						{
							for (int j = 0; j < 3; j++)
							{
								if (Right[j].type == '-')
								{
									Right[j].type = move;
									break;
								}
							}
							Left[i].type = '-';
							break;
						}
					}
				}
				boat = 1;
			}
			else
			{
				if (move != '-')
				{
					for (int i = 0; i < 3; i++)
					{
						if (Right[i].type == move)
						{
							for (int j = 0; j < 3; j++)
							{
								if (Left[j].type == '-')
								{
									Left[j].type = move;
									break;
								}
							}
							Right[i].type = '-';
							break;
						}
					}
				}
				boat = 0;
			}
			w=false, s=false, g=false;

			for (int i = 0; i < 3; i++)
			{
				if (Right[i].type == 'W')
					w = true;
				else if (Right[i].type == 'S')
					s = true;
				else if (Right[i].type == 'G')
					g = true;
			}
			if (w && s && g)
			{
				cout << "������ ���� �ǳԽ��ϴ�!" << endl;
				return 0;
			}
			else 
			{
				w = false, s = false, g = false;
			}

			if (boat == 1)
			{
				for (int i = 0; i < 3; i++)
				{
					if (Left[i].type == 'W')
						w = true;
					else if (Left[i].type == 'S')
						s = true;
					else if (Left[i].type == 'G')
						g = true;
				}
			}
			else 
			{
				for (int i = 0; i < 3; i++)
				{
					if (Right[i].type == 'W')
						w = true;
					else if (Right[i].type == 'S')
						s = true;
					else if (Right[i].type == 'G')
						g = true;
				}
			}



			if (w && s)
			{
				cout << "���밡 ���� ��ƸԾ����ϴ�!" << endl;
				return 0;
			}
			else if (g && s)
			{
				cout << "���� Ǯ�� �Ծ����ϴ�!" << endl;
				return 0;
			}
		}
		else
		{
			cout << "�ű� ǰ���� ����� �Է��ϼ���!" << endl;
		}
		cout << "--------------------------------------------------------" << endl;
	}
}