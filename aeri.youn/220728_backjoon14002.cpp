#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	int N = 0;
	scanf("%d", &N);

	int map[1000];
	int dp[1000];
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		scanf("%d", &temp);

		map[i] = temp;
	}

	int parent[1000];
	int max_result = 1;
	int result = 0;
	dp[0] = 1;

	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0)
			{
				dp[i] = max(1, dp[i]);
			}
			if (map[i] > map[j])
			{
				if ((dp[j] + 1) > dp[i])
				{
					dp[i] = (dp[j] + 1);
					parent[i] = j;
				}
			}
			if (max_result < dp[i])
			{
				max_result = dp[i];
				result = i;
			}
		}
	}
	printf("%d\n", max_result);

	vector<int> grape;
	grape.push_back(map[result]);
	while (parent[result] != -1)
	{
		grape.push_back(map[parent[result]]);
		result = parent[result];
	}
	for (auto i = (grape.end()); i > grape.begin(); i--)
	{
		printf("%d ", (*(i - 1)));
	}

	return 0;
}
