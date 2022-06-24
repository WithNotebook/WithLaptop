
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int nCity, nRoad;

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

void recursive(int start, int prevDistance, int c, vector<road> *v, int* distance, int* count)
{
	int cur = start;
	for (int i = 0; i < v[cur].size(); i++)
	{
		road r = v[cur][i];
		if ((distance[r.dest] > (prevDistance + r.distance)) || (distance[r.dest] == 0))
		{
			distance[r.dest] = prevDistance + r.distance;
			count[r.dest] = c;
		}
		recursive(r.dest, distance[r.dest], c + 1, v, distance, count);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> nCity >> nRoad;

	int* distance = new int[nCity + 1]{ 0, };
	int* count = new int[nCity + 1]{ 0, };
	vector<road> v[10001];
	vector<road> vv[10001];
	for (int i = 0; i < nRoad; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;

		v[s].push_back(road(e, d));
		vv[e].push_back(road(s, d));
	}
	int start, end;
	cin >> start >> end;

	recursive(start, 0, 2, v, distance, count);
	
	/*for (int i = 1; i <= nCity; i++)
	{
		cout << "[" << i << "]" << distance[i] << " " << count[i] << "\n";
	}
	cout << "==============================\n";
	*/
	int* distance2 = new int[nCity + 1]{ 0, };
	int* count2 = new int[nCity + 1]{ 0, };

	recursive(end, 0, 2, vv, distance2, count2);
	/*for (int i = 1; i <= nCity; i++)
	{
		cout << "[" << i << "]" << distance2[i] << " " << count2[i] << "\n";
	}*/

	int maxDistance = 0;
	int totalPathCount = 0;
	for (int i = 1; i <= nCity; i++)
	{
		if (maxDistance < (distance[i] + distance2[i]))
		{
			maxDistance = (distance[i] + distance2[i]);
			totalPathCount = count[i] + count2[i];
		}
	}

	cout << maxDistance << "\n";
	cout << totalPathCount << "\n";

	delete[] distance;
	delete[] count;
	delete[] distance2;
	delete[] count2;
	return 0;
}