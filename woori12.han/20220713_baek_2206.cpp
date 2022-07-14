#include<iostream>
#include<queue>
using namespace std;
struct pos 
{
	int x;
	int y;
	pos(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
};
int N, M;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int visited[1001][1001][2] = { 0, };
vector<int> map[1001];
void bfs(int start, int end, int block)
{
	queue<pair<pos, int>> q;
	q.push({ pos(start, end), block });
	visited[start][end][block] = 1;

	while (!q.empty())
	{
		int curX = pos(q.front().first).x;
		int curY = pos(q.front().first).y;
		int block = q.front().second;
		q.pop();
		
		if (curX == N && curY == M)
		{
			printf("%d\n", visited[curX][curY][block]);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M)
			{
				//방문한적 없고, 갈 수 있는 길일 때
				if (visited[nx][ny][block] == 0 && map[nx][ny] == 0)
				{
					visited[nx][ny][block] = visited[curX][curY][block] + 1;
					q.push({ pos(nx, ny), block});
				}
				else if (map[nx][ny] == 1 && block == 1)
				{
					//갈 수 없는 길인데 벽 부순적 없을 때
					visited[nx][ny][block - 1] = visited[curX][curY][block] + 1;
					q.push({ pos(nx, ny), block - 1});
				}
			}

		}
	}
	printf("%d\n", -1);
	return;
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		map[i].push_back(0);
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			map[i].push_back(c - '0');
		}
	}

	bfs(1, 1, 1);
	return 0;
}