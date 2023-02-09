#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int T, N, M = 0;
int order[501];
int indegree[501];
vector<int> graph[501];

int main()
{
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++)
	{		
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &order[i]);
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = (i + 1); j <= N; j++)
			{
				graph[order[j]].push_back(order[i]);
				indegree[order[i]]++;
			}
		}
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
		{
			int a, b = 0;
			scanf("%d %d", &a, &b);

			auto it = find(graph[a].begin(), graph[a].end(), b);
			if (it != graph[a].end())
			{
				graph[a].erase(it);
				indegree[b]--;
				graph[b].push_back(a);
				indegree[a]++;
			}
			else
			{
				it = find(graph[b].begin(), graph[b].end(), a);
				graph[b].erase(it);
				indegree[a]--;
				graph[a].push_back(b);
				indegree[b]++;
			}
		}
		queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		vector<int> result;
		for (int i = 1; i <= N; i++)
		{
			if (q.empty())
			{
				printf("IMPOSSIBLE");
				break;
			}
			int cur = q.front();
			q.pop();

			if (q.size() > 0)
			{
				printf("?");
				break;
			}
			else
			{
				result.push_back(cur);
			}

			for (int j = 0; j < graph[cur].size(); j++)
			{
				int next = graph[cur][j];
				indegree[next]--;
				if (indegree[next] == 0)
				{
					q.push(next);
				}
			}
		}
		if (result.size() == N)
		{
			for (int i = 0; i < N; i++)
			{
				printf("%d ", result[(N-1)-i]);
			}
		}
		printf("\n");

		memset(order, 0, sizeof(order));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}
	}
	return 0;
}