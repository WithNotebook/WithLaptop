#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, K = 0;
vector<pair<int, int>> map[10001];
long long costs[10001][21];

struct node {
	long long cost;
	int point;
	int count;

	bool operator<(const node& a) const
	{
		return cost > a.cost;
	}
};

void dijkstra()
{
	memset(costs, -1, sizeof(costs));

	priority_queue<node> pq;
	pq.push({0, 1, 0});
	costs[1][0] = 0;

	while (!pq.empty())
	{
		int current_node = pq.top().point;
		int count = pq.top().count;
		long long cost = pq.top().cost;
		pq.pop();

		if (cost > costs[current_node][count]) continue;

		for (pair<int, int> next : map[current_node])
		{
			int next_node = next.first;
			long long next_cost = cost + next.second;

			if ((costs[next_node][count] == -1) || (costs[next_node][count] > next_cost))
			{
				costs[next_node][count] = next_cost;
				pq.push({next_cost, next_node, count});
			}
			if (((count + 1) <= K) && ((costs[next_node][count + 1] == -1) || (costs[next_node][count + 1] > cost)))
			{
				costs[next_node][count + 1] = cost;
				pq.push({cost, next_node, count + 1});
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= M; i++)
	{
		int sou, des, cos = 0;
		scanf("%d %d %d", &sou, &des, &cos);

		map[sou].push_back(make_pair(des, cos));
		map[des].push_back(make_pair(sou, cos));
	}

	dijkstra();

	long long result = -1;
	for (int i = 0; i <= K; i++)
	{
		if (costs[N][i] == -1) continue;
		if (result == -1) result = costs[N][i];
		else
		{
			result = min(result, costs[N][i]);
		}
	}
	printf("%lld", result);
	return 0;
}