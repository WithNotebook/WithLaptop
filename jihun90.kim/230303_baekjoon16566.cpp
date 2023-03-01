#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define N_MAX 4000001

int parent[N_MAX];

int findParent(int a)
{
    if(parent[a] == a) return a;

    return (parent[a] = findParent(parent[a]));
}

void uunion(int a, int b)
{
    int parentA = findParent(a);
    int parentB = findParent(b);

    if(parentA!=parentB) parent[parentA] = parentB;
}


int main()
{  
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    vector<int> v;
    for(int i=1; i<=N; i++) parent[i] = i;

    for(int i=1; i<=M; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    while(K--)
    {
        int num;
        scanf("%d", &num);
        int index = (upper_bound(v.begin(), v.end(), num) - v.begin());
        index = findParent(index);

        printf("%d\n", v[index]);
        uunion(index, index+1);
    }

    return 0;
}