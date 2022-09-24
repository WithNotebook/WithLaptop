//1167 트리의 지름
#include<iostream>
#include <vector>
using namespace std;

int V; // 2 <= V <= 100000
vector<pair<int, int>> v[100001];
int visited[100001];

int maxDist = 0;
int maxDistEnd = 0;
void dfs(int s, int dist)
{
	visited[s] = 1;

	for (int i = 0; i < v[s].size(); i++)
	{
		if (visited[v[s][i].first] == 0)
		{
			if (maxDist < dist + v[s][i].second)
			{
				maxDist = dist + v[s][i].second;
				maxDistEnd = v[s][i].first;
			}
			dfs(v[s][i].first, dist + v[s][i].second);
		}
	}
}

int main()
{
	cin >> V;

	int start, end, dist;
	for (int i = 0; i < V; i++)
	{
		cin >> start;
		while (1)
		{
			cin >> end;
			if (end == -1) break;
			cin >> dist;
			v[start].push_back({ end, dist });
		}		
	}
	maxDist = 0;
	dfs(1, 0);
	maxDist = 0;
	fill(visited, visited + 100001, 0);
	dfs(maxDistEnd, 0);

	cout << maxDist << "\n";
	return 0;
}