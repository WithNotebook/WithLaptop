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
#include <string>

using namespace std;

const int MAX_N = 500;
const int MAX_M = 500;
const int MAX_Height = 10000;

const int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int room[MAX_N + 1][MAX_M + 1];
int cache[MAX_N + 1][MAX_M + 1];

int N, M;

int calculate(int row, int col) {
    if (row == N && col == M) {
        return 1;
    }

    int& ret = cache[row][col];

    if (ret != -1) return ret;

    int result = 0;

    for (int i = 0; i < 4; i++) {
        int nextX = row + directions[i][0];
        int nextY = col + directions[i][1];

        if (nextX < 1 || nextX > N || nextY < 1 || nextY > M) continue;
        if (room[row][col] <= room[nextX][nextY]) continue;

        result += calculate(nextX, nextY);
    }

    return ret = result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(cache[0], cache[0] + (MAX_N + 1) * (MAX_M + 1), -1);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> room[i][j];
        }
    }

    cout << calculate(1, 1);

    return 0;
}