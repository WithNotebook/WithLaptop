#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N = 0; //(1 ≤ N ≤ 100,000,000)
int k = 0; //(1 ≤ k ≤ 1,000,000,000)

vector<long long> list;

int main()
{
	cin >> N;
	
	int N_bak = N;
	int N_num = 0;
	while (N_bak) {
		N_num++;
		N_bak = N_bak / 10;
	}

	int j = 1;
	for (int i = 1; i <= N_num; i++)
	{
		list.push_back((i * pow(10, i)) - j);
		j = j * 10 + 1;
	}

	cin >> k;

	auto value = lower_bound(list.begin(), list.end(), k);
	int index = (value - list.begin());
	if (index >= list.capacity())
	{
		cout << -1;
		return 0;
	}

	int min = pow(10, index);
	int max = pow(10, (index + 1)) - 1;

	if (index >= 1)
	{
		k = k - list[index - 1];
	}
	int a = k / (index + 1);
	int b = k % (index + 1);

	int c = min + a - 1;

	if (b > 0)
	{
		c = c + 1;
	}

	if (c > N)
	{
		cout << -1;
		return 0;
	}

	string s = to_string(c);
	if (b != 0) 
	{ 
		b = b - 1;
	}
	else
	{
		b = index;
	}
	cout << s[b];

	return 0;
}
