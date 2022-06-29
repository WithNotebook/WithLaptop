    #include<stdio.h>
    #include<list>
    #include<vector>
    #include<queue>
    #include<cmath>

    using namespace std;

    list<int> _result;
    int _cityCount = 0;
    int _startPos = 0;
    int _endPos = 0;
    int _resultMax;

    struct town
    {
        int startPos = 0;
        int endPos = 0;
        int adj = 0;
    };

    int main()
    {
        scanf("%d", &_cityCount);

        int cmdCount = 0;
        vector<town> townForward[_cityCount+1];
        vector<town> townReverse[_cityCount+1];
        int max1[_cityCount+1];
        int max2[_cityCount+1];
        int inDegree[_cityCount+1];
        int tempMax[_cityCount+1];
        int tempMax2[_cityCount+1];
        int outDegree[_cityCount +1];

        for(int i= 0; i<=_cityCount; i++)
        {
            inDegree[i] = 0;
            outDegree[i]  = 0;
            max1[i] = 0;
            max2[i] = 0;
            tempMax[i] = 0;
            tempMax2[i] = 0;
        }
        
        scanf("%d", &cmdCount);
        for(int i = 0; i < cmdCount; i++)
        {
            int cur;
            int next;
            int adj;
            scanf("%d %d %d", &cur, &next, &adj);
            town temp;
            temp.startPos = cur;
            temp.endPos = next;
            temp.adj = adj;
            townForward[cur].push_back(temp);
            temp.startPos = next;
            temp.endPos = cur;
            temp.adj = adj;            
            townReverse[next].push_back(temp);
            inDegree[next]++;
            outDegree[cur]++;
        }
        
        scanf("%d %d", &_startPos, &_endPos);
        
        queue<int> q;
        max1[_startPos] = 0;
        
        q.push(_startPos);
        while(!q.empty())
        {
            int front = q.front();
            if(inDegree[front] == 0)
            {
                q.pop();
            }

            for(int next=0; next<townForward[front].size(); next++)
            {
                if(!townForward[front].empty())
                {
                    town temp = townForward[front].at(next);
                
                    if(temp.adj > 0)
                    {
                        tempMax[temp.endPos] = max(temp.adj + max1[temp.startPos], tempMax[temp.endPos]);

                        inDegree[temp.endPos]--;
                        if(inDegree[temp.endPos] == 0)
                        {   
                            max1[temp.endPos] = tempMax[temp.endPos];
                            q.push(temp.endPos);
                        }
                    }
                }
            }
        }
        _resultMax = max1[_endPos];

        queue<int> q2;
        q2.push(_endPos);
        queue<pair<int,int>> result;
        while(!q2.empty())
        {
            int front = q2.front();

            if(outDegree[front] == 0)
            {
                q2.pop();
            }

            for(int next = 0; next < townReverse[front].size(); next++)
            {   
                if(!townReverse[front].empty())
                {
                    town temp = townReverse[front].at(next);

                    if(temp.adj > 0)
                    {
                        tempMax2[temp.endPos] = max(max2[temp.startPos] + temp.adj ,tempMax2[temp.endPos]);
                        outDegree[temp.endPos]--;
                        if(outDegree[temp.endPos] == 0)
                        {
                            max2[temp.endPos] = tempMax2[temp.endPos];
                            q2.push(temp.endPos);
                        }
                    }
                }
            }


        }

        bool visited[_cityCount][_cityCount];
        fill(&visited[0][0], &visited[_cityCount-1][_cityCount], false);
        for(int front = 0; front <= _cityCount; front++)
        {
            if(!townReverse[front].empty())
            {
                for(int next=0; next < townReverse[front].size(); next++)
                {
                    town temp = townReverse[front].at(next);
                    
                    if(temp.adj > 0)
                    {
                        if(
                              (((max2[temp.startPos] + temp.adj) + max1[temp.endPos]) == max1[_endPos] )
                              )
                          {
                              if(!visited[temp.startPos][temp.endPos])
                              {
                                  result.emplace(temp.startPos, temp.endPos);
                              }
                          }
                    }

                }
            }
        }

        printf("%d\n", _resultMax);
        int count = result.size();
        printf("%d", count);
        return 0;
    };
