#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	int cityNum, busNum;


	cin >> cityNum >> busNum;

	long long INF = cityNum * 100000 + 1;
	vector<vector<long long>> map(1001, vector<long long>(1001, INF));
	vector<vector<int>> prevNode(1001, vector<int>(1001, -1));
	int src, dst;
	long long cost;

	for (int i = 0; i < busNum; i++) {
		cin >> src >> dst >> cost;
		if (map[src][dst] >= cost)
		{
			map[src][dst] = cost;
			prevNode[src][dst] = src;
		}
	}
	cin >>src >> dst;

	for (int k = 1; k <= cityNum; k++) {
		for (int i = 1; i <= cityNum; i++) {
			for (int j = 1; j <= cityNum; j++) {
				if (map[i][k] + map[k][j] <= map[i][j]) {
					map[i][j] = map[i][k] + map[k][j];
					prevNode[i][j] = k;
				}
			}
		}
	}

	vector<int> answer;
	int cur = dst;
	vector<bool> visited(100001);
	while (1) {
		if (visited[cur])
		{
			cur = prevNode[src][cur];
			continue;
		}
		else
		{
			visited[cur] = true;
			answer.push_back(cur);
			if (cur == src) {
				break;
			}
			else {
				cur = prevNode[src][cur];

			}
		}
	}

	cout<< map[src][dst] <<'\n'<< answer.size()<<'\n';
	while (!answer.empty()) {
		cout <<  answer.back() << " ";
		answer.pop_back();
	}
}