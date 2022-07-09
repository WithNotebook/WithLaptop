#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
int NEXT_MOVE[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N, M;
bool worldMap[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M][2];
bool inserted[MAX_N][MAX_M][2];

struct pointST {
	short x;
	short y;
	bool exploded;
	int distance;
};

queue<pointST> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;

			if (temp == '0') {
				worldMap[i][j] = true;
			}
		}
	}
	
	q.push(pointST{ 0, 0, false, 1 });
	inserted[0][0][0] = true;
	bool isArrived = false;
	int result = INT32_MAX;

	while (!q.empty()) {
		pointST cur = q.front();		
		q.pop();
		int tempExploded = cur.exploded ? 1 : 0;		

		visited[cur.x][cur.y][tempExploded] = true;

		if ((cur.x == N - 1) && (cur.y == M - 1)) {
			result = min(result, cur.distance);
			isArrived = true;
		}

		for (int i = 0; i < 4; i++) {
			short nextX = cur.x + NEXT_MOVE[i][0];
			short nextY = cur.y + NEXT_MOVE[i][1];

			if ((nextX < 0) || (nextX >= N) || (nextY < 0) || (nextY >= M)) {
				continue;
			}

			if (visited[nextX][nextY][tempExploded]) {
				continue;
			}

			if ((worldMap[nextX][nextY]) && (!inserted[nextX][nextY][tempExploded])) {
				q.push(pointST{ nextX, nextY, cur.exploded, cur.distance + 1 });
				inserted[nextX][nextY][tempExploded] = true;
			}
			else if ((cur.exploded == 0) && (!inserted[nextX][nextY][1])) {
				q.push(pointST{ nextX, nextY, true, cur.distance + 1 });
				inserted[nextX][nextY][1] = true;
			}
		}
	}	

	if (isArrived) {
		cout << result;
	}
	else {
		cout << -1;
	}

	return 0;
}