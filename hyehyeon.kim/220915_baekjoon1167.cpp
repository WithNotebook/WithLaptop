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

const int MAX_V = 100000;

struct edge {
    int end;
    int dist;
};

vector<edge> adjList[MAX_V + 1];
bool visited[MAX_V + 1];

edge findLongest(edge cur) {
    visited[cur.end] = true;
    edge result = cur;

    for (auto it = adjList[cur.end].begin(); it != adjList[cur.end].end(); it++) {
        edge next = *it;

        if (visited[next.end]) continue;

        edge nextDFS = findLongest({ next.end, cur.dist + next.dist });

        if (nextDFS.dist > result.dist) {
            result = nextDFS;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V;
    cin >> V;

    for (int i = 0; i < V; i++) {
        int cur;
        cin >> cur;

        int next;
        cin >> next;

        while (next != -1) {
            int distance;
            cin >> distance;

            adjList[cur].push_back({ next, distance });
            adjList[next].push_back({ cur, distance });
            cin >> next;
        }
    }

    fill_n(visited, V + 1, false);
    edge u = findLongest({ 1, 0 });

    fill_n(visited, V + 1, false);
    edge v = findLongest({ u.end, 0 });

    cout << v.dist;

    return 0;
}