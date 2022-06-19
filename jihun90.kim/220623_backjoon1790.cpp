#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;

int N;
int k;

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

    int count = 0;
    int const KOO = 9;
    int digit = 0;
 
    int resultNum = 0;
    while(true)
    {
       if((count + (digit + 1) * (pow(10, digit) * KOO)) > k)
       {
            break;
       }
       count = count + (digit + 1) * (pow(10, digit) * KOO);
       resultNum = resultNum + (pow(10, digit) * KOO);  
       digit++; 
    }
   
    int rem = digit-1;
    if((k-count) > 0)
    {
        digit++;

        rem = (k - (count + 1)) % digit;
        int temp = (k-(count + 1)) / digit + 1;

        resultNum = resultNum + temp;
    }

    if(resultNum > N)
    {
        printf("-1");
    }
    else
    {
        char result = to_string(resultNum)[rem];
        printf("%c", result);
    }
    return 0;
}   
