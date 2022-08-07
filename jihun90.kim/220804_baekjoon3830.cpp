#include <stdio.h>

using namespace std;
#define MAX 100001

int _N;
long long _parents[MAX];
long long _distance[MAX];

void init()
{
	for (int i = 0; i < _N; i++)
	{
		_parents[i] = i;
		_distance[i] = 0;
	}
}

long long find(long long x)
{
	if (x == _parents[x])
	{
		return x;
	}
	else
	{
		long long temp = find(_parents[x]);
		_distance[x] = _distance[x] + _distance[_parents[x]];		
		return  _parents[x] = temp;
	}
}


void unionValue(long long a, long long b, long long value)
{
	//b > a	
	long long parentA = find(a);
	long long parentB = find(b);

	if (parentA != parentB)
	{
		if (_distance[a] >= _distance[b] + value)
		{
			_parents[parentB] = parentA;
			_distance[parentB] = _distance[a] - (_distance[b] + value);
		}
		else
		{
			_parents[parentA] = parentB;
			_distance[parentA] = (_distance[b] + value) - (_distance[a]);
		}
	}
}

int backjoon3830()
{
	int M;
	_N = 0;

	while (true)
	{
		scanf("%d %d", &_N, &M);

		if (_N == 0 && M == 0)
		{
			break;
		}

		_N = _N + 1;
		init();

		char c;
		for (int i = 0; i < M; i++)
		{
			getchar();
			c = getchar();

			if (c == '!')
			{
				long long a, b, w;
				scanf("%lld %lld %lld", &a, &b, &w);
				unionValue(a, b, w);
			}
			else if (c == '?')
			{
				long long a, b;
				scanf("%lld %lld", &a, &b);
				if (find(a) == find(b))
				{
					printf("%lld\n", _distance[a] - _distance[b]);
				}
				else
				{							
					printf("UNKNOWN\n");
				}
			}

		}
	}
	return 0;
}