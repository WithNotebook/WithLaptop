 #include<stdio.h>
 #include<stack>


using namespace std;

int arr[1000];
int dp[1000];
stack<int> result;

int baekjoon14002()
{
    int num;
    scanf("%d", &num);

    for(int i = 0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0;
    for(int i = 0; i<num; i++)
    {
        dp[i] = 1;
        for(int j=0; j<=i; j++)
        {
            if(arr[j] < arr[i])
            {
                if(dp[i] <= dp[j])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            
            if(max < dp[i])
            {
                max = dp[i];
            }            
        }
    }

    printf("%d\n", max);
    
    int i = num;
    while(i>=0)
    {
       if(dp[i] == max)
       {
           result.push(arr[i]);
           max--;
       }  
        i--;
    }

    while (!result.empty())
    {
        printf("%d", result.top());
        result.pop();
        if(!result.empty())
        {
            printf(" ");
        }
    }


    return 0;
}