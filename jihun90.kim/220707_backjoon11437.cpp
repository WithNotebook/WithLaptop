#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

struct node
{
    node* parents = nullptr;
    vector<node*> nodes;
    int cur = 0;
    int level = 0;
};

int _nodeCount;

int LCA(node *tree, int a, int b)
{
    int aCur = tree[a].cur;
    int bCur = tree[b].cur;

    while (aCur != bCur)
    {
        int aLevel = tree[aCur].level;
        int bLevel = tree[bCur].level;

        if(aLevel > bLevel)
        {
            aCur = tree[aCur].parents->cur;
        }
        else if(aLevel < bLevel)
        {
            bCur = tree[bCur].parents->cur;
        }
        else
        {   
            aCur = tree[aCur].parents->cur;
            bCur = tree[bCur].parents->cur;
        }
    }
    
    return aCur;
}

void makeTree(node *tree, vector<pair<int, int>> *edgeList)
{   
    int lev = 1;
    tree[1].parents = &tree[0];
    tree[1].level = lev;
    tree[1].cur = 1;
    
    queue<int> index;
    index.push(1);
    while(!index.empty())
    {
        int front = index.front();
        for(vector<pair<int,int>>::iterator it = edgeList->begin(); it != edgeList->end(); it++)
        {
            pair<int, int> temp = *it;
            
            if(tree[front].cur == temp.first)
            {
                node* parentsNode = tree[temp.second].parents;
                if((parentsNode == nullptr))
                {
                    node tempNode;
                    tempNode.cur = temp.second;
                    tempNode.parents = &tree[front];
                    tempNode.level = lev+1;
                    tree[front].nodes.push_back(&tempNode);
                    tree[temp.second] = tempNode;
                    index.push(temp.second);
                }       
            }       
            else if(tree[front].cur == temp.second)
            {
                node* parentsNode = tree[temp.first].parents;
                if((parentsNode == nullptr))
                {
                    node tempNode;
                    tempNode.cur = temp.first;
                    tempNode.parents = &tree[front];
                    tempNode.level = lev+1;
                    tree[front].nodes.push_back(&tempNode);
                    tree[temp.first] = tempNode;
                    index.push(temp.first);
                }
            }
        }
        index.pop();
        lev++;
    }
}

int main()
{    
    vector<pair<int, int>> edgeList;
    vector<pair<int, int>> solList;
    
    scanf("%d", &_nodeCount);
    node tree[_nodeCount+1];

    for(int i = 0; i < _nodeCount-1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edgeList.emplace_back(a, b);
    }

    int solCount;
    scanf("%d", &solCount);
    for(int i = 0; i < solCount; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        solList.emplace_back(a, b);
    }

    makeTree(tree, &edgeList);

    for(int i = 0; i<solList.size(); i++)
    {
        int result = LCA(tree, solList[i].first, solList[i].second);
        printf("%d\n", result);
    }
    return 0;
}