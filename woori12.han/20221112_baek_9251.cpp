#include<iostream>
#include<string>
using namespace std;


int lcs[1001][1001];
int main()
{
	string input1, input2;
	cin >> input1 >> input2;

	for (int i = 1; i <= input1.length(); i++)
	{
		for (int j = 1; j <= input2.length(); j++)
		{
			if (input1[i - 1] == input2[j - 1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	cout << lcs[input1.length()][input2.length()] << "\n";
	return 0;
}