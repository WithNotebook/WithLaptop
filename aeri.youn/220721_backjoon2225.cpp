#include <iostream>

using namespace std;

/*int result = 0;
void dp(int _n, int _k)
{
	if (_k == 0)
	{
		if (_n == 0)
		{
			result++;
			return;
		}
		return ;
	}
	for (int i = 0; i <= _n; i++)
	{
		dp((_n - i), (_k - 1));
	}
}*/

long long p[201][201];
long long mod = 1000000000;
int main()
{
	int N, T = 0;
	scanf("%d %d", &N, &T);

	//dp(N, T); 
	//printf("%d\n", result);
	for (int i = 0; i <= N; i++)
	{
		p[i][1] = 1;
	}
	for (int i = 1; i <= T; i++)
	{
		p[0][i] = 1;
	}
	for (int i = 1; i <= N; i++) //Че
	{
		for (int j = 2; j <= T; j++) //АЁСўМі
		{
			for (int k = 0; k <= i; k++)
			{
				p[i][j] = p[i][j] + p[i - k][j - 1];
				p[i][j] = p[i][j] % mod;
			}
		}
	}
	printf("%d", (p[N][T]));
	return 0;
}