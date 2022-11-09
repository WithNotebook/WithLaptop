#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

char str1[1001];
char str2[1001];
int map[1001][1001];

int main()
{
	cin >> str1;
	cin >> str2;

	for (int i = 1; i <= strlen(str1); i++)
	{
		for (int j = 1; j <= strlen(str2); j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				map[i][j] = map[i - 1][j - 1] + 1;
			}
			else
			{
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
			}
		}
	}
	cout << map[strlen(str1)][strlen(str2)];
	return 0;
}
