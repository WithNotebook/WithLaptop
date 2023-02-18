#include<iostream>

using namespace std;

int dp[501][501] = { 0, };
int map[501][501] = { 0, };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int M, N;

int dfs(int x, int y)
{
	if(x == N-1 && y == M-1)
	{
		return 1;
	}

	if (dp[x][y] == -1)
	{
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (map[nx][ny] != 0 && map[x][y] > map[nx][ny])
			{
				dp[x][y] = dfs(nx, ny);
			}
		}
	}
	return dp[x][y];
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; i < N; j++)
		{
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0,0) << "\n";
	
	return 0;
}