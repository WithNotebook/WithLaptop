#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define N_MAX 100001


struct team
{
    long long sum;
    long long min;
};

struct battle
{
    team teamA;
    team teamB;
};

long long aTeam[N_MAX];
long long bTeam[N_MAX];

battle battleTree[N_MAX*4];
long long result[N_MAX*4];

battle init(int start, int end, int node)
{
    battle result;
    if(start == end)
    {
        result.teamA.min = aTeam[start];
        result.teamA.sum = aTeam[start];
        result.teamB.min = bTeam[start];
        result.teamB.sum = bTeam[start];
        return (battleTree[node] = result);
    }

    int mid = (start + end) /2;
    
    battle battle1 = init(start, mid, node*2);
    battle battle2 = init(mid+1, end, node*2+1);

    team a;
    team b;

    //teamA
    a.sum = battle1.teamA.sum + battle2.teamA.sum; 
    a.min = min(battle1.teamA.min, battle2.teamA.min);

    //teamB;
    b.sum = battle1.teamB.sum + battle2.teamB.sum; 
    b.min = min(battle1.teamB.min, battle2.teamB.min);

    result.teamA = a;
    result.teamB = b;

    return (battleTree[node] = result);
}

team printTeamA(int start, int end, int node, int left, int right)
{
    if((right<start) || (end < left)) return team({0, N_MAX});
    if((left <= start) && (end <= right)) return battleTree[node].teamA;

    int mid = (start + end) /2;
    team t1 = printTeamA(start, mid, node*2, left, right);
    team t2 = printTeamA(mid+1, end, node*2+1, left, right);

    team a;
    a.sum = t1.sum + t2.sum;
    a.min = min(t1.min, t2.min);
    
    return a;
}

team printTeamB(int start, int end, int node, int left, int right)
{
    if((right<start) || (end < left)) return team({0, N_MAX});
    if((left <= start) && (end <= right)) return battleTree[node].teamB;

    int mid = (start + end) /2;
    team t1 = printTeamB(start, mid, node*2, left, right);
    team t2 = printTeamB(mid+1, end, node*2+1, left, right);

    team b;
    b.sum = t1.sum + t2.sum;
    b.min = min(t1.min, t2.min);
    
    return b;
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for(int i=1; i<=N; i++)
    {
        long long player;
        scanf("%lld", &player);
        aTeam[i] = player;
    }

    for(int i=1; i<=N; i++)
    {
        long long player;
        scanf("%lld", &player);
        bTeam[i] = player;
    }

    init(1, N, 1);
    vector<long long> vA;
    vector<long long> vB;

    for(int i=1; (i+K-1)<=N; i++)
    {
        int end = i+K-1;
        team tempA = printTeamA(1, N, 1, i, end);
        team tempB = printTeamB(1, N, 1, i, end);
        
        vA.push_back(tempA.sum - (tempA.min + tempA.min));
        vB.push_back(tempB.sum - (tempB.min + tempB.min));
    }

    sort(vA.begin(), vA.end(), greater<long long>());
    sort(vB.begin(), vB.end(), greater<long long>());

    long long result = N_MAX * K;
    for(auto i : vA)
    {
        long long a = i;
        for(auto j : vB)
        {
            long long b = j;
            long long temp = abs(a-b);
            
            if (temp > result) break;
            
            result = min(result, temp);
        }
        if(result == 0 ) break;
    }

    printf("%lld", result);

    return 0;
}