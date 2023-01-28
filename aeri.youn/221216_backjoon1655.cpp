#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N = 0;
	scanf("%d", &N);

	priority_queue<int, vector<int>, greater<int>> min_pq;
	priority_queue<int, vector<int>, less<int>> max_pq;

	int value = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &value);

		if (min_pq.empty() && max_pq.empty())
		{
			max_pq.push(value);
		}
		else
		{			
			if (min_pq.size() < max_pq.size())
			{
				min_pq.push(value);
			}
			else
			{
				max_pq.push(value);
			}
			if (min_pq.top() < max_pq.top())
			{
				int a = min_pq.top();
				min_pq.pop();
				int b = max_pq.top();
				max_pq.pop();

				min_pq.push(b);
				max_pq.push(a);
			}
		}
		printf("%d\n", max_pq.top());
	}
	return 0;
}
