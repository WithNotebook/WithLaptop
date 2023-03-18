#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int parent[200001];
int friend_num[200001];

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void makeUnion(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) {
		parent[b] = a;
		friend_num[a] += friend_num[b];
	}
	else if (a > b) {
		parent[a] = b;
		friend_num[b] += friend_num[a];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, cnt, num;
	string str1, str2;
	map<string, int> ::iterator it;
	cin >> test;
	for (int t = 0; t < test; t++) {
		m.clear();
		cnt = 0;
		for (int i = 0; i < 200001; i++) {
			parent[i] = i;
			friend_num[i] = 1;
		}

		cin >> num;
		int a, b;
		for (int i = 0; i < num; i++) {
			cin >> str1 >> str2;
			it = m.find(str1);
			if (it == m.end()) {
				m[str1] = ++cnt;
				a = cnt;
			}
			else a = it->second;

			it = m.find(str2);
			if (it == m.end()) {
				m[str2] = ++cnt;
				b = cnt;
			}
			else b = it->second;
			makeUnion(a, b);
			int root = findParent(a);
			cout << friend_num[root] << '\n';
		}
	}
	return 0;
}