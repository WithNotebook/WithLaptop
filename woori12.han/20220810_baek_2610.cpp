#include <iostream>

using namespace std;

int N, M;
int parent[101];

int find(int n)
{
	if (parent[n] == n)
	{
		return n;
	}

	return parent[n] = find(parent[n]);
}

void merge(int a, int b)
{
	int parentA = find(a);
	int parentB = find(b);

	//if (parentA == parentB) return;

	if (a < b)
	{
		if (parentA != a) //부모가 있다면
		{
			parent[parentA] = a;
			parent[a] = a;
			parent[b] = a;
		}
		else
		{
			parent[b] = a;
		}
	}
	else
	{
		if (parentB != b) //부모가 있다면
		{
			parent[parentB] = b;
			parent[a] = b;
			parent[b] = b;
		}
		else
		{
			parent[a] = b;
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	return 0;
}