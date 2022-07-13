#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N_M_MAX = 1000;
const int MAX = N_M_MAX * N_M_MAX;

int map[MAX];
pair<int, int> list[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int backup[MAX][2];

int N, M = 0;

void bfs(int start, int end)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));

	memset(backup, -1, sizeof(int) * MAX);
	backup[0][0] = 1;

	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = (temp.first / M) + list[k].first;
			int y = (temp.first % M) + list[k].second;

			if ((x < 0) || (y < 0)) continue;
			if ((x >= N) || (y >= M)) continue;

			int index = (x * M) + y;

			if (index == end)
			{
				printf("%d", backup[temp.first][temp.second] + 1);
				return;
			}

			int wall = temp.second;
			if (map[index] == 1) //º®
			{
				if (wall != 1)//º®¾ÆÁ÷¾È»Ñ¼ÌÀ½
				{
					wall = 1; //º®»Ñ¼ö±â
					if (backup[index][wall] == -1)
					{
						backup[index][wall] = backup[temp.first][0] + 1;
						q.push(make_pair(index, wall));
					}
				}
			}
			else //º®¾Æ´Ô
			{
				if (backup[index][wall] == -1)
				{
					backup[index][wall] = backup[temp.first][wall] + 1;
					q.push(make_pair(index, wall));
				}
			}
		}
	}
	printf("%d", backup[end][0]);
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		char temp[N_M_MAX];
		scanf("%s", &temp);

		for (int j = 0; j < M; j++)
		{
			int a = temp[j] - '0';
			int current = (i * M) + j; //ÇöÀç index

			map[current] = a;
		}
	}
	bfs(0, (N * M - 1));

	return 0;
}