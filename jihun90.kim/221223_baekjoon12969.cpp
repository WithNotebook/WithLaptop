#include<stdio.h>

char text[31];
int N, K;

bool dfs(int n, int a, int b, int k)
{
    if(N == n)
    {
        if(K == k) return true;
        else return false;
    }

    text[n] = 'A';
    if (dfs(n+1, a+1, b, k)) return true;

    text[n] = 'B';
    if (dfs(n+1, a, b+1, k+a)) return true;

    text[n] = 'C';
    if (dfs(n+1, a, b, k+a+b)) return true;

    return false;
}

int main()
{
    scanf("%d %d", &N, &K);

    text[0] = 'A';
    bool result = dfs(1, 1, 0, 0);
    if (result) 
    {
        printf("%s", text);
    }

    text[0] = 'B';
    result = dfs(1, 0, 1, 0);
    if (result) 
    {
        printf("%s", text);
    }

    text[0] = 'C';
    result = dfs(1, 0, 0, 0);
    if (result) 
    {
        printf("%s", text);
    }
    return 0;
}