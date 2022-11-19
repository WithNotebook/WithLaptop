#define MAX 3001

#include <iostream>
#include<set>
#include<map>
#include<queue>

using namespace std;

int N;
multimap<int, int> mm;
set<int> cycleStation;

int distFromCycle[MAX];
int visited[MAX];
int preStation[MAX];

bool cycle = false;
int startNode, destNode;

void findStartEndOfCycle(int start, int order)
{
    visited[start] = order;

    if (cycle == true) return;

    for (auto a = mm.lower_bound(start); a != mm.upper_bound(start); a++)
    {
        int next = a->second;

        if (visited[next] == 0)
        {
            findStartEndOfCycle(next, order + 1);
            preStation[next] = start;
        }
        else
        {
            if (visited[next] != (order - 1))
            {
                startNode = start;
                destNode = next;
                cycle = true;
                return;
            }
        }
    }
}

void findAllStationInCycle()
{
    int curNode = destNode;
    while (curNode != startNode)
    {
        cycleStation.insert(curNode);
        curNode = preStation[curNode];
    }
    cycleStation.insert(startNode);
}

void findAllDistanceFromCycle()
{
    queue<pair<int, int>> q;
    for (auto a = cycleStation.begin(); a != cycleStation.end(); a++)
    {
        int cycleStation = *a;
        visited[cycleStation] = 1;
        q.push({ cycleStation, 0 });
    }

    while (!q.empty())
    {
        int cur = q.front().first;
        int curDist = q.front().second;
        q.pop();
        for (auto b = mm.lower_bound(cur); b != mm.upper_bound(cur); b++)
        {
            int next = b->second;

            if (visited[next] == 0)
            {
                distFromCycle[next] = curDist + 1;
                visited[next] = 1;
                q.push({ next, curDist + 1 });
            }
        }
    }
}

int main()
{
    cin >> N;
    int s, d, maxRoadStation = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> s >> d;

        mm.insert(pair<int, int>(s, d));
        mm.insert(pair<int, int>(d, s));
    }

    fill(visited, visited + MAX, 0);
    findStartEndOfCycle(1, 1); //find start and end of cycle
    findAllStationInCycle(); //find all station in cycle

    fill(distFromCycle, distFromCycle + 3001, 0);
    fill(visited, visited + MAX, 0);
    findAllDistanceFromCycle();//find distance from cycle for all stations

    for (int i = 1; i <= N; i++)
    {
        cout << distFromCycle[i] << " ";
    }

    cout << "\n";
    return 0;
}