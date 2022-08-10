#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int const MAX = 101;

int parent[MAX];
int depth[MAX];

int _find(int a)
{
	if (parent[a] == a)
	{
		return a;
	}
	return  parent[a] = _find(parent[a]);
}

void _union(int a, int b)
{
	int parent_a = _find(a);
	int parent_b = _find(b);

	if (parent_a == parent_b)
	{
		return;
	}

	if (depth[parent_a] > depth[parent_b])
	{
		parent[parent_b] = parent_a;
	}
	else
	{
		parent[parent_a] = parent_b;
		if (depth[parent_a] == depth[parent_b])
		{
			depth[parent_b]++;
		}
	}
}

bool checked[MAX];
vector<int> map[MAX];

int _bfs(int start)
{
	queue<pair<int, int>> q;

	int depth = 0;
	q.push({ start, 0 });
	checked[start] = true;

	while (!q.empty())
	{
		pair<int, int> current = q.front();
		q.pop();
		depth = current.second;

		for (auto i = map[current.first].begin(); i != map[current.first].end(); i++)
		{
			if (!checked[(*i)])
			{
				checked[(*i)] = true;
				q.push({ (*i), (current.second + 1) });
			}
		}
	}
	return depth;
}

int main()
{
	int N, M = 0;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		depth[i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		_union(a, b);

		map[a].push_back(b);
		map[b].push_back(a);
	}

	pair<int, int> list_answer[MAX];
	for (int i = 1; i <= N; i++)
	{
		memset(checked, false, sizeof(checked));
		int find = _find(i);
		int bfs = _bfs(i);

		if ((list_answer[find].first == 0) || (list_answer[find].second > bfs))
		{
			list_answer[find].first = i;
			list_answer[find].second = bfs;
		}
	}
	vector<int> list;
	for (int i = 1; i <= N; i++)
	{
		if (list_answer[i].first != 0)
		{
			list.push_back(list_answer[i].first);
		}
	}
	printf("%d\n", list.size());
	for (auto i = list.begin(); i < list.end(); i++)
	{
		printf("%d\n", (*i));
	}
	return 0;
}