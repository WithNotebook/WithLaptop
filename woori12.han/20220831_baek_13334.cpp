#include<iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		a.second < b.second;
	}
}

vector<pair<int, int>> v;
priority_queue<int> pq;

int main()
{
	int s, e, length;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;

		if (s <= e)
		{
			v.push_back({ s, e });
		}
		else
		{
			v.push_back({ e, s });
		}
	}

	cin >> length;

	sort(v.begin(), v.end(), comp);

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		int start = v[i].first;
		int end = v[i].second;

		if (end - start > length)
		{
			continue;
		}

		pq.push(-start);

		while (!pq.empty())
		{
			int num = -pq.top();
			if (num + length >= end)
			{
				break;
			}
			pq.pop();
		}
		res = max(res, (int)pq.size());
	}

	cout << res << "\n";

	return 0;
}