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
const int INF = 10000000;

struct Load {
    int end;
    int time;
};

int adjMaxtrix[MAX_N + 1][MAX_N + 1];

void floydWarshall(int N) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adjMaxtrix[i][j] <= adjMaxtrix[i][k] + adjMaxtrix[k][j]) continue;

                adjMaxtrix[i][j] = adjMaxtrix[i][k] + adjMaxtrix[k][j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, X;
    cin >> N >> M >> X;

    fill(&adjMaxtrix[0][0], &adjMaxtrix[MAX_N][MAX_N], INF);

    for (int i = 0; i < M; i++) {
        int start, end, time;
        cin >> start >> end >> time;

        adjMaxtrix[start][end] = time;
    }

    floydWarshall(N);
    
    int result = 0;

    for (int i = 1; i <= N; i++) {
        if (i == X) continue;

        int temp = adjMaxtrix[i][X] + adjMaxtrix[X][i];

        if (temp > result) {
            result = temp;
        }
    }

    cout << result;

    return 0;
}