#include<stdio.h>
#include<stack>

using namespace std;

int main()
{

    int N;
    scanf("%d", &N);

    stack<long long> lls; 
    int maxVal = 0;
    for(int i = 0; i < N; i++)
    {
        long long in;
        scanf("%lld", &in);

        if(lls.empty())
        {
            lls.push(in);
        }
        else
        {
            long long temp = lls.top();
            if(temp > in)
            {
                int area=0;
                int count=0;
                while(temp != lls.top())
                {
                    area += lls.top();
                    lls.pop();
                    count++;
                }

                for(int i=0; i<count; i++)
                {
                    lls.push(in);
                }
            }
            lls.push(in);

            if (temp > maxVal) 
            {
                maxVal = temp;
            }
        }


    }

    return 0;
}