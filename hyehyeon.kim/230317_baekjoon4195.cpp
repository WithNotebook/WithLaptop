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

    int getSize(int p) {
        int pRoot = find(p);

        return size[pRoot];
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

    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++) {
        int F;
        cin >> F;

        int id = 1;
        unionFind* disjointSet = new unionFind(2 * F);
        map<string, int> people;

        for (int i = 0; i < F; i++) {
            string a, b;
            cin >> a >> b;

            if (people.find(a) == people.end()) {
                people.insert({ a, id++ });
            }

            if (people.find(b) == people.end()) {
                people.insert({ b, id++ });
            }

            disjointSet->doUnion(people[a], people[b]);
            cout << disjointSet->getSize(people[a]) << "\n";
        }
    }

    return 0;
};
