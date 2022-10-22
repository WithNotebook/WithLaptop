#include<iostream>
#include<algorithm>
#define INF 1e9
using namespace std;

int colorCost[1001][3];
int dp[1001][3];

int main()
{
	//빨강, 파랑, 초록

	int N;
	cin >> N;

	int minSumCost = INF;
	for (int i = 0; i < N; i++)
	{
		cin >> colorCost[i][0] >> colorCost[i][1] >> colorCost[i][2];
	}

	for (int j = 0; j < 3; j++)
	{
		dp[0][0] = INF;
		dp[0][1] = INF;
		dp[0][2] = INF;
		dp[0][j] = colorCost[0][j];

		for (int i = 1; i < N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + colorCost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + colorCost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + colorCost[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == j) continue;
			minSumCost = min(minSumCost, dp[N-1][i]);

		}
	}
	cout << minSumCost << "\n";

	return 0;

}