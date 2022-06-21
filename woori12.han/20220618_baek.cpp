// 20220618_baek.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int remainValue = K;

    for (int i = 1; i <= 10; i++)
    {
        int value = (pow(10, i) - pow(10, i - 1)) * i;
        
        if (remainValue == value)
        {
            cout << pow(10, i) - 1 << endl;
            break;
        }
        else if (remainValue < value)
        {
            int mok = remainValue / i;
            int nam = remainValue % i;

            if (nam > 0)
            {
                int theNumber = pow(10, i - 1) + mok;

                if (theNumber > N)
                {
                    cout << -1 << endl;
                }
                else
                {
                    int digit = 0;
                    for (int j = 0; j < nam; j++)
                    {
                        digit = theNumber / 10;
                        theNumber %= 10;
                    }
                    cout << digit << endl;
                }
                break;
            }
            else if (nam == 0)
            {
                long long theNumber = pow(10, i - 1) + mok - 1;
                if (theNumber > N)
                {
                    cout << -1 << endl;
                }
                else
                {
                    short digit = theNumber % 10;
                    cout << digit << endl;
                }
                break;
            }
        }
        else //remain > value
        {
            remainValue -= value;
        }
    }
    return 0;
}