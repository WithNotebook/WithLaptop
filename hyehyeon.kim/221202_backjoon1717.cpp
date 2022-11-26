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

using namespace std;

class unionFind {
private:
    int* id;
    int* size;
    int count;
public:
    unionFind(int N) {
        count = N + 1;
        id = new int[N + 1];
        size = new int[N + 1];

        for (int i = 0; i <= N; i++) {
            id[i] = i;
            size[i] = 1;
        }
    }

    int getCount() {
        return count;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }

        return p;
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
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unionFind* disjointSet = new unionFind(n);

    for (int i = 0; i < m; i++) {
        int c, a, b;
        cin >> c >> a >> b;

        if (c == 0) {
            disjointSet->doUnion(a, b);
        }
        else if (c == 1) {
            if (disjointSet->isConnected(a, b)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
};