#include <iostream>
#include <cmath>

using namespace std;

int train[50001];
int dp[4][50001];

int main()
{
	int num = 0;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> train[i];
		train[i] = train[i] + train[i-1];
	}
	int length = 0;
	cin >> length;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = (i * length); j <= num; j++)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - length] + (train[j] - train[j - length]));
		}
	}
	cout << dp[3][num];

	return 0;
}

