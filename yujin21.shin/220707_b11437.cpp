#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct NODE {
	int depth = 1;
	int parent = 0;
};

int findCommonParent(vector<NODE> &tree, int nodeA, int nodeB) {

	if (tree[nodeA].depth > tree[nodeB].depth) swap(nodeA, nodeB);

	while (tree[nodeA].depth != tree[nodeB].depth) nodeB = tree[nodeB].parent;

	while (nodeA != nodeB) {
		nodeA = tree[nodeA].parent;
		nodeB = tree[nodeB].parent;
	}

	return nodeA;
}

int main() {
	int N, M;

	scanf("%d", &N);
	int src, dst;
	vector<vector<int>> nodeList(N + 1);
	vector<NODE> tree(N + 1);
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d", &src, &dst);
		nodeList[src].push_back(dst);
		nodeList[dst].push_back(src); //
	}
	
	vector<bool> check(N + 1);
	queue<int> q;
	q.push(1);
	check[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < nodeList[cur].size(); i++)
		{
			if (!check[nodeList[cur][i]]) //
			{
				tree[nodeList[cur][i]].depth = tree[cur].depth + 1;
				check[nodeList[cur][i]] = true; 
				tree[nodeList[cur][i]].parent = cur;
				q.push(nodeList[cur][i]);
			}
		}
	}

	scanf("%d", &M);
	int nodeA, nodeB;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &nodeA, &nodeB);
		printf("%d\n", findCommonParent(tree, nodeA, nodeB));
	}
}