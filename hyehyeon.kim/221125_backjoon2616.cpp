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

const int MAX_N = 50000;
int accumulated[MAX_N + 1];
int cache[4][MAX_N + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;        
    cin >> N;

    accumulated[0] = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        accumulated[i] = accumulated[i - 1] + cur;
    }

    cin >> M;

    for (int i = 1; i <= 3; i++) {
        for (int j = i * M; j <= N; j++) {
            cache[i][j] = max(cache[i][j - 1], cache[i - 1][j - M] + accumulated[j] - accumulated[j - M]);
        }
    }

    cout << cache[3][N];

    return 0;
};