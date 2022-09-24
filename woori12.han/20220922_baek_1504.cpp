#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int dist[801];
vector<pair<int, int>> v[801];
void dijkstra(int s)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();

		if (dist[cur] < curDist)
		{
			continue;
		}

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextDist = v[cur][i].second + curDist;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
}

int main()
{
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	int v1, v2;
	cin >> v1 >> v2;

	//case1) minDist
	//1 - V1 까지의 최소 거리
	//V1- V2 까지의 최소 거리
	//V2 - N 까지의 최소 거리

	//case2) minDist2
	//1 - V2 까지의 최소 거리
	//V1- V2 까지의 최소 거리
	//V1 - N 까지의 최소 거리
	int minDist = 0, minDist2 = 0;

	fill(dist, dist + 801, INF);
	dijkstra(1);
	minDist += dist[v1];
	minDist2 += dist[v2];

	fill(dist, dist + 801, INF);
	dijkstra(v1);
	minDist += dist[v2];
	minDist2 += dist[v2];

	fill(dist, dist + 801, INF);
	dijkstra(N);
	minDist += dist[v2];
	minDist2 += dist[v1];

	cout << min(minDist, minDist2) << "\n";
	return 0;
}