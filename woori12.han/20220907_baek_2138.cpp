#include<iostream>
#include <string>
using namespace std;

int N;
string s, s2;
string res;

string changeSwitch(string tempS, int index)
{
	tempS[index] = (tempS[index] == '0') ? '1' : '0';
	if (index == 0)
	{
		tempS[index + 1] = (tempS[index + 1] == '0') ? '1' : '0';
	}
	else if (index > 0)
	{
		tempS[index - 1] = (tempS[index - 1] == '0') ? '1' : '0';
		if (index < N - 1)
		{
			tempS[index + 1] = (tempS[index + 1] == '0') ? '1' : '0';
		}
	}
	return tempS;
}

int main()
{
	cin >> N;
	char a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		s += a;
		s2 += a;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		res += a;
	}

	if (s == res)
	{
		cout << "0\n";
		return 0;
	}

	//s : 0번째 index의 스위치를 누르지 않을 경우
	//s2 : 0번째 index의 스위치를 누를 경우
	s2 = changeSwitch(s2, 0);
	int count1 = 0, count2 = 1;
	for (int i = 1; i < N; i++)
	{
		if (s[i - 1] != res[i - 1])
		{
			s = changeSwitch(s, i);
			count1++;
		}

		if (s2[i - 1] != res[i - 1])
		{
			s2 = changeSwitch(s2, i);
			count2++;
		}
	}

	if (s == res)
	{
		cout << count1 << "\n";
	}
	else if (s2 == res)
	{ 
		cout << count2 << "\n";
	}
	else
	{
		cout << "-1\n";
	}
	
	return 0;
}