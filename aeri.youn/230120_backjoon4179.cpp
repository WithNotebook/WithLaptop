#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[1000][1000];

queue <pair<int, int>> q;

int fireDis[1000][1000];
int hoonDis[1000][1000];

int x[4] = { 0, 0, -1, 1 };
int y[4] = { -1, 1, 0, 0 };

int R, C = 0;

int bfs(pair<int, int> start)
{
	while (!q.empty())
	{
		pair<int, int> prev = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> cur = make_pair(prev.first + x[i], prev.second + y[i]);
			if ((cur.first < 0) || (cur.second < 0) || (cur.first >= R) || (cur.second >= C))
			{
				continue;
			}
			if ((map[cur.first][cur.second] == '#') || (fireDis[cur.first][cur.second] != 0))
			{
				continue;
			}
			q.push(make_pair(cur.first, cur.second));
			fireDis[cur.first][cur.second] = fireDis[prev.first][prev.second] + 1;
		}
	}

	q.push(start);
	hoonDis[start.first][start.second] = 1;

	while (!q.empty())
	{
		pair<int, int> prev = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> cur = make_pair(prev.first + x[i], prev.second + y[i]);
			if ((cur.first < 0) || (cur.second < 0) || (cur.first >= R) || (cur.second >= C))
			{
				return hoonDis[prev.first][prev.second];
			}
			if ((map[cur.first][cur.second] == '#') || (hoonDis[cur.first][cur.second] != 0))
			{
				continue;
			}
			if ((hoonDis[prev.first][prev.second] + 1) >= (fireDis[cur.first][cur.second]) && (fireDis[cur.first][cur.second] != 0))
			{
				continue;
			}

			q.push(make_pair(cur.first, cur.second));
			hoonDis[cur.first][cur.second] = hoonDis[prev.first][prev.second] + 1;
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &R, &C);

	char temp[1000];
	pair<int, int> hoon = { -1, -1 };

	memset(fireDis, 0, sizeof(fireDis));
	memset(hoonDis, 0, sizeof(hoonDis));

	for (int i = 0; i < R; i++)
	{
		scanf("%s", &temp);
		for (int j = 0; j < C; j++)
		{
			map[i][j] = temp[j];
			if (map[i][j] == 'J') { hoon.first = i; hoon.second = j; }
			if (map[i][j] == 'F')
			{
				q.push(make_pair(i, j));
				fireDis[i][j] = 1;
			}
		}
	}
	int result = bfs(hoon);

	if (result != -1) printf("%d", result);
	else printf("IMPOSSIBLE");
	return 0;
}
