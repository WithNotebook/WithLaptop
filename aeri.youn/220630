#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n = 0; //(1 ≤ n ≤ 10,000)
int m = 0; //(1 ≤ m ≤ 100,000)

struct point
{
	int endpoint;
	int distance;
};

vector<point> list[10001];
vector<point> reverselist[10001];
int maxvalue[10001];
int checked[10001];

void bfs(int startpoint, int endpoint)
{
	queue<point> q;

	q.push(point{ startpoint, 0 });
	while (!q.empty())
	{
		int current = q.front().endpoint;
		q.pop();

		for (auto i = list[current].begin(); i != list[current].end(); i++)
		{
			int temp = maxvalue[current] + (*i).distance;
			if (temp > maxvalue[(*i).endpoint])
			{
				maxvalue[(*i).endpoint] = temp;
				if (endpoint != (*i).endpoint)
				{
					q.push((*i));
				}
			}
		}
	}
	cout << maxvalue[endpoint] << endl;

	int result = 0;
	q.push(point{ endpoint, 0 });
	while (!q.empty())
	{
		int current = q.front().endpoint;
		q.pop();

		int max = maxvalue[current];
		for (auto i = reverselist[current].begin(); i != reverselist[current].end(); i++)
		{
			int temp = max - (*i).distance;
			if (temp == maxvalue[(*i).endpoint])
			{
				if (checked[(*i).endpoint] == 1)
				{
					result++;
					continue;
				}
				if (startpoint != (*i).endpoint)
				{
					q.push((*i));
				}
				checked[(*i).endpoint] = 1;
				result++;
			}
		}
	}
	cout << result << endl;
}

int main()
{
	cin >> n >> m;

	int startpoint, endpoint, distance = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> startpoint >> endpoint >> distance;
		list[startpoint].push_back(point{ endpoint, distance });
		reverselist[endpoint].push_back(point{ startpoint, distance });
	}
	cin >> startpoint >> endpoint;

	bfs(startpoint, endpoint);
	
	return 0;
}

