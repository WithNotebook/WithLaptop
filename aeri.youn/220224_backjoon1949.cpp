#include <iostream>
#include <vector>

using namespace std;

int N;
int num[10001];

int dp[10001][2];
bool visited[10001];
vector<int> tree[10001];

int dfs(int current)
{
	visited[current] = true;
	dp[current][0] = 0;
	dp[current][1] = num[current];

	for (int i = 0; i < tree[current].size(); i++)
	{
		int next = tree[current][i];
		if (visited[next])
		{
			continue;
		}
		dfs(next);

		dp[current][0] = dp[current][0] + max(dp[next][0], dp[next][1]);
		dp[current][1] = dp[current][1] + dp[next][0];
	}
	return max(dp[current][0], dp[current][1]);
}

int main()
{
	scanf("%d",&N);

	for (int i = 1; i <= N ; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 1; i <= (N-1); i++)
	{
		int a, b = 0;
		scanf("%d %d", &a, &b);

		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	printf("%d", dfs(1));

	return 0;
}
