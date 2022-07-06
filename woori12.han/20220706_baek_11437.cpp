#include <iostream>
#include <vector>
#include <math.h>
#define MAX_NODE 100001
using namespace std;

vector<int> graph[MAX_NODE];
int depth[MAX_NODE];
int ac[MAX_NODE][21];
int max_depth = 0;

void getTree(int current, int parent)
{
	depth[current] = depth[parent] + 1;
	ac[current][0] = parent;

	max_depth = (int)floor(log2(MAX_NODE));

	for (int i = 1; i <= max_depth; i++)
	{
		int tmpParentNode = ac[current][i - 1];
		ac[current][i] = ac[tmpParentNode][i - 1];
	}

	int len = graph[current].size();
	for (int i = 0; i < len; i++)
	{
		int there = graph[current][i];
		if (there != parent)
		{
			getTree(there, current);
		}
	}
}

int getLCA(int a, int b)
{
	if (depth[a] != depth[b])
	{
		if (depth[a] > depth[b])
		{
			swap(a, b);
		}
		//작은 depth까지 끌어올린다

		for (int i = max_depth; i >= 0; i--)
		{
			if (depth[a] <= depth[ac[b][i]])
			{
				b = ac[b][i];
			}
		}
	}

	//다 끌어올렸으면 공통 조상 찾는다
	if (a == b)
	{
		return a;
	}

	for (int i = max_depth; i >= 0; i--)
	{
		if (ac[a][i] != ac[b][i])
		{
			a = ac[a][i];
			b = ac[b][i];
		}
	}
	return ac[a][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	depth[0] = -1;

	for (int i = 0; i < (n - 1); i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	getTree(1, 0);

	int m, a, b;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		int lca = getLCA(a, b);
		cout << lca << "\n";
	}

	return 0;
}