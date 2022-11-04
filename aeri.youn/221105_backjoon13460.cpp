#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

char map[10][10];
bool visited[10][10][10][10];

struct point
{
    int red_x;
    int red_y;
    int blue_x;
    int blue_y;
    int distance;
};

int main()
{
    int N, M;
    cin >> N >> M;

    point start;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'R')
            {
                start.red_x = i;
                start.red_y = j;
            }
            else if (map[i][j] == 'B')
            {
                start.blue_x = i;
                start.blue_y = j;
            }
        }
    }
    start.distance = 0;

    queue<point> q;
    q.push(start);

    visited[start.red_x][start.red_y][start.blue_x][start.blue_y] = true;

    const int move[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!q.empty())
    {
        point current = q.front();
        q.pop();

        if (current.distance > 10)
        {
            cout << -1;
            return 0;
        }
        if ((map[current.red_x][current.red_y] == 'O') && map[current.blue_x][current.blue_y] != 'O')
        {
            cout << current.distance;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int next_red_x = current.red_x;
            int next_red_y = current.red_y;
            while ((map[next_red_x][next_red_y] != '#') && (map[next_red_x][next_red_y] != 'O'))
            {
                next_red_x = next_red_x + move[i][0];
                next_red_y = next_red_y + move[i][1];
            }
            if (map[next_red_x][next_red_y] == '#')
            {
                next_red_x = next_red_x - move[i][0];
                next_red_y = next_red_y - move[i][1];
            }

            int next_blue_x = current.blue_x;
            int next_blue_y = current.blue_y;
            while ((map[next_blue_x][next_blue_y] != '#') && (map[next_blue_x][next_blue_y] != 'O'))
            {
                next_blue_x = next_blue_x + move[i][0];
                next_blue_y = next_blue_y + move[i][1];
            }
            if (map[next_blue_x][next_blue_y] == '#')
            {
                next_blue_x = next_blue_x - move[i][0];
                next_blue_y = next_blue_y - move[i][1];
            }

            if (next_red_x == next_blue_x && next_red_y == next_blue_y)
            {
                if (map[next_red_x][next_red_y] != 'O')
                {
                    int red_distance = abs(current.red_x - next_red_x) + abs(current.red_y - next_red_y);
                    int blue_distance = abs(current.blue_x - next_blue_x) + abs(current.blue_y - next_blue_y);
                    if (red_distance > blue_distance)
                    {
                        next_red_x = next_red_x - move[i][0];
                        next_red_y = next_red_y - move[i][1];
                    }
                    else if (red_distance < blue_distance)
                    {
                        next_blue_x = next_blue_x - move[i][0];
                        next_blue_y = next_blue_y - move[i][1];
                    }
                }
            }

            if (!visited[next_red_x][next_red_y][next_blue_x][next_blue_y]) 
            {
                visited[next_red_x][next_red_y][next_blue_x][next_blue_y] = true;
                q.push(point{ next_red_x, next_red_y, next_blue_x, next_blue_y, (current.distance+1) });
            }
        }
    }
    cout << -1;
    return 0;
}
