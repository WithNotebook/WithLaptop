/**** 1238 파티*/

#define PEOPLE_NUM 1001
#define INF 1e9
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[1001];
vector<pair<int, int>> reverseV[1001];
int dist[PEOPLE_NUM] = { 0, };
int reverseDist[PEOPLE_NUM] = { 0, };

void dijkstra(int start, vector<pair<int, int>> *graph, int* distAry)
{
    priority_queue<pair<int, int>> pq;

    distAry[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int nowDist = -pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (distAry[nowNode] < nowDist) continue;

        for (int i = 0; i < graph[nowNode].size(); i++)
        {
            int newNode = graph[nowNode][i].first;
            int newDist = nowDist + graph[nowNode][i].second;

            if (newDist < distAry[newNode])
            {
                distAry[newNode] = newDist;
                pq.push({ -newDist , newNode });
            }
        }
    }
}

int main()
{
    int N, M, X; // N명, x마을에서 모임, m개의 도로
    fill(dist, dist + PEOPLE_NUM, INF);
    fill(reverseDist, reverseDist + PEOPLE_NUM, INF);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({ b, c });
        reverseV[b].push_back({ a, c });
        
    }

    dijkstra(X, v, dist);
    dijkstra(X, reverseV, reverseDist);

    int maxNum = 0;
    int newValue = 0;
    for (int i = 1; i <= N; i++)
    {
        newValue = dist[i] + reverseDist[i];
        maxNum = max(maxNum, newValue);
    }

    cout << maxNum << "\n";
    return 0;
}
