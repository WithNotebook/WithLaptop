#include<stdio.h>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
    int N, C;
    vector<int> v;
    scanf("%d %d", &N, &C);

    for(int i = 0; i<N; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int start = 1;
    int end = v.back() - v.front();

    int mid;

    int result = 0;
    while(start <= end)
    {
        mid = (start + end) / 2;

        int wifiCount = 1;
        
        int lastIndex = v[0];
        for(int i = 1; i<N; i++)
        {
            if((lastIndex + mid) <= v[i])
            {
                lastIndex = v[i];
                wifiCount++;
            }
        }

        if(wifiCount >= C)
        {
            start = mid + 1;
            end = end;
            result = max(result, mid);
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