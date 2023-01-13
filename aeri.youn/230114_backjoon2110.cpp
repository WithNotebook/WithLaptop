#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> home;

int main()
{
    int N, C;
    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        home.push_back(temp);
    }
    sort(home.begin(), home.end());

    int start = 0;
    int end = home[N-1];

    int result = 0;
    while (start <= end)
    {
        int count = 1;

        int mid = (start + end) / 2;
        int prev = home[0];
        for (int i = 1; i < N; i++)
        {
            if ((home[i] - prev) >= mid)
            {
                count++;
                prev = home[i];
            }
        }
        if (count >= C)
        {
            result = max(result, mid);
            start = mid + 1;
            end = end;
        }
        else
        {
            start = start;
            end = mid - 1;
        }
    }
    printf("%d\n", result);

    return 0;
}
