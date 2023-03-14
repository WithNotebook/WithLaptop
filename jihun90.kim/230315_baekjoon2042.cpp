
#include<stdio.h>

using namespace std;

#define N_MAX 1000001

long long tree[N_MAX * 4];
long long arr[N_MAX];

long long init(int start, int end, int node)
{
    if(start == end) return (tree[node]=arr[start]);
    int mid = (start + end) / 2;

    return (tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1));
}

long long print(int start, int end, int node, int left, int right)
{
    if ((end<left) || (right < start)) return 0; 
    if((left<=start) && (end <= right)) return tree[node];

    int mid = (start + end) / 2;
    return (print(start, mid, node*2, left, right) + print(mid+1, end, node*2+1,left, right));
}

void update(int start, int end, int node, int target, long long diff)
{
    if(target<start || target>end) return;
    tree[node] += diff;
    if(start == end) return;

    int mid = (start + end)/2;
    update(start, mid, node*2, target, diff);
    update(mid+1, end, node*2+1, target, diff);
}

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    for(int i=1; i<=N; i++)
    {
        long long a;
        scanf("%lld", &a);
        arr[i] = a;
    }
    init(1, N, 1);

    for(int i=1; i<=M+K; i++)
    {
        int a;
        long long b, c;
        scanf("%d %lld %lld", &a, &b, &c);
        if(a==1)
        {
            long long diff = c-arr[b];
            arr[b] = c;
            update(1, N, 1, b, diff);
        }
        else
        {
            printf("%lld\n",print(1, N, 1, (int)b, (int)c));
        }

    }

    return 0;
}