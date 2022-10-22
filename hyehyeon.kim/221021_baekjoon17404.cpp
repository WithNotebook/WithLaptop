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

const int MAX_N = 1000;

const int RED = 0;
const int GREEN = 1;
const int BLUE = 2;

int houses[MAX_N + 2][3];
int cache[MAX_N + 2][3][3];

int N;

int findNMin(int prevColor, int zeroColor) {
    if (prevColor == RED) {
        if (zeroColor == RED) return min(houses[N][GREEN], houses[N][BLUE]);
        else if (zeroColor == BLUE) return houses[N][GREEN];
        else return houses[N][BLUE];
    }
    else if (prevColor == GREEN) {
        if (zeroColor == GREEN) return min(houses[N][RED], houses[N][BLUE]);
        else if (zeroColor == BLUE) return houses[N][RED];
        else return houses[N][BLUE];
    }
    else {
        if (zeroColor == BLUE) return min(houses[N][RED], houses[N][GREEN]);
        else if (zeroColor == GREEN) return houses[N][RED];
        else return houses[N][GREEN];
    }
}

int findMinCost(int cur, int prevColor, int zeroColor) {
    if (cur == N) return findNMin(prevColor, zeroColor);

    if (cur == 1) {
        int result = INT32_MAX;

        for (int i = 0; i < 3; i++) {
            result = min(result, houses[cur][i] + findMinCost(cur + 1, i, i));
        }

        return result;
    }
    else {
        int& ret = cache[cur][prevColor][zeroColor];

        if (ret != -1) return ret;

        int result = INT32_MAX;

        for (int i = 0; i < 3; i++) {
            if (i == prevColor) continue;

            result = min(result, houses[cur][i] + findMinCost(cur + 1, i, zeroColor));
        }

        return (ret = result);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    memset(cache, -1, sizeof(cache));

    for (int i = 1; i <= N; i++) {
        cin >> houses[i][0];
        cin >> houses[i][1];
        cin >> houses[i][2];
    }

    for (int i = 0; i < 3; i++) {
        houses[0][i] = houses[N][i];
        houses[N + 1][i] = houses[1][i];
    }

    int result = findMinCost(1, -1, -1);

    cout << result;

    return 0;
}