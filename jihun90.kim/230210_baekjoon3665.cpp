#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
	int testCase;
	scanf("%d", &testCase);

	for (int testCaseInex = 1; testCaseInex <= testCase; testCaseInex++)
	{
		int t[501];
		int adj[501][501];
		int inDegree[501];
		int n;

		scanf("%d", &n);

		for(int i=1; i<=n; i++)
		{
			int temp;
			scanf("%d", &temp);
			t[i] = temp;
		}

		for (int i = 1; i <= n; i++)
		{
			inDegree[i] = 0;
		}

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                adj[i][j] = 0;
            }
        }

		for (int i = 1; i <= n; i++)
		{
			for (int j = (i + 1); j <= n; j++)
			{			
                adj[t[i]][t[j]] = 1;
                inDegree[t[j]]++;
            }
		}

		int m;
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			
			if (adj[a][b] == 1)
			{
				adj[a][b] = 0;
				adj[b][a] = 1;
				inDegree[a]++;
				inDegree[b]--;
			}
			else
			{
				adj[b][a] = 0;
				adj[a][b] = 1;
				inDegree[b]++;
				inDegree[a]--;
			}
		}

		queue<int> q;
		queue<int> result;

		for (int i = 1; i <= n; i++)
		{
			if (inDegree[i] == 0) q.push(i);
		}

		if(!q.empty()) result.push(q.front());

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			if (!q.empty()) break;
			for (int i = 1; i <= n; i++)
			{
				if (adj[cur][i] > 0)
				{
					inDegree[i]--;
					if (inDegree[i] == 0)
					{
						q.push(i);
						result.push(i);
					}
				}
			}
		}

		if (!q.empty())
		{
			printf("?");
		}
		else if (result.size() != n)
		{
			printf("IMPOSSIBLE");
		}
		else
		{
			while (!result.empty())
			{
				int val = result.front();
				result.pop();
				printf("%d", val);

				if (!result.empty())
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}

