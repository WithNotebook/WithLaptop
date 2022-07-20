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

const int DENOMINATION = 1000000000;

const int MAX_N = 200;
const int MAX_K = 200;

int cache[MAX_N + 1][MAX_K + 1];

int calculate(int N, int K) {
    if (K == 1) return 1;

    int& ret = cache[N][K];

    if (ret != -1) {
        return ret;
    }

    int result = 0;

    for (int i = 0; i <= N; i++) {
        result += calculate(N - i, K - 1);
        result %= DENOMINATION;
    }

    return (ret = result);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    memset(cache, -1, sizeof(cache));

    cout << calculate(N, K);

    return 0;
}