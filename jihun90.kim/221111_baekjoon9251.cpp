#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>

#define MAX 1000

using namespace std;

int dp[MAX+1][MAX+1];
string result;

int main()
{

    result = "";
    string str;
    getline(cin, str);
    str = " "+str;

    char c = getchar();
    
    int i = 1;
    while (c != '\n')
    {
        int len = str.length();
        for(int j=1; j<=len; j++)
        {
            if (str[j] == c)
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        } 
        i++;   
        c = getchar();
    }
    printf("%d", dp[i-1][str.length()]);
    return 0;
}