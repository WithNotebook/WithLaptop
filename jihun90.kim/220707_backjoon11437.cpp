    #include<stdio.h>
    #include<vector>

    using namespace std;
    struct node
    {
        node* parents;
        int current = 0;
        int level = 0;
        bool visible = 0;
    };

    typedef vector<vector<int>> edge;

    int LCA(node *tree,int a, int b)
    {
        int aLevel = tree[a].level;
        int bLevel = tree[b].level;
        
        int aCur = tree[a].current;
        int bCur = tree[b].current;

        if (aLevel > bLevel)
        {
            while (aLevel != bLevel)
            {
                aCur = tree[aCur].parents->current;
                aLevel = tree[aCur].level;
            }
            
        } 
        else if(aLevel < bLevel)
        {
            while (aLevel != bLevel)
            {
                bCur = tree[bCur].parents->current;
                bLevel = tree[bCur].level;
            }
        }

        while (aCur != bCur)
        {
            aCur = tree[aCur].parents->current;
            bCur = tree[bCur].parents->current;
        }

        return aCur;
    }

    void makeTree(node *tree, edge *edgeList, int nodeCount)
    {
        for(int index = 1; index < nodeCount; index++)
        {
            for(int nextNum = 0; nextNum < (*edgeList)[index].size(); nextNum++)
            {
                int next = (*edgeList)[index][nextNum]; 
                if(tree[next].visible)
                {
                    continue;
                }
                tree[next].current = next;
                tree[next].level= tree[index].level+1;
                tree[next].parents = &tree[index];
                tree[next].visible = true;
            }
        }
    }


    int backjoon11437()
    {
        int nodeCount;
        scanf("%d", &nodeCount);

        vector<vector<int>> edgeList(nodeCount+1);
        node *tree = new node[nodeCount+1];

        for(int i = 1; i < nodeCount; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            edgeList[a].push_back(b);
            edgeList[b].push_back(a);
        }

        tree[1].current = 1;
        tree[1].level = 1;
        tree[1].visible = true;
        makeTree(tree, &edgeList, nodeCount);

        int cmdCount;
        scanf("%d", &cmdCount);
        for(int i=0; i<cmdCount; i++)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            printf("%d\n", LCA(tree ,a ,b));
        }


        delete[] tree;

        return 1;
    }