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
#include <stack>

using namespace std;

const int MAX_R = 1000;
const int MAX_C = 1000;

const int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;

char boards[MAX_R][MAX_C];
bool visited[MAX_R][MAX_C];

queue<pair<int, int>> fires;
queue<pair<int, int>> temp;

struct jihun {
    int r;
    int c;
    int time;
};

int calculate(int startR, int startC) {
    fill(visited[0], visited[0] + MAX_R * MAX_C, false);
    queue<jihun> bfsQueue;
    bfsQueue.push(jihun{ startR, startC, 0 });
    visited[startR][startC] = true;

    int time = 1;

    while (!bfsQueue.empty()) {
        jihun cur = bfsQueue.front();
        bfsQueue.pop();

        if (cur.time + 1 == time) {
            while (!temp.empty()) temp.pop();
            while (!fires.empty()) {
                pair<int, int> curFire = fires.front();
                fires.pop();

                for (int i = 0; i < 4; i++) {
                    int nextR = curFire.first + directions[i][0];
                    int nextC = curFire.second + directions[i][1];

                    if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
                    if (boards[nextR][nextC] == '#') continue;
                    if (boards[nextR][nextC] == 'F') continue;

                    boards[nextR][nextC] = 'F';
                    temp.push(make_pair(nextR, nextC));
                }
            }
            
            while (!temp.empty()) {
                pair<int, int> curFire = temp.front();
                temp.pop();
                fires.push(curFire);
            }
            
            time++;
        }

        for (int i = 0; i < 4; i++) {
            int nextR = cur.r + directions[i][0];
            int nextC = cur.c + directions[i][1];

            if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) return cur.time + 1;
            if (visited[nextR][nextC]) continue;
            if (boards[nextR][nextC] == '#') continue;
            if (boards[nextR][nextC] == 'F') continue;

            bfsQueue.push(jihun{ nextR, nextC, cur.time + 1 });
            visited[nextR][nextC] = true;
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

    cin >> R >> C;

    int startR, startC;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> boards[r][c];

            if (boards[r][c] == 'J') {
                startR = r;
                startC = c;
            }
            else if (boards[r][c] == 'F') {
                fires.push(make_pair(r, c));
            }
        }
    }

    int ret = calculate(startR, startC);

    if (ret == -1) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << ret;
    }

    return 0;
}