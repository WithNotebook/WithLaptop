#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;

		if (maxHeap.size() == minHeap.size())
		{
			maxHeap.push(num);
		}
		else //(maxHeap.size() == minHeap.size() + 1)
		{
			minHeap.push(num);
		}

		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
		{
			int minHeapTop = minHeap.top();
			int maxHeapTop = maxHeap.top();

			minHeap.pop();
			maxHeap.pop();

			minHeap.push(maxHeapTop);
			maxHeap.push(minHeapTop);
		}

		cout << maxHeap.top() << "\n";
	}
	return 0;
}