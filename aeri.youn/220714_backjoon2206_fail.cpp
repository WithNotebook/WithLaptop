#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N_M_MAX = 1000;
const int MAX = N_M_MAX * N_M_MAX;

vector<pair<int, int>> map[MAX];
pair<int, int> list[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int backup[MAX][2];

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

		for (auto i = map[temp.first].begin(); i < map[temp.first].end(); i++)
		{
			if ((*i).first == end)
			{
				printf("%d", backup[temp.first][temp.second] + 1);
				return;
			}

			int wall = temp.second;
			if ((*i).second == 1) //∫Æ
			{
				if (wall != 1)//∫Ææ∆¡˜æ»ª—ºÃ¿Ω
				{
					wall = 1; //∫Æª—ºˆ±‚
					if (backup[(*i).first][wall] == -1)
					{
						backup[(*i).first][wall] = backup[temp.first][0] + 1;
						q.push(make_pair((*i).first, wall));
					}
				}
			}
			else //∫Ææ∆¥‘
			{
				if (backup[(*i).first][wall] == -1)
				{
					backup[(*i).first][wall] = backup[temp.first][wall] + 1;
					q.push(make_pair((*i).first, wall));
				}
			}
		}
	}
	printf("%d", backup[end][0]);
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
			int current = (i * M) + j; //«ˆ¿Á index

			for (int k = 0; k < 4; k++)
			{
				int x = (current / M) + list[k].first;
				int y = (current % M) + list[k].second;

				if ((x < 0) || (y < 0)) continue;
				if ((x >= N) || (y >= M)) continue;

				int index = (x * M) + y; //¡÷∫Ø index
				map[index].push_back(make_pair(current, a));
			}
		}
	}
	bfs(0, (N * M - 1));

	return 0;
}