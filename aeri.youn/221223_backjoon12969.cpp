#include <iostream>

using namespace std;

int N, K = 0; //3 ≤ N ≤ 30, 0 ≤ K ≤ N(N-1)/2)
const int MAX_N = 30;
const int MAX_K = (MAX_N *(MAX_N -1))/2;

bool dp[MAX_N + 1][MAX_N + 1][MAX_N + 1][MAX_K];
char answer[MAX_N + 1];

void solve(int index, int i, int j, int pair)
{
	if ((index == N) && (pair == K))
	{
		printf("%s\n", &answer);
		exit(0);
	}
	if (index == N)
	{
		return;
	}
	if (dp[index][i][j][pair])
	{
		return;
	}

	dp[index][i][j][pair] = true;

	answer[index] = 'A';
	solve((index + 1), (i + 1), j, pair);

	answer[index] = 'B';
	solve((index + 1), i, (j + 1), (pair + i));

	answer[index] = 'C';
	solve((index + 1), i, j, (pair + i + j));
}

int main()
{
	scanf("%d %d", &N, &K);

	solve(0, 0, 0, 0);
	printf("-1\n");
	
	return 0;
}
