#include <iostream>
#include <queue>

const int MAX = 1000;
const int DIRECTION_NUM = 4;

using namespace std;

char Map[MAX + 1][MAX + 1];
int F_Step[MAX + 1][MAX + 1];
int J_Step[MAX + 1][MAX + 1];

int row, column;
char tmp;
int ans = INT32_MAX;

struct Point {
    int x;
    int y;

    Point operator+(Point p1)
    {
        Point ret;
        ret.x = x + p1.x;
        ret.y = y + p1.y;
        return ret;
    }
};

Point Move[DIRECTION_NUM] = { {-1,0}, {0, -1}, {1,0}, {0, 1} };

void makeFireStep()
{
    queue<Point> q;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            F_Step[i][j] = 0;
            if (Map[i][j] == 'F')
            {
                q.push({ i, j });
                F_Step[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        Point Cur = q.front();
        q.pop();
        for (int direction = 0; direction < DIRECTION_NUM; direction++)
        {
            Point next = Cur + Move[direction];

            if (next.x < 1 || next.y < 1 || next.x > row || next.y > column)
            {
                continue;
            }
            else if (F_Step[next.x][next.y] > 0 || Map[next.x][next.y] == '#')
            {
                continue;
            }
            q.push(next);
            F_Step[next.x][next.y] = F_Step[Cur.x][Cur.y] + 1;
        }
    }
}

int Solve()
{
    queue<Point> q;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            J_Step[i][j] = 0;
            if (Map[i][j] == 'J')
            {
                q.push({ i, j });
                J_Step[i][j] = 1;
            }
        }
    }


    while (!q.empty())
    {
        Point Cur = q.front();
        q.pop();
        for (int direction = 0; direction < DIRECTION_NUM; direction++)
        {
            Point next = Cur + Move[direction];

            if (next.x < 1 || next.y < 1 || next.x > row || next.y > column)
            {
                return J_Step[Cur.x][Cur.y];
            }
            if (J_Step[next.x][next.y] > 0 || Map[next.x][next.y] == '#')
            {
                continue;
            }
            if (F_Step[Cur.x][Cur.y] > 0 && J_Step[Cur.x][Cur.y] + 1 >= F_Step[next.x][next.y])
            {
                continue;
            }
            q.push(next);
            J_Step[next.x][next.y] = J_Step[Cur.x][Cur.y] + 1;
        }
    }

    return -1;
}

int 4179()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> column;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            cin >> tmp;
            Map[i][j] = tmp;
        }
    }

    makeFireStep();
    int result = Solve();

    if (result == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << result << '\n';
    }
}
