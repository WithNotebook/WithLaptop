#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;

int N, M, K;
vector<pair<int, int>> v[1001]; 
priority_queue<int> dist[1001]; 

void dijk() {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0 ,1 });
	dist[1].push(0);
	while (!q.empty()) {
		int curDist = q.top().first;
		int curCity = q.top().second;
		q.pop();
		for (int i = 0; i < v[curCity].size(); i++) {
			int nextDist = v[curCity][i].second;
			int nextCity = v[curCity][i].first;
			if (dist[nextCity].size() < K) {
				dist[nextCity].push(curDist + nextDist);
				q.push({ curDist + nextDist,nextCity });
			}
			else if (dist[nextCity].top() > curDist + nextDist) {
				dist[nextCity].pop();
				dist[nextCity].push(curDist + nextDist);
				q.push({ curDist + nextDist,nextCity });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int a, b, c, i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	dijk();
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K) cout << "-1\n";
		else cout << dist[i].top() << "\n";
	}
}
