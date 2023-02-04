#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

const long long MAXTIME = INT64_MAX;

struct city
{
	long long time;
	long long pos;
	long long count;

	bool operator<(const city& val) const
	{
		return (val.time < time);
	}
};

long long dist[10001][21];
vector<pair<long long, long long>> v[10001];
priority_queue<city> pq;

long long dijkstra(int start, int end, int k)
{
	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			dist[i][j] = MAXTIME;	
		}
	}	

    dist[start][0] = 0;

	pq.push({ 0, start, 0 });

	while (!pq.empty())
	{
		
		long long curPos = pq.top().pos;
		long long curTime = pq.top().time;
		long long curCount = pq.top().count;

		pq.pop();

		if (dist[curPos][curCount] < curTime)
		{
			continue;
		}

		for (int i = 0; i < v[curPos].size(); i++)
		{
			long long nextPos = v[curPos][i].first;
			long long nextTime = v[curPos][i].second;
		
			city next;
			next.pos = nextPos;
			next.time = nextTime + curTime;
			next.count = curCount;

			if (dist[nextPos][next.count] > next.time)
			{
				dist[nextPos][next.count] = next.time;	
				pq.push(next);
			}

			if (curCount < k)
			{
                next.pos = nextPos;
				next.time = curTime;
				next.count = curCount+1;

				if (dist[nextPos][next.count] > next.time)
				{
					dist[nextPos][next.count] = next.time;
					pq.push(next);
				}
			}
		}
	}

	long long result = MAXTIME;
	for (int i = 0; i <= k; i++)
	{
		result = min(result, dist[end][i]);
	}

	return result;
}

int main()
{

	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= M; i++)
	{
		long long A, B, time;
		scanf("%lld %lld %lld", &A, &B, &time);

		v[A].push_back(pair<long long, long long>(B, time));
		v[B].push_back(pair<long long, long long>(A, time));
	}

	
	long long result = dijkstra(1, N, K);

	printf("%lld\n", result);

	return 0;
}

