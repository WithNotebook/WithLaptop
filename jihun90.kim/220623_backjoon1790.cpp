#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;

int N;
int k;
char result;

int getCharCount(int number)
{
    int count=0;
    
    int digit = to_string(number).length();
    int tempCalc = 0;
    for(int i=0; i<digit-1; i++)
    {
        tempCalc = ((i+1) * (9 * pow(10, i)));
        count = count + tempCalc;
    }
    tempCalc = ((number - (pow(10, digit-1)-1)) * (digit));
    count = count +tempCalc;

    return count;
}

int main()
{
    scanf("%d",&N);
    scanf("%d",&k);

    int count;
    bool flag = true;

    count=getCharCount(N);
    int i =0;
    int number = 0;
    int prevNumber = 0;
    if (count > k)
    {    
        number = 0;
        while(flag)
        { 
            prevNumber = number;
            number = number + 9 * pow(10, i);            
            count = getCharCount(number);
        
            if (count > k)
            {
                flag=false;
            }
            else
            {
                i++;
            }
        }
        int prevCount = getCharCount(prevNumber);
        int temp = (k - prevCount) / (i+1) + 1;
        int temp2 = (k - prevCount) % (i+1);
        
        int resultNumber = prevNumber + temp;
        result = to_string(resultNumber)[temp2-1];
            
        printf("%c\n", result);
    }
    else if(count == k)
    {
        result = to_string(N).back();
        printf("%c\n", result);
    }
    else
    {
        printf("-1\n");
    }



    return 0;
}   
