#include <iostream>
#include <algorithm>
#include <queue>


const int MAX = 100001;

using namespace std;

priority_queue<int, vector<int>> MaxPQ;
priority_queue<int, vector<int>, greater<int>> MinPQ;

priority_queue<int> emptyMaxPQ;
priority_queue<int, vector<int>, greater<int>> emptyMinPQ;

void 1655()
{
	int tempMax = MaxPQ.top();
	int tempMin = MinPQ.top();

	MaxPQ.pop();
	MinPQ.pop();

	MaxPQ.push(tempMin);
	MinPQ.push(tempMax);
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		if (MaxPQ.empty())
		{
			MaxPQ.push(input);
		}
		else
		{
			if (MinPQ.size() >= MaxPQ.size())
			{
				MaxPQ.push(input);
			}
			else
			{
				MinPQ.push(input);
			}

			if (MaxPQ.top() > MinPQ.top())
			{
				swap();
			}
		}

		cout << MaxPQ.top() << '\n';
	}



	MinPQ.swap(emptyMinPQ);
	MaxPQ.swap(emptyMaxPQ);

	return 0;
}
