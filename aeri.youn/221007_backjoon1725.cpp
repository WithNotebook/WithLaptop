#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

long long list[100002];

int main()
{
	long long result = 0;

	int N = 0; //1 <= N <= 100,000
	cin >> N;

	stack<int> s;
	s.push(0);
	for (int i = 1; i <= (N + 1); i++)
	{
		if (i == (N + 1)) list[i] = 0;
		else cin >> list[i];

		while ((!s.empty()) && (list[s.top()] > list[i]))
		{
			int index = s.top();
			int height = list[index];
			s.pop();

			long long value = height * ((i-1) - (s.top()));
			result = max(result, value);
		}
		s.push(i);
	}

 	cout << result;

	return 0;
}

