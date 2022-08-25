#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<vector<pair<long long, int>>> map;

int parent[1001];
long long cost[1001];

void _bfs(int start, int end)
{
	int result_cost = 0;
	int result_count = 0;

	memset(parent, 0, sizeof(parent));
	memset(cost, -1, sizeof(cost));

	queue<pair<int, pair<long long, int>>> list;
	list.push({ start, {0, 1} });

	while (!list.empty())
	{
		pair<int, pair<long long, int>> temp = list.front();
		list.pop();

		if (temp.first == end)
		{
			if ((result_cost == 0) || (result_cost > temp.second.first))
			{
				result_cost = temp.second.first;
				result_count = temp.second.second;
			}
			continue;
		}
		if ((result_cost != 0) && (result_cost < temp.second.first))
		{
			continue;
		}

		for (auto i = map[temp.first].begin(); i < map[temp.first].end(); i++)
		{
			if (((cost[(*i).second]) == -1) || (cost[(*i).second] > ((*i).first + temp.second.first)))
			{
				cost[(*i).second] = ((*i).first + temp.second.first);
				parent[(*i).second] = temp.first;

				list.push({ (*i).second, {((*i).first + temp.second.first), (temp.second.second + 1)} });
			}
		}
	}

	vector<int> result;
	int current = end;
	result.push_back(current);
	while (current != start)
	{
		current = parent[current];
		result.push_back(current);
	}

	cout << cost[end] << endl;
	cout << result.size() << endl;
	for (auto i = result.rbegin(); i < result.rend(); i++)
	{
		cout << (*i) << " ";
	}
}

int main()
{
	int n = 0; // 1<=n<=1000
	cin >> n;

	int m = 0; // 1<=m<=100000
	cin >> m;

	map.resize(m + 1);
	for (int i = 0; i < m; i++)
	{
		int start, end;
		long long cost;
		cin >> start >> end >> cost;

		map[start].push_back({ cost, end });
	}

	for (int i = 1; i < (m + 1); i++)
	{
		sort(map[i].begin(), map[i].end());
	}

	int start, end;
	cin >> start >> end;
	_bfs(start, end);

	return 0;
}