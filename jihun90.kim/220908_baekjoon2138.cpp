#include<stdio.h>
#include<string>

using namespace std;

#define MAX 100001

int bulbCnt;
char source[MAX];
char dest[MAX];
char temp[MAX];

char flagOn(char bulb)
{
    return (bulb =='0') ? '1' : '0';
}

void switchOn(int index, char* bulbs)
{
    if(index-1 >= 0) bulbs[index-1] = flagOn(bulbs[index-1]);
    if((index >= 0) && index < bulbCnt) bulbs[index] = flagOn(bulbs[index]);
    if(index+1 < bulbCnt) bulbs[index+1] = flagOn(bulbs[index+1]);
}

int main()
{
    scanf("%d", &bulbCnt);

    scanf("%s", source);
    scanf("%s", dest);

    copy(source, source + bulbCnt, temp);
    
    int minCount = MAX;

    int count = 0;
    for(int i=1; i<bulbCnt; i++)
    {
        if(temp[i-1] != dest[i-1])
        {
            switchOn(i, temp);
            count++;
        }
    }
    if(string(temp) != string(dest)) count = MAX;
    minCount = min(minCount, count);

    copy(source, source + bulbCnt, temp);
    count = 0;
    switchOn(0, temp);
    count++;
    for(int i=1; i<bulbCnt; i++)
    {
        if(temp[i-1] != dest[i-1])
        {
            switchOn(i, temp);
            count++;
        }
    }
    if(string(temp) != string(dest)) count = MAX;
    minCount = min(minCount, count);

    if (minCount == MAX) minCount = -1;

    printf("%d", minCount);

    return 0;
}