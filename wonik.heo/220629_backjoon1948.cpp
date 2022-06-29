#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_CITY = 10001;

int In[MAX_CITY] = { 0, };
int Cost[MAX_CITY] = { 0, };
bool visit[MAX_CITY] = { false, };
int ans_RoadCnt = 0;

vector<pair<int, int>> Info[MAX_CITY];
vector<pair<int, int>> Reverse_Info[MAX_CITY];

void Ans_Cost(int start)
{
    queue<pair<int, int>> Queue;

    Queue.push(make_pair(start, 0));

    while (!Queue.empty())
    {
        int current = Queue.front().first;
        int current_cost = Queue.front().second;
        Queue.pop();

        for (int i = 0; i < Info[current].size(); i++)
        {
            int next = Info[current][i].first;
            int next_cost = Info[current][i].second;

            Cost[next] = max(Cost[next], current_cost + next_cost);
            In[next]--;

            if (In[next] == 0)
            {
                Queue.push(make_pair(next, Cost[next]));
            }
        }
    }

}

void Ans_RoadCnt(int end)
{
    queue<int> Queue;

    Queue.push(end);
    visit[end] = true;

    while (!Queue.empty())
    {
        int current = Queue.front();
        Queue.pop();

        for (int i = 0; i < Reverse_Info[current].size(); i++)
        {
            int next = Reverse_Info[current][i].first;
            int next_cost = Reverse_Info[current][i].second;

            if ((Cost[current] - next_cost == Cost[next]))
            {
                ans_RoadCnt++;
                if (!visit[next])
                {
                    visit[next] = true;
                    Queue.push(next);
                }
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int city, road, start, end, cost;

    cin >> city >> road;

    for (int i = 0; i < road; i++)
    {
        cin >> start >> end >> cost;
        Info[start].push_back(make_pair(end, cost));
        Reverse_Info[end].push_back(make_pair(start, cost));
        In[end]++;
    }
    cin >> start >> end;
    Ans_Cost(start);
    Ans_RoadCnt(end);

    cout << Cost[end] << endl << ans_RoadCnt << endl;

}
