#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define N_MAX 1001

int A[N_MAX];
vector<int> dp;

int main()
{
    int N;
    scanf("%d", &N);

    dp.push_back(0);

    for(int i=1; i<=N; i++)
    {
        int a;
        scanf("%d", &a);
        A[i] = a;
        if(dp.back() < A[i]) dp.push_back(A[i]);
        else
        {
            vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), A[i]);
            if(it != dp.end()) (*it) = A[i];
        } 
    }

    printf("%d\n", (int)dp.size()-1);

    return 0;
}