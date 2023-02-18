#include <iostream>

using namespace std;

int M, N;

int map[501][501];
int dp[501][501];
pair<int, int> xy[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

int dfs(int x, int y)
{
	if (dp[x][y] != -1) 
	{
		return dp[x][y];
	}
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int mx = x + xy[i].first;
		int my = y + xy[i].second;

		if ((mx >= 1) && (my >= 1) && (mx <= M) && (my <= N))
		{
			if (map[mx][my] < map[x][y])
			{
				dp[x][y] = dp[x][y] + dfs(mx, my);
			}
		}
	}
	return dp[x][y];
}

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M ; i++)
	{
		for (int j = 1; j <= N ; j++)
		{
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;

			if ((i == M) && (j == N))
			{
				dp[i][j] = 1;
			}
		}
	}
	printf("%d", dfs(1, 1));

	return 0;
}
