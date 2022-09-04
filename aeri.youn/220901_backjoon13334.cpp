#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<pair<int, int>> list;
	for (int i = 0; i < n; i++)
	{
		int home, office;
		cin >> home >> office;
		if (home > office) 
		{ 
			swap(home, office); 
		}
		list.push_back(make_pair(office, home));
	}
	sort(list.begin(), list.end());

	int d = 0;
	cin >> d;

	int result = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < list.size(); i++)
	{
		int start = list[i].first - d;
		int end = list[i].first;

		if (list[i].second < start)
		{
			continue;
		}
		pq.push(list[i].second);

		while(!pq.empty())
		{
			if ((pq.top()) >= start)
			{
				break;
			}
			pq.pop();
		}
		result = max(result, (int)pq.size());
	}
	cout << result;
	return 0;
}