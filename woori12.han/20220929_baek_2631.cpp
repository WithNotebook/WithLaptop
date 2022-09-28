#include <iostream>

using namespace std;

int ary[202] = { 0, };
int dp[202] = { 0, };
int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
		dp[i] = 1;
	}

	int maxDPNum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((ary[i] > ary[j]) && ((dp[j] + 1) > dp[i]))
			{
				dp[i] = dp[j] + 1;
			}
		}
		maxDPNum = max(maxDPNum, dp[i]);
	}

	cout << N - maxDPNum << endl;
	return 0;
}