#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>>

const int MAX = 1000;
const int DIRECTION_NUM = 4;

using namespace std;

struct Info {
    int x;
    int y;
    int block;
    int distance;
};

struct Point {
    int x;
    int y;
};

int MAP[MAX + 1][MAX + 1];
int Visit[MAX + 1][MAX + 1][2] = { 0, };
Point Move[DIRECTION_NUM] = { {-1,0}, {0, -1}, {1,0}, {0, 1} };
bool isPossible = false;

int row, column;
int ans = INT32_MAX;

bool EnableMove(Info cur, Point move)
{
    bool return_Value = true;

    int Next_x = cur.x + move.x;
    int Next_y = cur.y + move.y;

    if ((Next_x > column) || (Next_x < 1) || (Next_y < 1) || (Next_y > row))
    {
        return false;
    }

    if (MAP[Next_y][Next_x] == 1 && cur.block == 1)
    {
        return false;
    }

    if (Visit[Next_y][Next_x][cur.block])
    {
        return false;
    }

    return return_Value;
}


void Solve()
{
    queue<Info> q;
    Visit[1][1][0] = true;
    q.push({ 1,1,0,1 });


    while (!q.empty())
    {
        Info Cur = q.front();

        if (Cur.x == column && Cur.y == row)
        {
            ans = min(ans, Cur.distance);
            isPossible = true;
        }

        q.pop();

        for (int i = 0; i < DIRECTION_NUM; i++)
        {
            if (EnableMove(Cur, Move[i]))
            {
                int Next_x = Cur.x + Move[i].x;
                int Next_y = Cur.y + Move[i].y;
                if (MAP[Next_y][Next_x] == 1)
                {
                    Visit[Next_y][Next_x][Cur.block + 1] = true;
                    q.push({ Next_x, Next_y, Cur.block + 1, Cur.distance + 1 });
                }
                else
                {
                    Visit[Next_y][Next_x][Cur.block] = true;
                    q.push({ Next_x, Next_y, Cur.block, Cur.distance + 1 });
                }
            }
        }

    }
}

int 2206()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> column;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            char a;
            cin >> a;
            MAP[i][j] = a - '0';
        }
    }

    Solve();
    int result = isPossible ? ans : -1;

    cout << result << endl;
}

