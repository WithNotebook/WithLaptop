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
#include <stack>
#include <list>

using namespace std;

const int MAX_N = 3000;

vector<int> adjList[MAX_N + 1];
list<int> tempadjList[MAX_N + 1];
int distances[MAX_N + 1];
bool branchLines[MAX_N + 1];
bool visited[MAX_N + 1];
vector<int> hubs;
vector<int> edges;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
        tempadjList[s].push_back(e);
        tempadjList[e].push_back(s);
    }

    for (int i = 1; i <= N; i++) {
        distances[i] = 0;
        branchLines[i] = false;
        visited[i] = false;

        if (adjList[i].size() == 1) {
            edges.push_back(i);
        }
    }

    for (auto it = edges.begin(); it != edges.end(); it++) {
        int cur = *it;
        int next = *(tempadjList[cur].begin());

        while (true) {
            branchLines[cur] = true;
            tempadjList[next].remove(cur);

            if (tempadjList[next].size() >= 2) {
                break;
            }

            cur = next;
            next = *(tempadjList[cur].begin());
        }
    }

    for (int i = 1; i <= N; i++) {
        if (branchLines[i]) continue;

        if (adjList[i].size() >= 3) {
            hubs.push_back(i);
        }
    }

    for (auto it = hubs.begin(); it != hubs.end(); it++) {
        stack<pair<int, int>> bfsStack;
        bfsStack.push(make_pair(*it, 0));

        while (!bfsStack.empty()) {
            pair<int, int> cur = bfsStack.top();
            bfsStack.pop();
            visited[cur.first] = true;

            distances[cur.first] = cur.second;

            for (auto it2 = adjList[cur.first].begin(); it2 != adjList[cur.first].end(); it2++) {
                if ((visited[*it2]) || (!branchLines[*it2])) continue;

                bfsStack.push(make_pair(*it2, cur.second + 1));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << distances[i] << " ";
    }

    return 0;
};