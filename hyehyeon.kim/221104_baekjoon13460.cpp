#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

const int NEXT_MOVE[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

const int MAX_N = 10;
const int MAX_M = 10;

char board[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M][MAX_N][MAX_M];

struct pointST {
	int x;
	int y;
	int distance;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	pointST red;
	pointST blue;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			board[i][j] = temp;

			if (temp == 'R') {
				red = pointST{ i, j, 0 };
			}
			else if (temp == 'B') {
				blue = pointST{ i, j, 0 };
			}
		}
	}

	queue<pair<pointST, pointST>> q;
	q.push(make_pair(red, blue));
	visited[red.x][red.y][blue.x][blue.y] = true;

	bool isSucceded = false;
	int result = INT32_MAX;

	while (!q.empty()) {
		pair<pointST, pointST> curState = q.front();
		q.pop();

		pointST curRed = curState.first;
		pointST curBlue = curState.second;

		for (int i = 0; i < 4; i++) {
			int deltaX = NEXT_MOVE[i][0];
			int deltaY = NEXT_MOVE[i][1];

			bool isFailed = false;
			bool isBlueStopped = false;
			bool isRedStopped = false;
			int step = 1;
			int redStep = 1;
			int blueStep = 1;

			bool tempSucceeded = false;

			while ((!isRedStopped) || (!isBlueStopped)) {
				if ((!isBlueStopped) && (board[curBlue.x + deltaX * step][curBlue.y + deltaY * step] == 'O')) {
					isFailed = true;
					tempSucceeded = false;
					isBlueStopped = true;
				}

				if ((!isRedStopped) && (board[curRed.x + deltaX * step][curRed.y + deltaY * step] == 'O')) {
					tempSucceeded = true;
					isRedStopped = true;
				}

				if ((!isBlueStopped) &&
					((board[curBlue.x + deltaX * step][curBlue.y + deltaY * step] == '#') || ((isRedStopped && !tempSucceeded) && (curRed.x + redStep * deltaX == curBlue.x + step * deltaX) && (curRed.y + redStep * deltaY == curBlue.y + step * deltaY))))
				{
					isBlueStopped = true;
					blueStep = step - 1;
				}

				if ((!isRedStopped) &&
					((board[curRed.x + deltaX * step][curRed.y + deltaY * step] == '#') || ((isBlueStopped && !isFailed) && (curRed.x + step * deltaX == curBlue.x + blueStep * deltaX) && (curRed.y + step * deltaY == curBlue.y + blueStep * deltaY))))
				{
					isRedStopped = true;
					redStep = step - 1;

					if ((!isBlueStopped) &&
						((board[curBlue.x + deltaX * step][curBlue.y + deltaY * step] == '#') || ((isRedStopped && !tempSucceeded) && (curRed.x + redStep * deltaX == curBlue.x + step * deltaX) && (curRed.y + redStep * deltaY == curBlue.y + step * deltaY))))
					{
						isBlueStopped = true;
						blueStep = step - 1;
					}
				}

				step++;
			}

			if (isFailed) {
				continue;
			}

			if ((redStep == 0) && (blueStep == 0)) {
				continue;
			}

			int nextRedX = curRed.x + redStep * deltaX;
			int nextRedY = curRed.y + redStep * deltaY;
			int nextBlueX = curBlue.x + blueStep * deltaX;
			int nextBlueY = curBlue.y + blueStep * deltaY;

			if (visited[nextRedX][nextRedY][nextBlueX][nextBlueY]) {
				continue;
			}

			visited[nextRedX][nextRedY][nextBlueX][nextBlueY] = true;

			if (!tempSucceeded) {
				q.push(make_pair(pointST{ curRed.x + redStep * deltaX, curRed.y + redStep * deltaY, curRed.distance + 1 }, pointST{ curBlue.x + blueStep * deltaX, curBlue.y + blueStep * deltaY, curBlue.distance + 1 }));
			}
			else {
				isSucceded = true;
				result = min(result, curRed.distance + 1);
			}
		}
	}

	if ((!isSucceded) || (result > 10)) {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;
}