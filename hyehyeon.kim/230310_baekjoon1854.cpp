#include<cmath>
#include<vector>
#include<iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 1000;

struct road {
    int end;
    int time;
};

struct path {
    int city;
    int totalTime;
};

bool operator < (path a, path b) {
    return a.totalTime < b.totalTime;
}

bool operator > (path a, path b) {
    return a.totalTime > b.totalTime;
}

vector<road> adjList[MAX_N + 1];
priority_queue<int> times[MAX_N + 1];

void kthDijkstra(int K) {    
    priority_queue<path, vector<path>, greater<path>> pq;

    times[1].push(0);
    pq.push(path{ 1, 0 });

    while (!pq.empty()) {
        path cur = pq.top();
        pq.pop();

        for (road next : adjList[cur.city]) {
            int nextTime = cur.totalTime + next.time;

            if (times[next.end].size() < K) {
                times[next.end].push(nextTime);
                pq.push(path{ next.end, cur.totalTime + next.time });
            }
            else if (times[next.end].top() > nextTime) {
                times[next.end].pop();
                times[next.end].push(nextTime);
                pq.push(path{ next.end, cur.totalTime + next.time });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adjList[a].push_back(road{ b, c });
    }

    kthDijkstra(K);

    for (int i = 1; i <= N; i++) {
        if (times[i].size() < K) {
            cout << -1 << "\n";
        }
        else {
            cout << times[i].top() << "\n";
        }
    }
    
    return 0;
}