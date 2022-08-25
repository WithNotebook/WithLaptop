#pragma warning(disable:4996)

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int MAX_N = 1000;

struct bus {
    int end;
    int value;
};

vector<bus> adjList[MAX_N + 1];
int dist[MAX_N + 1];
int cache[MAX_N + 1];
int startPoint, endPoint;

priority_queue<pair<int, int>> pq;

void dijkstra() {
    pq.push({ 0, startPoint });
    dist[startPoint] = 0;
    cache[startPoint] = -1;

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        int curDist = -cur.first;
        int curPoint = cur.second;
        
        if (curDist > dist[curPoint]) continue;

        for (auto it = adjList[curPoint].begin(); it != adjList[curPoint].end(); it++) {
            bus next = *it;
            int nextDist = curDist + next.value;

            if (dist[next.end] <= nextDist) continue;

            dist[next.end] = nextDist;
            pq.push({ -nextDist, next.end });
            cache[next.end] = curPoint;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    fill_n(dist, n + 1, 2000000000);
    fill_n(cache, n + 1, -1);

    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        adjList[s].push_back({ e, v });
    }

    cin >> startPoint >> endPoint;

    dijkstra();

    cout << dist[endPoint] << "\n";

    vector<int> visitings;
    int curVisiting = endPoint;

    while (curVisiting != -1) {
        visitings.push_back(curVisiting);
        curVisiting = cache[curVisiting];
    }

    cout << visitings.size() << "\n";

    for (auto it = visitings.rbegin(); it != visitings.rend(); it++) {
        cout << *it << " ";
    }

    return 0;
}