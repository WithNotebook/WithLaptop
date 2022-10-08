#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int barNum, ans = 0, bar[100002] = { 0, };
	stack<int> stk;

	cin >> barNum;

	for (int i = 1; i <= barNum; i++) cin >> bar[i];

	stk.push(0);
	for (int i = 1; i <= barNum + 1; i++)
	{

		while (!stk.empty() && bar[stk.top()] > bar[i])
		{
			int cur = stk.top();
			stk.pop();
			ans = max(ans, bar[cur] * (i - stk.top() - 1));
		}
		stk.push(i);
	}
	cout << ans;

}