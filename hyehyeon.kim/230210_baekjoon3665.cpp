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
#include <stack>

using namespace std;

const int MAX_N = 500;

int lastYears[MAX_N + 1];
int lastYearOrders[MAX_N + 1];
int indegrees[MAX_N + 1];

vector<int> adjList[MAX_N + 1];
queue<int> tempQueue;
vector<int> topologicalOrder;
vector<int> printOrder;

int orderMatrix[MAX_N + 1][MAX_N + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++) {
        fill_n(lastYears, MAX_N + 1, 0);
        fill_n(lastYearOrders, MAX_N + 1, 0);
        fill_n(indegrees, MAX_N + 1, 0);
        fill(orderMatrix[0], orderMatrix[0] + (MAX_N + 1) * (MAX_N + 1), 0);

        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> lastYearOrders[i];
            lastYears[lastYearOrders[i]] = i;

            adjList[i].clear();
        }

        int M;
        cin >> M;

        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;

            if (lastYears[a] < lastYears[b]) {
                orderMatrix[a][b] = 1;
                orderMatrix[b][a] = -1;
            }
            else {
                orderMatrix[a][b] = -1;
                orderMatrix[b][a] = 1;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (orderMatrix[i][j] == 1) {
                    indegrees[j]++;
                    adjList[i].push_back(j);
                }
                else if (orderMatrix[i][j] == -1) {
                    indegrees[i]++;
                    adjList[j].push_back(i);
                }
                else {
                    if (lastYears[i] < lastYears[j]) {
                        indegrees[i]++;
                        adjList[j].push_back(i);
                    }
                    else {
                        indegrees[j]++;
                        adjList[i].push_back(j);
                    }
                }
            }
        }

        topologicalOrder.clear();

        while (!tempQueue.empty()) {
            tempQueue.pop();
        }

        for (int i = 1; i <= N; i++) {
            if (indegrees[i] == 0) {
                tempQueue.push(i);
            }
        }

        while (!tempQueue.empty()) {
            int cur = tempQueue.front();
            tempQueue.pop();

            topologicalOrder.push_back(cur);

            for (auto it = adjList[cur].begin(); it != adjList[cur].end(); it++) {
                int next = (*it);
                indegrees[next]--;

                if (indegrees[next] == 0) {
                    tempQueue.push(next);
                }
            }
        }

        /*if (isCycle == 0) {
            cout << "IMPOSSIBLE" << "\n";
        }*/
        if (topologicalOrder.size() < N) {
            cout << "IMPOSSIBLE";
        }
        else {
            for (int i = topologicalOrder.size() - 1; i >= 0; i--) {
                cout << topologicalOrder[i];

                if (i != 0) {
                    cout << " ";
                }
            }
        }

        cout << "\n";
    }

    return 0;
}