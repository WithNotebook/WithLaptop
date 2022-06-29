#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	int startCity, endCity;

	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int>>> cityMap(n+1);
	vector<vector<pair<int, int>>> recityMap(n + 1);
	vector<int> entry(n + 1), weight(n + 1);

	//
	int srcNode, dstNode, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &srcNode, &dstNode, &w);
		cityMap[srcNode].push_back({ dstNode, w });
		recityMap[dstNode].push_back({ srcNode, w });
		entry[dstNode]++;
	}

	//
	scanf("%d %d", &startCity, &endCity);
	queue<pair<int, int>> q;
	q.push({ startCity, 0 });
	while (!q.empty()) {
		int curNode = q.front().first;
		int curWeight = q.front().second;
		q.pop();

		for (int i = 0; i < cityMap[curNode].size(); i++) {
			int nextNode = cityMap[curNode][i].first;
			int nextWeight = cityMap[curNode][i].second;

			weight[nextNode] = max(weight[nextNode], nextWeight + curWeight);
			entry[nextNode]--;

			if (entry[nextNode] == 0) 
					q.push({ nextNode,weight[nextNode] });
		}

	}

	//
	vector<bool> visit(n + 1);
	queue<int> rq;
	rq.push(endCity);
	visit[endCity] = true;
	int answerRoadCount = 0;

	while (!rq.empty()) {
		int curNode = rq.front();
		rq.pop();

		for (int i = 0; i < recityMap[curNode].size(); i++) {
			int nextNode = recityMap[curNode][i].first;
			int nextWeight = recityMap[curNode][i].second;

			if (weight[curNode] - nextWeight == weight[nextNode]) {
				answerRoadCount++;
				if (!visit[nextNode]) {
					visit[nextNode] = true;
					rq.push(nextNode);
				}
			}
		}
	}
	
	printf("%d %d", weight[endCity], answerRoadCount);
}