
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int nCity, nRoad;
int maxDistance;

struct road
{
	int dest;
	int distance;

	road(int d, int dd)
	{
		dest = d;
		distance = dd;
	}
};

void calcDistance(int start, vector<road>* v, int* distance)
{
	int* visited = new int[nCity + 1]{ 0, };
	queue<int> q;
	int prevDist = 0;
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		prevDist = distance[cur];

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nextPos = v[cur][i].dest;
			int newDist = v[cur][i].distance;

			distance[nextPos] = max(distance[nextPos], prevDist + newDist);
			maxDistance = max(maxDistance, distance[nextPos]);
			if (visited[nextPos] == 0)
			{
				visited[nextPos] = 1;
				q.push(nextPos);
			}
		}
	}
}

int calcPathCount(int start, int nCity, vector<road>* v, int* distance, int* distance2)
{
	int* visited = new int[nCity + 1] {0, };
	queue<int> q;
	int prevDist = 0;
	int pathCount = 0;

	q.push(start);
	visited[start] = 1;
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		prevDist = distance[cur];

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nextPos = v[cur][i].dest;
			int newDist = prevDist + v[cur][i].distance;
			if ((newDist == distance[nextPos]) &&
				(newDist + distance2[nextPos] == maxDistance))
			{
				pathCount++;
				if (visited[nextPos] == 0)
				{
					visited[nextPos] = 1;
					q.push(nextPos);
				}
			}
		}
	}
	delete[] visited;
	return pathCount;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> nCity >> nRoad;
	
	maxDistance = 0;
	int* distance = new int[nCity + 1]{ 0, };
	int* reverseDistance = new int[nCity + 1]{ 0, };
	vector<road>v[10001];
	vector<road>reverseV[10001];
	
	for (int i = 0; i < nRoad; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;

		v[s].push_back(road(e, d));
		reverseV[e].push_back(road(s, d));
	}

	int start, end;
	cin >> start >> end;

	calcDistance(end, reverseV, reverseDistance);
	calcDistance(start, v, distance);

	int pathCount = calcPathCount(start, nCity, v, distance, reverseDistance);
	
	cout << maxDistance << "\n" << pathCount << "\n";

	delete[] distance;
	delete[] reverseDistance;
	return 0;
}