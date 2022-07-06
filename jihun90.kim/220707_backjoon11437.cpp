    #include<stdio.h>
    #include<vector>

    using namespace std;
    struct node
    {
        int parents;
        int current = 0;
        int level = 0;
        bool visited = 0;
    };

    #define MAX 50001
    typedef vector<vector<int>> edge;
    
    vector<vector<int>> _edgeList(MAX);
    vector<node> _tree(MAX);

    int LCA(int a, int b)
    {
        int aLevel = _tree[a].level;
        int bLevel = _tree[b].level;
        
        int aCur = _tree[a].current;
        int bCur = _tree[b].current;

        if (aLevel > bLevel)
        {
            while (aLevel != bLevel)
            {
                aCur = _tree[aCur].parents;
                aLevel = _tree[aCur].level;
            }
            
        } 
        else if(aLevel < bLevel)
        {
            while (aLevel != bLevel)
            {
                bCur = _tree[bCur].parents;
                bLevel = _tree[bCur].level;
            }
        }

        while (aCur != bCur)
        {
            aCur = _tree[aCur].parents;
            bCur = _tree[bCur].parents;
        }

        return aCur;
    }

    void makeTreeDFS(int cur, int parents)
    {
        _tree[cur].current = cur;
        _tree[cur].parents = parents;
        _tree[cur].level = _tree[parents].level + 1;
        _tree[cur].visited = true;

        for(vector<int>::iterator it=_edgeList[cur].begin(); it!= _edgeList[cur].end(); it++)
        {
            int next = (*it); 
            if(!_tree[next].visited)
            {
                makeTreeDFS(next, cur);
            }
        }
    }

    int main()
    {
        int nodeCount;
        scanf("%d", &nodeCount);

        for(int i = 1; i < nodeCount; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            _edgeList[a].push_back(b);
            _edgeList[b].push_back(a);
        }

        makeTreeDFS(1, 0);

        int cmdCount;
        scanf("%d", &cmdCount);
        for(int i=0; i<cmdCount; i++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            printf("%d\n", LCA(a ,b));
        }
        return 1;
    }