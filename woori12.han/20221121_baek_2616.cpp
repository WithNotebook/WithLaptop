#include<iostream>
#include<algorithm>

using namespace std;
int input[50001] = { 0, };
int dp[4][50001] = { 0, };
int main()
{

	int N;
	cin >> N;

	int a;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		input[i] = input[i - 1] + a;
	}

	int numOfCars;
	cin >> numOfCars;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = i * numOfCars; j <= N; j++)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - numOfCars] + input[j] - input[j - numOfCars]);
		}
	}

	cout << dp[3][N] << "\n";
	return 0;
}