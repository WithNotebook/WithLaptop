    #include<stdio.h>
    #include<algorithm>
    #include<vector>

    using namespace std;

    int _N, _M;
    int _parents[101];
    int _rank[101];
    int _graph[101][101];

    void init()
    {
        for(int i = 0; i<_N; i++)
        {
            for(int j=0; j<_N; j++)
            {
                _graph[i][j] = 99999;
                if(i==j)
                {
                    _graph[i][j] = 0;
                }
            }
            _parents[i] = i;
            _rank[i] = 1;
        }
    }

    void floyd()
    {
        for(int k=1; k<_N; k++)
        {
            for(int i =1; i<_N; i++)
            {
                for(int j=1; j<_N; j++)
                {
                    _graph[i][j] = min(_graph[i][j], _graph[i][k] + _graph[k][j]);
                }
            }
        }
    }

    int find(int x)
    {
        if(_parents[x] == x) return x;
        return _parents[x] = find(_parents[x]);
    }

    vector<int> findCommonParents(int parents)
    {
        vector<int> commonParents;
        for(int i=1; i<_N; i++)
        {
            if (parents==_parents[i])
            {
                commonParents.push_back(i);
            }
        }
        return commonParents;
    }

    void unionValue(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (_rank[a] > _rank[b]) swap(a,b);
        if (_rank[a] == _rank[b]) _rank[b]++;
        _parents[b] = a;
    }

    int main()
    {
        scanf("%d", &_N);
        scanf("%d", &_M);
        _N = _N+1;

        init();

        for(int i=0; i<_M; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            unionValue(a, b);
    
            _graph[a][b] = 1;
            _graph[b][a] = 1;       
        }

        floyd();


        vector<int> result;
        for(int i=1; i<_N; i++)
        {

            vector<int> commonParents = findCommonParents(i);
            if(commonParents.empty())
            {
                continue;
            }

            int minOfmax = 99999;
            int ret = 0;
            for(vector<int>::iterator it = commonParents.begin(); it!=commonParents.end(); it++)
            {
                int maxTime = 0;
                for(int vindex=0; vindex<commonParents.size(); vindex++)
                {
                    int time = _graph[*it][commonParents[vindex]];
                    if(maxTime < time )
                    {
                        maxTime = time;
                    }
                }

                if(minOfmax > maxTime)
                {
                    minOfmax = maxTime;
                    ret = *it;
                }
            }
            result.push_back(ret);
        }

        sort(result.begin(), result.end());
        printf("%d\n", result.size());
        for(vector<int>::iterator it=result.begin(); it!=result.end(); it++)
        {
            printf("%d\n", *it);
        }

        return 0;
    }