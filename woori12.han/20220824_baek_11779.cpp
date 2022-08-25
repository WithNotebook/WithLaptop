#include<iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[100001];
int dist[100001];
int path[100001];

void dijkstra(int s)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty())
	{
		int nowCost = -pq.top().first;
		int nowNode = pq.top().second;
		pq.pop();

		//현재까지의 cost가 이미 dist에 찾은 최소 비용보다 크면 더 탐색할 필요 없으므로 continue
		if (dist[nowNode] < nowCost)
		{
			continue;
		}

		//queue에서 꺼낸 노드와 연결된 노드들을 탐색
		for (int i = 0; i < graph[nowNode].size(); i++)
		{
			int newNode = graph[nowNode][i].first;
			int newCost = nowCost + graph[nowNode][i].second;

			if (dist[newNode] > newCost)
			{
				dist[newNode] = newCost;
				pq.push({ -newCost, newNode });
				path[newNode] = nowNode;
			}
		}
	}
}

int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
	}
	
	int start, end;
	cin >> start >> end;
	
	//각 노드까지의 거리를 INF값으로 초기화
	fill(dist, dist + 100001, INF);

	//다익스트라 알고리즘 수행해서 dist 업데이트
	dijkstra(start);

	//최소비용, start -> end 까지의 path에 몇개의 노드가 있는지, 해당 path출력
	cout << dist[end] << "\n";
	int index = end;
	int count = 1;
	vector<int> v;
	v.push_back(end);
	while (index != start)
	{
		index = path[index];
		v.push_back(index);
		count++;
	}
	cout << count << "\n";
	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
	return 0;
}