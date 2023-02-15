#include<stdio.h>
#include<algorithm>

using namespace std;

#define N_MAX 100001
#define INT_MAX 1000000001

long long tree[4 * N_MAX];
long long arr[N_MAX];

long long init(int start, int end, int node)
{
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node *2), init(mid +1, end, node*2 +1));
}

long long minValue(int start, int end, int node, int left, int right)
{
    if((left>end)||(right<start)) return INT_MAX;
    if((left<=start) && (end<=right)) return tree[node];

    int mid = (start + end) / 2;
    return min(minValue(start, mid, node *2, left, right), minValue(mid+1, end, node*2 +1, left, right));
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++)
    {
        long long num;
        scanf("%lld", &num);
        arr[i] = num;
    }

    init(1, N, 1);

    for(int i=1; i<=M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        long long result = minValue(1, N, 1, a, b);
        printf("%lld\n", result);
    }

    return 0;
}