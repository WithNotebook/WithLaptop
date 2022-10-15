#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> go[1001];
vector<pair<int, int>> back[1001];
int go_min[1001];
int back_min[1001];

int main()
{
	int n, m, x = 0;
	cin >> n >> m >> x;

	for (int i = 1; i <= m; i++)
	{
		int sou, des, cos = 0;
		cin >> sou >> des >> cos;

		go[des].push_back(make_pair(sou, cos));
		back[sou].push_back(make_pair(des, cos));
	}
	memset(go_min, 0, sizeof(go_min));
	memset(back_min, 0, sizeof(back_min));

	queue<pair<int, int>> q;
	q.push(make_pair(x, 0));
	while (!q.empty())
	{
		pair<int, int> current = q.front();
		q.pop();

		if (current.second > go_min[current.first]) continue;
		for (auto j = go[current.first].begin(); j < go[current.first].end(); j++)
		{
			if ((go_min[(*j).first] == 0) ||
				(((*j).second + current.second) < go_min[(*j).first]))
			{
				go_min[(*j).first] = ((*j).second + current.second);
				q.push(make_pair((*j).first, go_min[(*j).first]));
			}
		}
	}

	q.push(make_pair(x, 0));
	while (!q.empty())
	{
		pair<int, int> current = q.front();
		q.pop();

		if (current.second > back_min[current.first]) continue;
		for (auto j = back[current.first].begin(); j < back[current.first].end(); j++)
		{
			if ((back_min[(*j).first] == 0) ||
				(((*j).second + current.second) < back_min[(*j).first]))
			{
				back_min[(*j).first] = ((*j).second + current.second);
				q.push(make_pair((*j).first, back_min[(*j).first]));
			}
		}
	}

	go_min[x] = 0;
	back_min[x] = 0;

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, (go_min[i] + back_min[i]));
	}

	cout << result;
	return 0;
}