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

int peoples[MAX_N + 1];
vector<int> adjList[MAX_N + 1];
int cache[MAX_N + 1][2];

int calculate(int cur, int parent, bool prev) {
    int& ret = cache[cur][prev];

    if (ret != -1) return ret;

    int choose = peoples[cur];
    int notChoose = 0;

    if (parent != -1 && adjList[cur].size() == 1 && !prev) {
        return ret = choose;
    }

    for (auto it = adjList[cur].begin(); it != adjList[cur].end(); it++) {
        if ((*it) == parent) continue;

        choose += calculate(*it, cur, true);
        notChoose += calculate(*it, cur, false);
    }

    if (prev) {
        return ret = notChoose;
    }
    else {
        return ret = max(choose, notChoose);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; i++) {
        cin >> peoples[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;

        adjList[U].push_back(V);
        adjList[V].push_back(U);
    }

    int root = -1;

    for (int i = 1; i <= N; i++) {
        if (adjList[i].size() == 1) {
            root = i;
            break;
        }
    }

    int ret = calculate(root, -1, false);

    cout << ret;

    return 0;
}