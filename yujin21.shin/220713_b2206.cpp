#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct INFO {
	int x, y, cnt;
	int chance;
};

bool operator<(const INFO& a, const INFO& b) {
	if (a.cnt == b.cnt) {
		return a.chance < b.chance;
	}
	return a.cnt > b.cnt;
}

bool isValid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	else
		return true;
}

vector<vector<short>> questionMap(1000, vector<short>(1000));
bool visited[1000][1000][2];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &questionMap[i][j]);
		}
	}

	int answer = -1;
	priority_queue<INFO> pq;
	pq.push({ 0,0,1,1 }); // (1,1)에서 시작

	while (!pq.empty()) {
		INFO cur = pq.top();
		pq.pop();
		
		// 방문여부 체크
		if (visited[cur.x][cur.y][cur.chance])
			continue;
		else 
			visited[cur.x][cur.y][cur.chance] = true;

		// 목적지 도착
		if (cur.x == (n - 1) && cur.y == (m - 1)) {
			answer = cur.cnt;
			break;
		}

		for (int dir = 0; dir < 4; dir++) {
			
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int ncnt = cur.cnt + 1;
			int nchance = cur.chance;

			if (isValid(nx, ny)) {
				//벽
				if (questionMap[nx][ny] == 1) {
					if (nchance == 1) 
						nchance = 0;
					else 
						continue;
				}
				
				//방문 여부 체크
				if (visited[nx][ny][nchance]) //이건 해도 되고 안해도 됨. 하면 시간 줄어듦
					continue;
				else 
					pq.push({ nx,ny,ncnt,nchance });
			}
		}
	}
	printf("%d", answer);
}