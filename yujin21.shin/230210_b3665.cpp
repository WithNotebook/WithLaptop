#include <iostream>
#include <vector>
 
using namespace std;

vector<int> v;

void solve() {
	int map[555][555]={0,};
	int n; 
	cin >> n; 
	v.resize(n);
	
	for (auto& ranker : v) 
		cin >> ranker;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			map[v[i]][v[j]] = 1;
		}
	}
	int m; cin >> m;
	while (m--) {
		int src, dst; 
		cin >> src >> dst;
		swap(map[src][dst], map[dst][src]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (map[v[j]][v[i]]) 
				swap(v[i], v[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (map[v[j]][v[i]]) {
				cout << "IMPOSSIBLE\n"; 
				return;
			}
		}
	}
	for (auto i : v) cout << i << " "; cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int testCase; 
	cin >> testCase;
	while (testCase--) 
		solve();
}