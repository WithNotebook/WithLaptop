#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main()
{
    char map[1000][1000];
    bool visited[1000][1000];

    int R, C;
    scanf("%d %d", &R, &C);

    queue<pair<int, int>> fire;
    pair<int, int> jihun;

    getchar();
    for(int i = 0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            visited[i][j] = false;
            char temp = getchar();
            map[i][j] = temp;
            if(temp == 'J')
            {
                jihun.first=i;
                jihun.second=j;
                map[i][j] = '.';
                visited[i][j] = true;
            }

            if(temp == 'F')
            {
                fire.push(pair<int, int>(i, j));
            }
        }
        getchar();
    }

    queue<pair<int, int>> jihunQ;
    jihunQ.push(jihun);

    int cnt = 0;
    int result = 1000000;
    while (!jihunQ.empty())
    {
        cnt++;
        int fireCnt = fire.size();
        while (fireCnt!=0)
        {
            pair<int, int> cur = fire.front();
            fire.pop();

            for(auto dir = directions.begin(); dir!=directions.end(); dir++)
            {
                pair<int, int> next;
                next.first = cur.first + (*dir).first;
                next.second = cur.second + (*dir).second;

                if((next.first >= R) || (next.second >= C) || (next.first < 0) || (next.second < 0)) continue;

                if((map[next.first][next.second] != '#') && (map[next.first][next.second] != 'F'))
                {
                    map[next.first][next.second] = 'F';
                    fire.push(next);
                }
            }
            fireCnt--;
        }

        int jihunCnt = jihunQ.size();
        while (jihunCnt!=0)
        {
            pair<int, int> cur = jihunQ.front();
            jihunQ.pop();

            for(auto dir = directions.begin(); dir!=directions.end(); dir++)
            {
                pair<int, int> next;
                next.first = cur.first + (*dir).first;
                next.second = cur.second + (*dir).second;

                if((next.first >= R) || (next.second >= C) || (next.first < 0) || (next.second < 0))
                {
                    result = min(result, cnt);
                    continue;
                }

                if((map[next.first][next.second] != '#') && (map[next.first][next.second] != 'F'))
                {
                    if(!visited[next.first][next.second])
                    {
                        jihunQ.push(next);
                        visited[next.first][next.second] = true;
                    }
                }
            }
            jihunCnt--;
        }
    }

    if (result == 1000000)
    {
       printf("IMPOSSIBLE");
    }
    else
    {
        printf("%d", result);
    }

    return 0;
}