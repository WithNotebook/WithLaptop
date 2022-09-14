#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> list[100001];
bool checked[100001];

long long result = 0;
int y = 0;

void dfs(int a, long long sum)
{
	checked[a] = true;

	bool end = false;
	for (auto i = list[a].begin(); i < list[a].end(); i++)
	{
		if (checked[(*i).first])
		{
			continue;
		}
		end = true;
		dfs((*i).first, (sum + (*i).second));
	}
	if (!end)
	{
		if ((result == 0) || (result < sum))
		{
			result = sum;
			y = a;
		}
	}
}

int main()
{
	int v = 0;
	cin >> v;

	for (int i = 0; i < v; i++)
	{
		int num = 0;
		cin >> num;

		while(true)
		{
			int a, b = 0;
			cin >> a;
			if (a == -1) break;

			cin >> b;

			list[num].push_back(make_pair(a, b));
		}
	}

	dfs(1, 0);
	memset(checked, false, sizeof(checked));
	dfs(y, 0);
	/*for (int i = 1; i <= v; i++)
	{
		if (list[i].size() == 1)
		{
			memset(checked, false, sizeof(checked));

			dfs(i, 0);
		}
	}*/
	cout << result;

	return 0;
}
