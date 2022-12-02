#include <iostream>

using namespace std;

int parent[1000001];

int _find(int value)
{
	if (value == parent[value])
	{
		return value;
	}
	return parent[value] = _find(parent[value]);
}

void _union(int a, int b)
{
	int parent_a = _find(a);
	int parent_b = _find(b);

	parent[parent_b] = parent_a;
}

int main()
{
	int N, M = 0;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int x, a, b = 0;
		scanf("%d %d %d", &x, &a, &b);

		if (x == 0)
		{
			_union(a, b);
		}
		else
		{
			if (_find(a) == _find(b))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}
