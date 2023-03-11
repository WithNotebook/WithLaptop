#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
#define TEXT_MAX 4002

int cnt[TEXT_MAX][TEXT_MAX];

int main()
{
    char str1[TEXT_MAX], str2[TEXT_MAX];
    
    memset(&str1, 0, sizeof(char) * TEXT_MAX);
    memset(&str1, 0, sizeof(char) * TEXT_MAX);

    scanf("%s", &str1[1]);
    scanf("%s", &str2[1]);

    for(int i=0; i<TEXT_MAX; i++)
    {
        for(int j=0; j<TEXT_MAX; j++)
        {
            cnt[i][j] = 0;
        }
    }

    int res = 0;
    for(int i=1; i<TEXT_MAX; i++)
    {
        if(str1[i] == '\0') break;
        for(int j=1; j<TEXT_MAX; j++)
        {
            if(str2[j] == '\0') break;
            if(str1[i] == str2[j]) 
            {
                cnt[i][j] = cnt[i-1][j-1] + 1;
                res = max(cnt[i][j], res);
            }
        }
    }

    printf("%d\n", res);

    return 0;
}