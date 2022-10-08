#include <iostream>

using namespace std;

int main()
{
    float a = 0, c = 0;
    int b = 0;
    int temp[20] = { 0 }, temp1[10] = { 0 };

    cout << "이진수 변환을 원하는 양수를 입력하세요. 소수점까지 가능합니다." << endl;
    cout << "(소수점 최대 10자리까지 표시됩니다. 종료는 -1 입니다.)" << endl << endl;
    while (1)
    {
        cout << "입력 : ";
        cin >> a;
        if (a == -1)
            break;
        b = a;
        c = a - b;

        cout << "이진수로 변환합니다.." << endl;
        int up = 0;
        while (b != 0)
        {
            if (b % 2 == 1)
            {
                temp[up] = 1;
            }
            else
            {
                temp[up] = 0;
            }
            b = b / 2;
            up++;
        }

        int down = 0;

        while (down< sizeof(temp1)/4)
        {
            c = c * 2;
           
            if (c >= 1)
            {
                temp1[down] = 1;
                down++;
                if (c == 1)
                    break;
                c = c - 1;
            }
            else
            {
                temp1[down] = 0;
                down++;
                if (c == 0 || int(c * 1000) == 0)
                    break;
            }
            
        }

        cout << "이진 값 : ";
        
        for (int j = up - 1; j >= 0; j--)
            cout << temp[j];
        
        if(down!=0)
            cout << '.';

        for (int j = 0; j < down; j++)
            cout << temp1[j];

        cout << endl << endl;
    }

}
