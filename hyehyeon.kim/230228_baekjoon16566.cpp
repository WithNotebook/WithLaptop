#include<cmath>
#include<vector>
#include<iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 4000000;

int id[MAX_N + 1];

vector<int> cards;

int find(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]];
        p = id[p];
    }

    return p;
}

void do_union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);

    if (rootP == rootQ) return;

    id[rootQ] = rootP;
}

int upperBound(int target) {
    int lo = 0;
    int hi = cards.size() - 1;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        int cur = find(cards[mid]);

        if (cur <= target) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }

    int ret = find(cards[hi]);
    do_union(cards[hi - 1], cards[hi]);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

    int N, M, K;
    cin >> N >> M >> K;    

    for (int i = 0; i <= MAX_N; i++) {
        id[i] = i;
    }

    cards.push_back(0);

    for (int i = 1; i <= M; i++) {
        int temp;
        cin >> temp;
        cards.push_back(temp);
    }

    sort(cards.begin(), cards.end());

    for (int i = 0; i < K; i++) {
        int cs;
        cin >> cs;

        int ms = upperBound(cs);
        cout << ms << "\n";
    }
    
    return 0;
}