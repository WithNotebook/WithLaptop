#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//우수마을을 선정하는데, 마을주민 수가 최대가 되어야함.
//우수 마을끼리는 인접할 수 없음.
int N;
int peopleNum[10001] = { 0, };
vector<int> map[10001];
int dp[10001][2];
int visited[10001] = { 0, };
void dfs(int cur)
{
	dp[cur][0] = 0;
	dp[cur][1] = peopleNum[cur];
	visited[cur] = 1;

	for (int i = 0; i < map[cur].size(); i++)
	{
		int next = map[cur][i];
		if (visited[next]) continue;
		dfs(next);
		dp[cur][0] += max(dp[next][0], dp[next][1]);
		dp[cur][1] += dp[next][0];
	}
}

int main()
{
	cin >> N;

	
	for(int i = 1; i <= N; i++)
	{
		cin >> peopleNum[i];
	}

	int s, e;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N - 1; i++)
	{
		cin >> s >> e;
		map[s].push_back(e);
		map[e].push_back(s);
	}

	dfs(1);

	int res = max(dp[1][0], dp[1][1]);
	cout << res << "\n";

	return 0;
}