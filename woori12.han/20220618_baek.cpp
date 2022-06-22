// 20220618_baek.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    long long remainValue = K;

    for (int i = 1; i <= 10; i++)
    {
        long long value = (pow(10, i) - pow(10, i - 1)) * i;
       
        if (remainValue <= value)
        {
            long long mok = remainValue / i;
            long long nam = remainValue % i;

            if (nam > 0)
            {
                long long theNumber = pow(10, i - 1) + mok;

                if (theNumber > N)
                {
                    cout << -1 << endl;
                }
                else
                {
                    char digit = to_string(theNumber).at(nam - 1);
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
                    int digit = theNumber % 10;
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