/*
n(1≤n≤1,000)개의 도시가 있다. 
그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다.
리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 
그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라. 
항상 시작점에서 도착점으로의 경로가 존재한다.

5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

4
3
1 3 5

*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct INFO {
	int idx;
	long long dist;
	int prevIdx;
};

bool operator<(INFO a, INFO b) {
	return a.dist > b.dist;
}

int main() {

	int cityNum, busNum;

	cin >> cityNum >> busNum;

	long long INF = cityNum * 100000 + 1;
	vector<vector<long long>> graph(1001, vector<long long>(1001, INF));
	vector<long long> dijkVector(10001, INF);
	int src, dst;
	long long cost;

	for (int i = 0; i < busNum; i++) {
		cin >> src >> dst >> cost;
		if (graph[src][dst] > cost)
		{
			graph[src][dst] = cost;
		}
	}
	cin >> src >> dst;

	//dijkstra
	vector<int> route(10001);
	vector<bool> visited(10001);
	priority_queue<INFO> pq;

	dijkVector[src] = graph[src][src]==INF?0:graph[src][src];
	pq.push({ src, 0, src });
		while (!pq.empty()) {
			INFO cur = pq.top();
			pq.pop();

			// 최소경로 체크
			if (visited[cur.idx]||(cur.dist > dijkVector[cur.idx]) )	continue;

			// 목적지 도착
			if (cur.idx == dst) {
				if (cur.dist <= dijkVector[dst]) {
					break;
				}
			}
			else {
				visited[cur.idx] = true;
				// 다양한 경로를 위한 pop
				for (int i = 1; i <= cityNum; i++) {
					if ((!visited[i]) && (cur.dist + graph[cur.idx][i] <= dijkVector[i])) {
						dijkVector[i] = cur.dist + graph[cur.idx][i];
						route[i] = cur.idx;
						pq.push({ i, cur.dist + graph[cur.idx][i], cur.idx });
					}
				}
			}
		}

		int cur = dst;

		vector<int> answer;
		while (cur != src) {
			answer.push_back(cur);
			cur = route[cur];
		}
		answer.push_back(src);


		cout << dijkVector[dst] << endl << answer.size()<<endl;
		for (int i = answer.size() - 1; i >= 0; i--)	cout << answer[i] << " ";
}