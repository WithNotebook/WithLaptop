#include <iostream>

using namespace std;


int child[200];
int main()
{
	int N = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		scanf("%d", &temp);

		child[i] = temp;
	}

	int dp[200] = { 0, };

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (child[j] < child[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if ((result == 0) || (result < dp[i]))
		{
			result = dp[i];
		}
	}
	printf("%d", (N - result));
	return 0;
}
