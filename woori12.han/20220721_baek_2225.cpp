#include <iostream>

using namespace std;

int N, K;
int dp[202][202] = { 0, };
int mod = 1000000000;
int main()
{
	cin >> N >> K;

	dp[0][0] = 1;
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int t = 0; t <= j; t++)
			{
				dp[i][j] += dp[i - 1][j - t];
				dp[i][j] %= mod;
			}
		}
	}

	cout << dp[K][N] << endl;

	return 0;
}