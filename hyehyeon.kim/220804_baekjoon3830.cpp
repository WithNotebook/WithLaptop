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

const int MAX_N = 100000;

struct connection {
    bool isConnected;
    long long diff;
};

class WeightedQuickUnionUF {
private:
    vector<int> id;
    vector<long long> diffs;
    vector<int> size;
    int count;

    struct findST {
        int ancestor;
        long long diff;
    };
public:
    WeightedQuickUnionUF() {
        count = -1;
        id.resize(MAX_N + 1);
        diffs.resize(MAX_N + 1);
        size.resize(MAX_N + 1);
    }

    void clear(int N) {
        count = N;

        for (int i = 0; i <= N; i++) {
            id[i] = i;
            diffs[i] = 0;
            size[i] = 1;
        }
    }

    int getCount() {
        return count;
    }

    int find(int p) {
        if (p == id[p]) return p;

        int parent = find(id[p]);
        diffs[p] += diffs[id[p]];
        id[p] = parent;

        return parent;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    long long getDiffs(int p, int q) {
        return diffs[p] - diffs[q];
    }

    void doUnion(int p, int q, long long w) {
        int i = find(p);
        int j = find(q);

        if (i == j) return;

        if (size[i] < size[j]) {
            id[i] = j;
            diffs[i] = diffs[q] - diffs[p] + w;
            size[i] += size[j];
        }
        else {
            id[j] = i;
            diffs[j] = diffs[p] - diffs[q] - w;
            size[j] += size[i];
        }

        count--;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    WeightedQuickUnionUF* disjointSet = new WeightedQuickUnionUF();

    while (true) {
        string command;
        cin >> command;
         
        if (command == "!") {
            int a, b,  w;
            cin >> a >> b >> w;

            disjointSet->doUnion(a, b, w);
          }
        else if (command == "?") {
            int a, b;
            cin >> a >> b;

            if (disjointSet->isConnected(a, b)) {
                cout << disjointSet->getDiffs(a, b) << "\n";
            }
            else {
                cout << "UNKNOWN" << "\n";
            }
        }
        else if (command == "0") {
            int a;
            cin >> a;
            break;
        }
        else {
            N = stoi(command);
            cin >> M;

            disjointSet->clear(N);
        }
    }

    return 0;
}