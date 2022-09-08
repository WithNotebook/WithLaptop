#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	bool before[100001];
	bool after1[100001];
	bool after2[100001];

	string a = "";
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		before[i + 1] = a[i] - '0';
	}
	string b = "";
	cin >> b;
	for (int i = 0; i < b.size(); i++) {
		after1[i + 1] = b[i] - '0';
		after2[i + 1] = b[i] - '0';
	}

	int value1 = 0;
	for (int i = 1; i <= N; i++)
	{
		if (1 < i)
		{
			if (before[i - 1] == after1[i - 1])
			{
				continue;
			}
		}
		if (1 < i)
		{
			after1[i - 1] = !after1[i - 1];
		}
		after1[i] = !after1[i];
		if (i < N) {
			after1[i + 1] = !after1[i + 1];
		}
		value1++;
	}
	if (before[N] != after1[N])
	{
		value1 = -1;
	}

	int value2 = 0;
	for (int i = 2; i <= N; i++)
	{
		if (before[i - 1] == after2[i - 1])
		{
			continue;
		}
		after2[i - 1] = !after2[i - 1];
		after2[i] = !after2[i];
		if (i < N) {
			after2[i + 1] = !after2[i + 1];
		}
		value2++;
	}
	if (before[N] != after2[N])
	{
		value2 = -1;
	}

	if (value1 == -1)
	{
		cout << value2;
	}
	else if (value2 == -1)
	{
		cout << value1;
	}
	else
	{
		cout << min(value1, value2);
	}

	return 0;
}
