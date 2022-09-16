#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

struct INFO {
	int idx;
	int weight;
};
int answer = 0;
int maxIdx = 0;

void dfs(vector<vector<INFO>>& graph,vector<bool>& visited, int cur, int cnt) {

	if (visited[cur]) {
		return;
	}

	if (cnt > answer) {
		answer = cnt;
		maxIdx = cur;
	}
	visited[cur] = true;

	for (INFO info : graph[cur]) {
			dfs(graph, visited, info.idx, cnt + info.weight);
	}
}

int main() {
	
	int treeNodeNum;
	cin >> treeNodeNum;

	vector<vector<INFO>> graph(treeNodeNum);

	for (int i = 0; i < treeNodeNum; i++) {
		int node,idx, weight;
		cin >> node;
		node--;
		while (1) {
			cin >> idx;
			if (idx == -1) break;
			cin >> weight;
			idx--;
			graph[node].push_back({ idx,weight });
			graph[idx].push_back({ node,weight });
		}
	}
		vector<bool> visited(treeNodeNum);
		dfs(graph, visited, 0, 0);
		visited = vector<bool>(treeNodeNum);
		dfs(graph, visited, maxIdx, 0);

	cout << answer << endl;
}