#include<stdio.h>

using namespace std;

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int dp[11] = {0,};
    dp[1] = 1; //1
    dp[2] = 2; //2, 1+1
    dp[3] = 4; //3, 2+1, 1+2, 1+1

    for(int i=4; i<=10; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    for(int i=0; i<testcase; i++)
    {
        int temp;
        scanf("%d", &temp);
        printf("%d\n", dp[temp]);
    }
    return 0;
}