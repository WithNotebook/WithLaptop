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
#include <list>
#include <string>

using namespace std;

const int MAX_N = 50;
const int MAX_M = 50;

const int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int boards[MAX_N + 1][MAX_M + 1];
int twelves[MAX_N + 1];
bool visited[MAX_N + 1][MAX_M];

int N, M, T;
int totalDeletedNum = 0;

int inRangeJ(int num) {
    if (num <= 0) return num + M;
    if (num > M) return num - M;
    return num;
}

int inRangeC(int num) {
    if (num < 0) return num + M;
    if (num >= M) return num - M;
    return num;
}

void printBoards(string statement) {
    /*if (statement != "") cout << statement << "\n";

    for (int i = 1; i <= N; i++) {
        for (int c = 0; c < M; c++) {
            int j = inRangeJ(twelves[i] + c);
            cout << boards[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";*/
}

void clockwise(int pivotNum, int count) {
    int i = 1;

    while (pivotNum * i <= N) {
        int cur = pivotNum * i;
        twelves[cur] = inRangeJ(twelves[cur] - count);
        i++;
    }
}

void counterClockwise(int pivotNum, int count) {
    int i = 1;

    while (pivotNum * i <= N) {
        int cur = pivotNum * i;
        twelves[cur] = inRangeJ(twelves[cur] + count);
        i++;
    }
}

bool hasAnyAdjacentSameNumber(int i, int c) {
    bool hasSameNumber = false;
    int j = inRangeJ(twelves[i] + c);
    int num = boards[i][j];

    for (int k = 0; k < 4; k++) {
        int curI = i + directions[k][0];
        int curC = inRangeC(twelves[curI] + c);
        int curJ = inRangeJ(curC + directions[k][1]);

        if (curI <= 0 || curI > N || curJ <= 0 || curJ > M) continue;

        if (num == boards[curI][curJ]) {
            hasSameNumber = true;
        }
    }

    return hasSameNumber;
}

bool IsDeleted(int i, int c) {
    int j = inRangeJ(twelves[i] + c);

    return (boards[i][j] == 0);
}

void bfsSearch(int i, int c) {
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(i, c));    
    visited[i][c] = true;
    int j = inRangeJ(twelves[i] + c);
    int num = boards[i][j];

    while (!bfsQueue.empty()) {
        pair<int, int> cur = bfsQueue.front();
        bfsQueue.pop();

        int curJ = inRangeJ(twelves[cur.first] + cur.second);

        boards[cur.first][curJ] = 0;
        totalDeletedNum++;

        for (int k = 0; k < 4; k++) {
            int nextI = cur.first + directions[k][0];
            int nextC = inRangeC(cur.second + directions[k][1]);
            int nextJ = inRangeJ(twelves[nextI] + nextC);

            if (nextI <= 0 || nextI > N || nextJ <= 0 || nextJ > M) continue;
            if (boards[nextI][nextJ] == 0) continue;
            if (boards[nextI][nextJ] != num) continue;
            if (visited[nextI][nextC]) continue;

            bfsQueue.push(make_pair(nextI, nextC));
            visited[nextI][nextC] = true;
        }
    }
}

void doRound() {
    if (totalDeletedNum == M * N) return;

    fill(visited[0], visited[0] + (MAX_N + 1) * MAX_M, false);

    bool isDeleted = false;

    printBoards("Do Round..");

    for (int i = 1; i <= N; i++) {
        for (int c = 0; c < M; c++) {
            if (IsDeleted(i, c)) continue;
            if (!hasAnyAdjacentSameNumber(i, c)) continue;

            bfsSearch(i, c);
            isDeleted = true;

            printBoards("");
        }
    }

    if (isDeleted) return;

    double sum = 0;
    double totalCount = 0;
    double avg = 0;

    for (int i = 1; i <= N; i++) {                
        for (int j = 1; j <= M; j++) {
            if (boards[i][j] == 0) continue;

            sum += boards[i][j];
            totalCount++;
        }

        avg = sum / totalCount;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (boards[i][j] == 0) continue;

            if (boards[i][j] > avg) {
                boards[i][j] -= 1;
            }
            else if (boards[i][j] < avg) {
                boards[i][j] += 1;
            }
        }
    }

    printBoards("Revised with " + to_string(avg));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> boards[i][j];
        }

        twelves[i] = 1;
    }

    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k;

        if (d == 0) {
            clockwise(x, k);
        }
        else if (d == 1) {
            counterClockwise(x, k);
        }

        doRound();
    }

    int sum = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            sum += boards[i][j];
        }
    }

    cout << sum;

    return 0;
}