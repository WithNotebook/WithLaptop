#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int N;

	scanf("%d", &N);
	
	vector<int> arr(N);
	vector<int> dp(N);
	vector<int> lis[1010];
	vector<int> answer;
	for (int i = 0; i < N; i++) { // dp N번 돌면서 갱신
		scanf("%d", &arr[i]);
		dp[i] = 1;
		lis[i].push_back(arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) 
				{
					lis[i].clear();
					lis[i] = lis[j];
					lis[i].push_back(arr[i]);
					dp[i] = dp[j] + 1;
				}
			}
		}
		if (answer.size() < lis[i].size()) {
			answer = lis[i];
		}
	}

	printf("%d\n", answer.size());
	for (auto& a : answer)
		printf("%d ", a);
}