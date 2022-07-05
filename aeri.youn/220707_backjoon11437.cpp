#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n = 0; //(2 ¡Â n ¡Â 50,000)
int m = 0; //(1 ¡Â m ¡Â 10,000)

int depth[50001];
int parent[50001];

int result_print[10001];

vector<int> map[50001];

void dfs(int current, int distance)
{
	for (auto i = map[current].begin(); i != map[current].end(); i++)
	{
		if ((parent[(*i)] != 0) || ((*i) == 1))
		{
			continue;
		}
		parent[(*i)] = current;
		depth[(*i)] = distance + 1;

		dfs((*i), depth[(*i)]);
	}
}

int backjoon11437()
{
	cin >> n;

	int start, end = 0;
	for (int i = 0; i < n-1; i++)
	{
		cin >> start >> end;

		map[start].push_back(end);
		map[end].push_back(start);
	}
	
	depth[1] = 0;
	parent[1] = 0;
	dfs(1, 0);

	cin >> m;
	start, end = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> start >> end;

		if (depth[start] < depth[end])
		{
			swap(start, end);
		}
		while (depth[start] != depth[end])
		{
			start = parent[start];
		}

		while (start != end)
		{
			start = parent[start];
			end = parent[end];
		}
		result_print[i] = start;
	}
	for (int i = 1; i <= m; i++)
	{
		cout << result_print[i] << endl;
	}

	return 0;
}

