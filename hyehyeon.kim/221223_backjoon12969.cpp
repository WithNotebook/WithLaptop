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

using namespace std;

const int MAX_N = 30;
const int MAX_SCORE = 15 * 29;

string result = "-1";
int N, K;

bool visited[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_SCORE];

void calculate(string cur, int A, int B, int C, int score) {    
    if (cur.size() == N) {
        if (score == K) {
            result = cur;
        }

        visited[cur.size()][A][B][C][score] = true;
            
        return;
    }

    if (result != "-1") return;
    if (visited[cur.size()][A][B][C][score]) return;

    visited[cur.size()][A][B][C][score] = true;

    calculate(cur + "A", A + 1, B, C, score);
    calculate(cur + "B", A, B + 1, C, score + A);
    calculate(cur + "C", A, B, C + 1, score + A + B);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
      
    cin >> N >> K;

    calculate("", 0, 0, 0, 0);

    cout << result;

    return 0;
}