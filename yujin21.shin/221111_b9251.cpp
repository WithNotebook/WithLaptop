#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int dp[1001][1001];
int main() {
	string str[2];
	cin >> str[0] >> str[1];

	for (int i = 1; i <= str[1].size(); i++)
		for (int j = 1; j <= str[0].size(); j++) {
			if (str[1][i - 1] == str[0][j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp[str[1].size()][str[0].size()] << '\n';
}