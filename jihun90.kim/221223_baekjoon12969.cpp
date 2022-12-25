#include<stdio.h>

char text[31];
int N, K;
bool visited[31][31][31][451];

bool dfs(int n, int a, int b, int k)
{
    if(N == n)
    {
        if(K == k) return true;
        else return false;
    }
    
    if (visited[n][a][b][k]) return false;

    text[n] = 'A';
    if (dfs(n+1, a+1, b, k)) return true;
    else visited[n+1][a+1][b][k] = true;

    text[n] = 'B';
    if (dfs(n+1, a, b+1, k+a)) return true;
    else visited[n+1][a][b+1][k+a] = true;

    text[n] = 'C';
    if (dfs(n+1, a, b, k+a+b)) return true;
    else visited[n+1][a][b][k+a+b] = true;

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
        return 0;
    }

    text[0] = 'B';
    result = dfs(1, 0, 1, 0);
    if (result) 
    {
        printf("%s", text);
        return 0;
    }

    text[0] = 'C';
    result = dfs(1, 0, 0, 0);
    if (result) 
    {
        printf("%s", text);
        return 0;
    }

    printf("-1");
    return 0;
}