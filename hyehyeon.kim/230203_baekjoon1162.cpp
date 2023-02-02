#pragma warning(disable:4996)

#include <iostream>
#include<stdio.h>
#include<vector>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>

using namespace std;

const int MAX_N = 10000;
const int MAX_K = 20;
const long long MAX_VALUE = 1000000LL * 60000LL;

struct road {
    int end;
    long long time;
};

struct node {
    int cur;
    int remain;
    long long time;
};

bool operator < (node a, node b) {
    return a.time < b.time;
}

bool operator > (node a, node b) {
    return a.time > b.time;
}

vector<road> adjList[MAX_N + 1];
long long times[MAX_N + 1][MAX_K + 1];
bool visited[MAX_N + 1];

long long findMin(int N, int remain) {
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push(node{ 1, remain, 0 });

    long long ret = MAX_VALUE;
    times[1][remain] = 0;
    fill(times[0], times[0] + (MAX_N + 1) * (MAX_K + 1), MAX_VALUE);

    while (!pq.empty()) {
        node curNode = pq.top();
        pq.pop();

        if (curNode.time > times[curNode.cur][curNode.remain]) continue;
        times[curNode.cur][curNode.remain] = curNode.time;

        if (curNode.cur == N) {
            ret = min(ret, curNode.time);
            continue;
        }        

        for (auto it = adjList[curNode.cur].begin(); it != adjList[curNode.cur].end(); it++) {
            road next = *it;

            if (times[next.end][curNode.remain] > curNode.time + next.time) {
                pq.push(node{ next.end, curNode.remain, curNode.time + next.time });
            }            

            if (curNode.remain > 0 && times[next.end][curNode.remain - 1] > curNode.time) {
                pq.push(node{ next.end, curNode.remain - 1, curNode.time });
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        adjList[a].push_back(road{ b, t });
        adjList[b].push_back(road{ a, t });
    }

    cout << findMin(N, K);

    return 0;
}