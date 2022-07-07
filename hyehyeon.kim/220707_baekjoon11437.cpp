#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> tree[50001];
int depths[50001];
int parents[50001];

void cleanTree(int parent, int cur, int depth) {
	vector<int>::iterator it = tree[cur].begin();

	for (it; it != tree[cur].end(); it++) {
		if ((*it) == parent) {
			it = tree[cur].erase(it);

			if (it == tree[cur].end()) {
				return;
			}
		}

		parents[*it] = cur;
		depths[*it] = depth + 1;
		cleanTree(cur, *it, depth + 1);
	}
}


int findLCA(int a, int b) {
	while (true) {
		if (a == b) {
			return a;
		}

		if (depths[a] < depths[b]) {
			b = parents[b];
		}
		else {
			a = parents[a];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int root = 1;

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	cleanTree(-1, 1, 0);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << findLCA(a, b) << "\n";
	}

	return 0;
}