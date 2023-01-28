#include<iostream>
#include<queue>
using namespace std;

char map[1001][1001] = { 0, };
int R, C;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int visited[1001][1001] = { 0, };
int main()
{
	cin >> R >> C;

	int jPosX, jPosY, fireX, fireY;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				jPosX = i;
				jPosY = j;
			}
			else if (map[i][j] == 'F')
			{
				fireX = i;
				fireY = j;
			}
		}
	}

	queue<pair<pair<int, int>, int>> q;
	queue<pair<int, int>> fireQ;

	fireQ.push({ fireX, fireY });
	q.push({ {jPosX, jPosY}, 1 });
	while (true)
	{
		int fireQSize = fireQ.size();
		for (int j = 0; j < fireQSize; j++)
		{
			int curFireX = fireQ.front().first;
			int curFireY = fireQ.front().second;

			fireQ.pop();
			for (int i = 0; i < 4; i++)
			{
				int newFireX = curFireX + dx[i];
				int newFireY = curFireY + dy[i];

				if (newFireX >= 0 && newFireX < R && newFireY >= 0 && newFireY < C)
				{
					if (map[newFireX][newFireY] == '.')
					{
						fireQ.push({ newFireX, newFireY });
						map[newFireX][newFireY] = 'F';
					}
				}
			}
		}
		
		int qSize = q.size();
		if (qSize == 0)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		for (int j = 0; j < qSize; j++)
		{
			int curX = q.front().first.first;
			int curY = q.front().first.second;
			int time = q.front().second;

			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int newX = curX + dx[i];
				int newY = curY + dy[i];

				if (newX >= 0 && newX < R &&
					newY >= 0 && newY < C &&
					visited[newX][newY] == 0 &&
					map[newX][newY] == '.')
				{
					if (newX == 0 || newY == 0 || newX == R - 1 || newY == C - 1)
					{
						cout << time + 1 << "\n";
						return 0;
					}
					else
					{
						q.push({ { newX, newY }, time + 1 });
						visited[newX][newY] = 1;
					}

				}
			}
		}
	}

	return 0;
}