#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[201];
int dpLength[201];

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i<=N; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
    }


    for(int i = 1; i<=N; i++)
    {
        dpLength[i] = 1;
        for(int j = 1; j<i; j++)
        {
            if(arr[j] < arr[i])
            {
                dpLength[i] = max(dpLength[i], dpLength[j] + 1);
            }
        }
    }

    int count = 0;
    for(int i = 1; i<=N; i++)
    {
        if(dpLength[i] > count)
        {
            count++;
        }
    }

    printf("%d", N-count);

    return 0;
}