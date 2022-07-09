#include<stdio.h>
#include<queue>

using namespace std;

#define NMAX 1002
#define MMAX 1002

#define ROAD 0
#define WALL 1
#define NOT_MOVE -1


struct pos 
{
    int x, y;
    bool breakWall = false;
    pos(int inX, int inY, bool inBreakWall = false)
    {
        x = inX;
        y = inY;
        breakWall = inBreakWall;
    }
};


struct map
{
    int info[NMAX][MMAX];
    bool visited[NMAX][MMAX][2]; //visible array[2] 1 : not break wall 2 : break wall
    int moveCount[NMAX][MMAX][2]; //visible array[2] 1 : not break wall 2 : break wall


};

const pos _direction[4] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
int _N, _M;
map _map;

void init()
{
    for(int i=0; i<NMAX; i++)
    {
        for(int j=0; j<MMAX; j++)
        {
            _map.info[i][j] = NOT_MOVE; 
        }
    }

    for(int i=0; i<NMAX; i++)
    {
        for(int j=0; j<MMAX; j++)
        {
            for(int k=0; k<2; k++)
            {
                _map.visited[i][j][k] = false; 
                _map.moveCount[i][j][k] = 0;
            }
        }
    }
}

bool isNotMove(pos Pos)
{
    return _map.info[Pos.x][Pos.y] == NOT_MOVE;
}

bool isWall(pos Pos)
{
    return _map.info[Pos.x][Pos.y] == WALL;
}

bool isRoad(pos Pos)
{
    return _map.info[Pos.x][Pos.y] == ROAD;
}

bool isVisited(pos Pos)
{
    return _map.visited[Pos.x][Pos.y][Pos.breakWall] == true;
}


int bfs()
{
    queue<pos> q;
    pos startPos(1, 1, false);

    q.push(startPos);
    _map.moveCount[q.front().x][q.front().y][0]++;
    _map.visited[q.front().x][q.front().y][0] = true;

    while(!q.empty())
    {
        pos curPos(q.front().x, q.front().y, q.front().breakWall); 
        q.pop();

        if((curPos.x == _N) && (curPos.y == _M))
        {
            return _map.moveCount[curPos.x][curPos.y][curPos.breakWall]; 
        }

        for(int i = 0;  i<4; i++)
        {
            pos nextPos(curPos.x +_direction[i].x,
                        curPos.y +_direction[i].y,
                        curPos.breakWall);
            
            if(isNotMove(nextPos) or isVisited(nextPos))
            {
                continue;
            }

            if(isRoad(nextPos))
            {
                _map.visited[nextPos.x][nextPos.y][nextPos.breakWall] = true;
                _map.moveCount[nextPos.x][nextPos.y][nextPos.breakWall] = _map.moveCount[curPos.x][curPos.y][curPos.breakWall] + 1;
                q.push(nextPos);
            }

            if(isWall(nextPos) && !nextPos.breakWall)
            {
                _map.visited[nextPos.x][nextPos.y][1] = true;
                _map.moveCount[nextPos.x][nextPos.y][1] = _map.moveCount[curPos.x][curPos.y][0] + 1;
                nextPos.breakWall = true;
                q.push(nextPos);
            }
        }


    }

    return -1;

}

int backjoon2206()
{   
    init();

    scanf("%d %d",&_N, &_M);

    for(int i=1; i<=_N; i++)
    {
        for(int j=1; j<=_M; j++)
        {
            scanf("%1d", &_map.info[i][j]);
        }
    }

    int result = bfs();
    printf("%d", result);
    return 0;
}