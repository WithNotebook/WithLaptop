#include<iostream>

using namespace std;
int dp[16] = { 0, };
int t[16] = { 0, };
int p[16] = { 0, };
int N;
int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = N; i > 0; i--)
	{
		if (i + t[i] > N + 1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
		}
	}

	cout << dp[1] << "\n";

	return 0;
}