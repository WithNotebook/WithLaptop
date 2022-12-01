#include<stdio.h>

int root[1000001];

int find(int x)
{
    if (x == root[x])
    {
        return x;
    }
    return (root[x] = find(root[x]));
}

void uni(int a, int b)
{
    int parentA = find(a);
    int parentB = find(b);

    root[parentB] = parentA;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int f, a, b;
        scanf("%d %d %d", &f, &a, &b);
        if (f == 0)
        {
            uni(a, b);
        }
        else
        {
            a = find(a);
            b = find(b);
            if (a == b)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }

    return 0;
}

