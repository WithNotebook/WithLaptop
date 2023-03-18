#include<stdio.h>
#include<string>
#include<map>
#include<string>

using namespace std;
    
#define F_MAX 100001

map<string, string> parent;
map<string, int> cnt;

using namespace std;

string findFunc(string str1)
{
    if(parent[str1] == str1) return str1;

    return (parent[str1] = findFunc(parent[str1]));
}

int unionFunc(string str1, string str2)
{
    string parent1 = findFunc(str1);
    string parent2 = findFunc(str2);

    if(parent1 != parent2)
    {
        parent[parent1] = parent2;
        cnt[parent2] = cnt[parent1] + cnt[parent2];

    }

    return cnt[parent2];
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tI=1; tI<=t; tI++)
    {

        int F;
        scanf("%d", &F);
        
        parent.clear();
        cnt.clear();

        for(int i=1; i<=F; i++)
        {
            char f1[20], f2[20];
            scanf("%s %s", f1, f2);

            if(!parent.count(f1))
            { 
                parent.insert(pair<string, string>(f1,f1)); 
                cnt.insert(pair<string, int>(f1, 1));
            }
            if(!parent.count(f2)) 
            {
                parent.insert(pair<string, string>(f2,f2));
                cnt.insert(pair<string, int>(f2, 1));
            }

            int res = unionFunc(f1, f2);
            printf("%d\n", res);
        }
    }

    return 0;
}