#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int> maxPq;
priority_queue<int, vector<int>, greater<int>> minPq;

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);

        if(maxPq.size() > minPq.size())
        {
            minPq.push(temp);
        }
        else
        {
            maxPq.push(temp);
        }

        if(!maxPq.empty() && !minPq.empty())
        {
            if(maxPq.top() > minPq.top())
            {
                int temp = maxPq.top();
                maxPq.pop();
                maxPq.push(minPq.top());
                minPq.pop();
                minPq.push(temp);
            }            
        }
        printf("%d\n", maxPq.top());
    }



    return 0;
}