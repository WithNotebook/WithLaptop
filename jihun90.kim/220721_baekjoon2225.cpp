    #include<stdio.h>

    using namespace std;

    long long _dp[201][201];

    int baekjoon2225()
    {
        int N, K;

        scanf("%d %d", &N, &K);

        for(int n=0; n<=N; n++)
        {
            _dp[1][n] = 1;
        }

        for(int k=2; k<=K; k++)
        {
            long long temp = 0;
            for(int n=0; n<=N; n++)
            {
                temp += _dp[k-1][n];
                _dp[k][n] = temp % 1000000000;
            }
        }


        long long result = _dp[K][N] % 1000000000;

        printf("%lld\n", result);

        return 0;
    }