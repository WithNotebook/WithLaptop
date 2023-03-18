#include<iostream>
#include<string.h>
#include<map>
#define MAX 100001
using namespace std;

int T, F;
map<string, int> friendsMap;
int parent[MAX];
int friendNum[MAX];

void init()
{
	for (int i = 0; i < MAX; i++)
	{
		parent[i] = i;
	}
	friendsMap.clear();
}

int find(int a)
{
	if (parent[a] == a) return a;

	return (parent[a] = find(parent[a]));
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a < b)
	{
		friendNum[a] += friendNum[b];
		parent[b] = a;
	}
	else
	{
		friendNum[b] += friendNum[a];
		parent[a] = b;
	}
}

int main()
{
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		init();
		cin >> F;
		int index = 0;
		for (int i = 0; i < F; i++)
		{
			string fr1, fr2;
			cin >> fr1 >> fr2;
			if (friendsMap.find(fr1) == friendsMap.end())
			{
				friendsMap.insert({ fr1, ++index });
			}

			if (friendsMap.find(fr2) == friendsMap.end())
			{
				friendsMap.insert({ fr2, ++index });
			}
			
			//value(배열 index)를 찾아서 find-union 해줌
			merge(friendsMap[fr1], friendsMap[fr2]);
			/*int count = 0;
			
			int findValue = parent[friendsMap[fr2]];
			for (int j = 1; j <= index; j++)
			{
				if (parent[j] == findValue)
				{
					count++;
				}
			}*/
			int parent1 = find(friendsMap[fr1]);
			int parent2 = find(friendsMap[fr2]);

			int maxCount = parent1 < parent2 ? parent2 : parent1;
			cout << maxCount << "\n";
		}
	}
	
	
	return 0;
}