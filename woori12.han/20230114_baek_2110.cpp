#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, C;

//int pos[1000001];
vector<int> pos;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> C;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		pos.push_back(a);
	}

	sort(pos.begin(), pos.end());

	int maxInterval = pos[N - 1] - pos[0];
	int minInterval = 1;
	int mid, wifiCount = 1, prevPos, res = 0;
	while (minInterval <= maxInterval)
	{
		mid = (maxInterval + minInterval) / 2;
		wifiCount = 1;
		prevPos = pos[0];

		for (int i = 0; i < N; i++)
		{
			if ((pos[i] - prevPos) >= mid)
			{
				wifiCount++;
				prevPos = pos[i];

			}
		}

		if (wifiCount >= C)
		{
			minInterval = mid + 1;
			if (res <= mid)
			{
				res = mid;
			}
		}
		else
		{
			maxInterval = mid - 1;
		}
	}

	cout << res << "\n";
	return 0;
}