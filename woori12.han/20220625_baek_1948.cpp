
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct road
{
	int dest;
	int time;

	road(int d, int dd)
	{
		dest = d;
		time = dd;
	}
};

vector<road>v[10001];
vector<road>reverseV[10001];

int pathCount = 0;
int startCity, endCity;
int nCity, nRoad;

void calcDistance(int* movetime, int* indegree)
{
	queue<int> q;
	q.push(startCity);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nextCity = v[cur][i].dest;
			int nextTime = v[cur][i].time;

			movetime[nextCity] = max(movetime[nextCity], nextTime + movetime[cur]);
			indegree[nextCity]--;

			if (indegree[nextCity] == 0)
			{
				q.push(nextCity);
			}
		}
	}

	int* visited = new int[nCity + 1]{ 0, };
	q.push(endCity);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < reverseV[cur].size(); i++)
		{
			int prevCity = reverseV[cur][i].dest;
			int prevTime = reverseV[cur][i].time;

			if(movetime[cur] - prevTime == movetime[prevCity])
			{
				pathCount++;

				if (visited[prevCity] == 0)
				{
					visited[prevCity] = 1;
					q.push(prevCity);
				}
			}
		}
	}
	delete[] visited;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> nCity >> nRoad;
	
	int* movetime = new int[nCity + 1]{ 0, };
	int* indegree = new int[nCity + 1]{ 0, };

	for (int i = 0; i < nRoad; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;

		v[s].push_back(road(e, d));
		indegree[e]++;
		reverseV[e].push_back(road(s, d));
	}

	cin >> startCity >> endCity;

	calcDistance(movetime, indegree);
	cout << movetime[endCity] << "\n" << pathCount << "\n";

	delete[] indegree;
	delete[] movetime;

	return 0;
}