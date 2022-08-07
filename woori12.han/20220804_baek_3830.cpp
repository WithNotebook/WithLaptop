#include<iostream>
#include<cstring>

using namespace std;

long long dist[100001];
int parent[100001];

int findParent(int x)
{
	if (parent[x] == -1)
	{
		return x;
	}
	else
	{
		int p = findParent(parent[x]);
		dist[x] += dist[parent[x]];
		return parent[x] = p;
	}
}

void union1(int x, int y, int weight)
{
	int nx = findParent(x);
	int ny = findParent(y);

	if (nx == ny) return;

	dist[ny] = dist[x] - dist[y] + weight;

	parent[ny] = nx;
}

int main()
{
	int N, M;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> N >> M;

		if (N == 0 && M == 0) return 0;

		int s, e, d;
		char a;

		memset(parent, -1, sizeof(parent));
		memset(dist, 0, sizeof(dist));


		for (int i = 0; i < M; i++)
		{
			cin >> a;

			if (a == '!')
			{
				cin >> s >> e >> d;
				union1(s, e, d);
			}
			else
			{
				cin >> s >> e;
				if (findParent(s) != findParent(e))
				{
					cout << "UNKNOWN\n";
				}
				else
				{
					cout << dist[e] - dist[s] << "\n";
				}
			}
		}
	}

	return 0;
}