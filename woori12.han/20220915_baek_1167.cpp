//1167 트리의 지름
#include<iostream>
#include <vector>
#include<math.h>
#include <queue>
#define INF 987654321
using namespace std;

int V; // 2 <= V <= 100000
vector<pair<int, int>> v[100001];
vector<int> node;
int distance1[100001];

int dijkstra(int s)
{
	priority_queue<pair<int, int>> pq;

	int maxDist = 0;
	distance1[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty())
	{
		int curDist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (distance1[curNode] < curDist) continue;

		for (int i = 0; i < v[curNode].size(); i++)
		{
			int newDist = curDist + v[curNode][i].first;
			int newNode = v[curNode][i].second;

			if (newDist < distance1[newNode])
			{
				distance1[newNode] = newDist;
				pq.push({ -newDist, newNode });
				maxDist = max(maxDist, newDist);
			}
		}
	}
	return maxDist;
}

int main()
{
	cin >> V;

	int start = 0;
	int end = 0;
	int dist = 0;
	for (int i = 0; i < V; i++)
	{
		cin >> start;
		node.push_back(start);
		while (1)
		{
			cin >> end;
			if (end == -1) break;
			cin >> dist;
			v[start].push_back({ dist, end });
		}		
	}

	int maxDist = 0;
	int newMaxDist = 0;
	int nodeX = 0;
	for(int i = 0; i < node.size(); i++)
	{
		fill(distance1, distance1 + 100001, INF);
		nodeX = node[i];
		newMaxDist = dijkstra(nodeX);
		maxDist = max(maxDist, newMaxDist);
	}

	cout << maxDist << "\n";
	return 0;
}