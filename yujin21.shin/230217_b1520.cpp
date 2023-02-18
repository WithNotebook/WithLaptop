#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };;
int M, N;

bool IsVaild(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N)	
		return false;
	
	return true;
}

int DFS(vector<vector<int>>& map, vector<vector<int>>& dp, int x, int y)
{
	if (x == M - 1 && y == N - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsVaild(nx,ny))
		{
			if (map[nx][ny] < map[x][y])
			{
				dp[x][y] = dp[x][y] + DFS(map, dp, nx, ny);
			}
		}
	}
	return dp[x][y];
}

int main() {
	
	cin >> M >> N;
	vector<vector<int>> map(M, vector<int>(N));
	vector<vector<int>> dp(M, vector<int>(N));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	int answer = DFS(map, dp, 0, 0);

	cout << answer;
}