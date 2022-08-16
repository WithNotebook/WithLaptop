#pragma warning(disable:4996)

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int MAX_N = 100;

class unionFind {
private:
    int count;
    vector<int> id;
    vector<int> size;
public:
    unionFind(int n) {
        count = n;
        id.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            id[i] = i;
            size[i] = 1;
        }
    }

    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }

        return p;
    } 

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void doUnion(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) return;

        if (size[pRoot] < size[qRoot]) {
            id[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        }
        else {
            id[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        }

        count--;
    }
};

bool adjacentMatrix[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    memset(adjacentMatrix, false, MAX_N * MAX_N);

    unionFind* uf = new unionFind(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        uf->doUnion(a - 1, b - 1);
        adjacentMatrix[a - 1][b - 1] = true;
        adjacentMatrix[b - 1][a - 1] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                cache[i][j] = 0;
            }
            else if (adjacentMatrix[i][j]) {
                cache[i][j] = 1;
            }
            else {
                cache[i][j] = 1000;
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int cur = cache[i][k] + cache[k][j];

                if (cache[i][j] > cur) {
                    cache[i][j] = cur;
                }
            }
        }
    }

    int rootList[MAX_N];
    set<int> roots;

    for (int i = 0; i < N; i++) {
        rootList[i] = uf->find(i);
        roots.insert(rootList[i]);
    }

    int rankList[MAX_N];
    map<int, int> chiefs;
    fill_n(rankList, N, INT32_MAX);

    for (int i = 0; i < N; i++) {
        int curMax = INT32_MIN;

        for (int j = 0; j < N; j++) {
            if (rootList[i] != rootList[j]) continue;
            curMax = max(curMax, cache[i][j]);
        }

        int curRoot = rootList[i];

        if (rankList[curRoot] > curMax) {
            rankList[curRoot] = curMax;
            
            if (chiefs.find(curRoot) == chiefs.end()) {
                chiefs.insert({ curRoot, i });
            }
            else {
                chiefs[curRoot] = i;
            }
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto it = roots.begin(); it != roots.end(); it++) {
        pq.push(chiefs[*it]);
    }

    cout << roots.size() << "\n";

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        cout << cur + 1 << "\n";
    }

    return 0;
}