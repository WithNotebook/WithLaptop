#include <iostream>
#include <vector>
#define MAX_NUM 100020
using namespace std;

struct node
{
	int thickness;
	int cost;
	
	node(int t, int c)
	{
		thickness = t;
		cost = c;
	}
};

int totalCost;
int totalThick;
int totalCount;
int minR, minThick;
vector<node> items[MAX_NUM];

void dfs(int num, int cost, int thick, int count)
{
	if (num >= MAX_NUM || (totalCost != 0 && cost > totalCost))
	{
		return;
	}

	int length = items[num].size();

	for (int i = 0; i < length; i++)
	{
		int newCost = cost + items[num][i].cost;
		int newThick = thick + items[num][i].thickness;

		if (newThick >= minThick)
		{
			if (newCost == totalCost)
			{
				totalCount = min(totalCount, count);
			}
			else if(newCost < totalCost)
			{
				totalCost = newCost;
				totalCount = count;
			}
		}
		else
		{
			int nextItem = num + items[num][i].thickness;
			dfs(nextItem, newCost, newThick, count + 1);
		}
	}
}

int main()
{
	int T, N;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		totalCost = 0;
		totalThick = 0;
		totalCount = 0;

		cin >> N >> minR >> minThick;

		int a = 0, b = 0, c = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> a >> b >> c;

			items[a].push_back(node(b, c));
		}
		dfs(a, 0, 0, 1);
		printf("#%d %d %d\n", t, totalCost, totalCount);

		for (int i = 0; i < MAX_NUM; i++)
		{
			items[i].clear();
		}
		
	}
}
