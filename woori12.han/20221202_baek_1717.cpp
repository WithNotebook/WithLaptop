#include<iostream>
#include<vector>

using namespace std;

int parent[1000001] = { 0, };

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a > b)
	{
		parent[a] = b;
	}
	else
	{
		parent[b] = a;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b, c;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		if (a == 0)
		{
			//합집합
			merge(b, c);
		}
		else
		{
			//b랑 c랑 같은 집합인지 확인?
			if (find(b) == find(c))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
	return 0;
}