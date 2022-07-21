#include <iostream>

const int MOD_NUM = 1000000000;
const int MAX = 200;

using namespace std;

long long  DP[MAX + 1][MAX + 1];

int N, K;

void Solve()
{
    for (int i = 0; i <= N; i++)
    {
        DP[0][i] = 0;
        DP[1][i] = 1;
    }

    for (int i = 2; i <= K; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                DP[i][j] += DP[i - 1][k];
            }
            DP[i][j] = DP[i][j] % MOD_NUM;
        }
    }
}

int 2225()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    Solve();

    cout << DP[K][N] << '\n';

    return 0;
}

