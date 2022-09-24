#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define INF 987654321

using namespace std;

int main() {
	int nodeNum, edgeNum;
	cin >> nodeNum >> edgeNum;

	vector<vector<int>> graph(nodeNum,vector<int>(nodeNum,INF));

	int src,dst,weight;
	for (int i = 0; i < edgeNum; i++) {
		cin >> src >> dst >> weight;
		src--; dst--;
		graph[src][dst] = weight;
		graph[dst][src] = weight;
	}

	for (int i = 0; i < nodeNum; i++)	graph[i][i] = 0;

	int needNode1, needNode2;
	cin >> needNode1 >> needNode2;
	needNode1--; needNode2--;

	// 플로이드
	for (int k = 0; k < nodeNum; k++) {
		for (int i = 0; i < nodeNum; i++) {
			for (int j = 0; j < nodeNum; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int answer = -1;

	if (graph[0][needNode1] == INF || graph[needNode1][needNode2] == INF || graph[needNode2][nodeNum - 1] == INF)
	{
	}
	else
	{
		answer = min((graph[0][needNode1] + graph[needNode1][needNode2] + graph[needNode2][nodeNum - 1]),
			(graph[0][needNode2] + graph[needNode2][needNode1] + graph[needNode1][nodeNum - 1]));
	}

	cout << answer;
}