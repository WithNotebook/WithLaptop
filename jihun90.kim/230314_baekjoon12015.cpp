#include<stdio.h>
#include<vector>

using namespace std;

int lowerBound(vector<int> &data, int start, int end, int target)
{
    int left = start;
    int right = end;

    while (left < right)
    {
        int mid =  (left + right) / 2;
        if(data.at(mid) < target) left = mid + 1;
        else right = mid;
    }

    return (right);
    
}

int main()
{
    int N;
    scanf("%d", &N);
    
    vector<int> dp(N+1);
    dp[0] = 0;
    int dpIndex = 0;
    for(int i=1; i<=N; i++)
    {
        int a;
        scanf("%d", &a);

        if(a > dp[dpIndex])
        {
            dpIndex++;
            dp[dpIndex] = a;
        }
        else
        {
            int index = lowerBound(dp, 0, dpIndex, a);
            dp[index] = a;
        }
    }

    printf("%d\n", dpIndex);

    return 0;
}