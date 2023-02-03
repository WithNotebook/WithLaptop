#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO
{
	int idx;
	int time;
};

bool operator<(const INFO& a, const INFO& b) {
	return a.time > b.time;
}

int main() {

	long long answer=1000001;
	int cityNum, roadNum, remodelingRoadNum;
	cin >> cityNum >> roadNum >> remodelingRoadNum;

	vector<bool> visited(cityNum + 1,false);
	vector<vector<INFO>> roadMap(cityNum + 1);
	queue <vector<INFO>> dijkstra;

	int src, dst, t;
	for (int i = 1; i <= roadNum; i++) {
		cin >> src >> dst >> t;
		roadMap[src].push_back({ dst,t });
		roadMap[dst].push_back({ src,t });
	}

	dijkstra.push({ {1,0} });
	while (!dijkstra.empty()) {
		vector<INFO> cur = dijkstra.front();
		int curLocation = cur.back().idx;
		int curSize = cur.size();
		dijkstra.pop();

		if (curSize > cityNum)
		{
			continue;
		}
		if (curLocation == cityNum) {
			if (curSize <= remodelingRoadNum) {
				answer = 0;
				break;
			}
			else {
				sort(cur.begin(), cur.end());
				long long sum = 0;
				for (int i = remodelingRoadNum; i < curSize; i++) {
					sum += cur[i].time;
				}
				answer = min(answer, sum);
			}
		}

		visited[curLocation] = true;
		for (INFO& info : roadMap[curLocation]) {
			if (!visited[info.idx]) {
				vector<INFO> next = cur;
				next.push_back({ info.idx,info.time });
				dijkstra.push(next);
			}
		}
	}
	cout << answer;
}