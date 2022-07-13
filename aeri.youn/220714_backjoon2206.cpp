#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N_M_MAX = 1000;
const int MAX = N_M_MAX * N_M_MAX;

int map[N_M_MAX][N_M_MAX];
int backup[N_M_MAX][N_M_MAX][2];

pair<int, int> list[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

void bfs(int start_x, int start_y, int end_x, int end_y)
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(start_x, start_y), 0));

	memset(backup, -1, sizeof(int) * (N_M_MAX * N_M_MAX * 2));
	backup[0][0][0] = 1;

	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = temp.first.first + list[i].first;
			int y = temp.first.second + list[i].second;

			if ((x < 0) || (y < 0)) continue;
			if ((x > end_x) || (y > end_y)) continue;

			if ((x == end_x) && (y == end_y))
			{
				printf("%d", backup[temp.first.first][temp.first.second][temp.second] + 1);
				return;
			}

			int wall = temp.second;
			if (map[x][y] == 1) //º®
			{
				if (wall != 1)//º®¾ÆÁ÷¾È»Ñ¼ÌÀ½
				{
					wall = 1; //º®»Ñ¼ö±â
					if (backup[x][y][wall] == -1)
					{
						backup[x][y][wall] = backup[temp.first.first][temp.first.second][0] + 1;
						q.push(make_pair(make_pair(x, y), wall));
					}
				}
			}
			else //º®¾Æ´Ô
			{
				if (backup[x][y][wall] == -1)
				{
					backup[x][y][wall] = backup[temp.first.first][temp.first.second][wall] + 1;
					q.push(make_pair(make_pair(x, y), wall));
				}
			}
		}
	}
	printf("%d", backup[end_x][end_y][0]);
}

int main()
{
	int N, M = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		char temp[N_M_MAX];
		scanf("%s", &temp);

		for (int j = 0; j < M; j++)
		{
			int a = temp[j] - '0';
			int current = (i * M) + j; //ÇöÀç index

			map[i][j] = a;
		}
	}
	bfs(0, 0, (N - 1), (M - 1));

	return 0;
}