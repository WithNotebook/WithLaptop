#include <iostream>
#include <cstring>

using namespace std;

int const MAX = 100001;

long long parent[MAX];
long long weight[MAX];

long long _find(long long a)
{
	if (parent[a] == a)
	{
		return a;
	}
	long long temp = _find(parent[a]);
	weight[a] = weight[a] + weight[parent[a]];
	return  parent[a] = temp;

	//weight[a] = weight[a] + weight[parent[a]];
	//return parent[a] = _find(parent[a]);
}

void _union(long long a, long long b, long long w)
{
	long long parent_a = _find(a);
	long long parent_b = _find(b);

	if (parent_a == parent_b)
	{
		return;
	}

	if (weight[a] < weight[b])
	{
		parent[parent_b] = parent_a;
		weight[parent_b] = weight[a] - weight[b] + w;
	}
	else
	{
		parent[parent_a] = parent_b;
		weight[parent_a] = weight[b] - weight[a] - w;
	}
}

int main()
{
	while (true)
	{
		int N, M = 0;
		scanf("%d %d", &N, &M);

		if ((N == 0) && (M == 0))
		{
			break;
		}

		for (int i = 1; i <= N; i++)
		{
			parent[i] = i;
			weight[i] = 0;
		}

		for (int i = 0; i < M; i++)
		{
			char state;
			getchar();
			scanf("%c", &state);

			if (state == '!')
			{
				long long a, b, w;
				scanf("%lld %lld %lld", &a, &b, &w);

				_union(a, b, w);
			}
			else if (state == '?')
			{
				long long a, b;
				scanf("%lld %lld", &a, &b);

				long long parent_a = _find(a);
				long long parent_b = _find(b);

				if (parent_a != parent_b)
				{
					printf("UNKNOWN\n");
				}
				else
				{
					printf("%lld\n", (weight[b] - weight[a]));
				}
			}
		}
	}
	return 0;
}