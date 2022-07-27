#include<iostream>
#include<vector>
using namespace std;

int ary[1001] = { 0, };
int lis[1001] = { 0, };
vector<int> v;
int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
	}

    int maxLength = 0;
    int maxLengthIndex = 0;
	for (int i = 0; i < N; i++)
	{
		lis[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (ary[j] < ary[i])
			{
                lis[i] = max(lis[i], lis[j] + 1);
			}
		}
        if (maxLength < lis[i]) {
            maxLength = lis[i];
            maxLengthIndex = i;
        }
	}

    for (int i = maxLengthIndex; i >= 1; i--) 
    {
        if (maxLength == lis[i]) 
        {
            v.push_back(ary[i]);
            maxLength--;
        }
    }

    int size = v.size();
    printf("%d\n", size);

    for (int i = 0; i < size; i++) {
        printf("%d ", v.back());
        v.pop_back();
    }

	return 0;
}