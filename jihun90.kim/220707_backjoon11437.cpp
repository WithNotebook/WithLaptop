#include<stdio.h>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct node
{
    vector<node*> parents;
//    vector<node*> nodes;
    int cur = 0;
    int level = 0;
};

int _nodeCount;
int _parentsSize;

int LCA(node *tree, int a, int b)
{
    int aLevel = tree[a].level;
    int bLevel = tree[b].level;

    int aCur = tree[a].cur;
    int bCur = tree[b].cur;

    if(aLevel > bLevel)
    {
        aCur = tree[a].parents[aLevel - bLevel -1]->cur;
    }
    else if(aLevel < bLevel)
    {
        bCur = tree[b].parents[bLevel - aLevel - 1]->cur;
    }
    
    int index = 0;
    int prevACur = 0;
    int prevBCur = 0;
    bool isRecalc = false;
    while(tree[aCur].cur != tree[bCur].cur)
    {
        if (!isRecalc)
        {
            isRecalc = true;
        }
        prevACur = aCur;
        prevBCur = bCur;
        
        if(tree[aCur].parents.size() > pow(2,index))
        {
            aCur =tree[aCur].parents[pow(2, index)]->cur;
            bCur =tree[bCur].parents[pow(2, index)]->cur;
        }
    }

    index = 0;
    if (isRecalc)
    {
        aCur = prevACur;
        bCur = prevBCur;
    }
        
    while(tree[aCur].cur != tree[bCur].cur)
    {
        aCur =tree[aCur].parents[index]->cur;
        bCur =tree[bCur].parents[index]->cur;
    }

    return aCur;

}

void makeTree(node *tree, vector<pair<int, int>> *edgeList)
{   
    queue<int> index;
    index.push(1);
    int front = index.front();


    while(!index.empty())
    {
        front = index.front();
        for(int i = 0; i<edgeList->size(); i++)
        {
            pair<int, int> temp = edgeList->at(i);
            if (tree[front].cur == temp.first)
            {
                node tempNode;
                tempNode.parents.resize(_parentsSize+1);
                tempNode.cur = temp.second;
                tempNode.level = tree[front].level + 1;
                tempNode.parents[0] = &tree[front];
                for(int j=1; j < tree[front].parents.size(); j++)
                {
                    tempNode.parents[j] = tree[front].parents[j-1];
                }
 //               tree[front].nodes.push_back(&tempNode);
                tree[tempNode.cur] = tempNode;

                (*edgeList)[i].first = -1; //visited
                (*edgeList)[i].second = -1;

                index.push(tempNode.cur);
            }
            else if (tree[front].cur == temp.second)
            {
                node tempNode;
                tempNode.parents.resize(_parentsSize+1);
                tempNode.cur = temp.first;
                tempNode.level = tree[front].level + 1;
                tempNode.parents[0] = &tree[front];
                for(int j=1; j < tree[front].parents.size(); j++)
                {
                    tempNode.parents[j] = tree[front].parents[j-1];
                }
//                tree[front].nodes.push_back(&tempNode);
                tree[tempNode.cur] = tempNode;

                (*edgeList)[i].first = -1;
                (*edgeList)[i].second = -1;

                index.push(tempNode.cur);
            }

        }
        index.pop();
    }
}

int main()
{    
    vector<pair<int, int>> edgeList;
    vector<pair<int, int>> solList;
    
    scanf("%d", &_nodeCount);
    node* tree = new node[_nodeCount+1];

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
    
    _parentsSize = (int)log2(_nodeCount) + 1;

    for(int i = 0; i < _nodeCount+1; i++)
    {
        tree[i].parents.resize(_parentsSize);
    }

    int lev = 1;
    tree[1].level = lev;
    tree[1].cur = 1;
    makeTree(tree, &edgeList);

    for(int i = 0; i<solList.size(); i++)
    {
        int result = LCA(tree, solList[i].first, solList[i].second);
        printf("%d\n", result);
    }
    delete[] tree;

    return 0;
}