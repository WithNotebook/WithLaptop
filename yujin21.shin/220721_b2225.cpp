#include <stdio.h>

using namespace std;


int main()
{

	int N, K;

	scanf("%d %d", &N, &K);
	
	int dp[201][201] = { 0, };

	for (int i = 0; i <= N; i++)
	{
		dp[1][i] = 1;
	}

	for (int k = 1; k <= K; k++) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				dp[k][i] += dp[k - 1][i-j];
				dp[k][i] %=  1000000000;
			}
		}
	}

	printf("%d", dp[K][N]);
}