#include<stdio.h>
#include<algorithm>

using namespace std;

#define N_MAX 100001
#define INT_MAX 1000000001

long long tree[4 * N_MAX];
long long arr[N_MAX];

long long init(int start, int end, int node)
{
    if (start == end) return (tree[node] = arr[start]);

    int mid = (start + end) / 2;
    return (tree[node] = min(init(start, mid, node * 2), init(mid+1, end, node * 2 + 1)));
}

long long result(int start, int end, int node, int left, int right)
{
    if ((left > end) || (right < start)) return INT_MAX;
    if ((left<=start) && (end<=right)) return tree[node];

    int mid = (start + end) / 2;
    return min(result(start, mid, node*2, left, right), result(mid+1, end, node*2+1, left, right));
}

long long update(int start, int end, int node, int index, int diffVal)
{
    if((start > index) || (end < index)) return tree[node];
    if((start == end) && (start == index)) return (tree[node] = diffVal);
    if(start == end) return tree[node];
    
    int mid = (start + end) / 2;
    return (tree[node] = min(update(start, mid, node*2, index, diffVal), update(mid+1, end, node*2+1, index, diffVal)));
}

int main()
{
    int N, M;

    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        long long temp;
        scanf("%lld", &temp);
        arr[i] = temp;
    }

    init(1, N, 1);

    scanf("%d", &M);
    for(int i=1; i<=M; i++)
    {
        int flag;
        scanf("%d", &flag);
        if(flag == 1)
        {
            int i;
            long long  v;
            scanf("%d %lld", &i, &v);
            update(1, N, 1, i, v);
            arr[i] = v;
        }
        else
        {
            int i, j;
            scanf("%d %d", &i, &j);
            long long res = result(1, N, 1, i, j);
            printf("%lld\n", res);
        }
    }

    return 0;
}