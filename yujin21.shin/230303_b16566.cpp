#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

vector<int> cardNumber;
int parent[4000001];

int find(int num) {
	if (parent[num] == num) return num;
	else return parent[num] = find(parent[num]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	parent[u] = v;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N,M,K,number; 
	cin >> N>>M>>K;
	for (int i = 0; i < M; i++) {
		cin >> number;
		cardNumber.push_back(number);
		parent[i] = i;
	}
	sort(cardNumber.begin(), cardNumber.end());
	for (int i = 0; i < K; i++) {
		cin >> number;
		int idx = find(upper_bound(cardNumber.begin(), cardNumber.end(), number) - cardNumber.begin());
		cout << cardNumber[idx] << '\n';
		merge(idx, idx + 1);
	}

}