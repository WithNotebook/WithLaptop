#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parent[101];
vector<int> v[101];
vector<int> group[101];
vector<int> res;
int find(int n)
{
	if (parent[n] == n)
	{
		return n;
	}
	int parentTemp = find(parent[n]);
	return parent[n] = parentTemp;
}

void merge(int a, int b)
{
	int parentA = find(a);
	int parentB = find(b);

	if (parentA == parentB) return;

	parent[b] = parentA;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		merge(a, b);
	}
	
	//그룹끼리 모아놓은 벡터
	for (int i = 1; i <= N; i++)
	{
		if (parent != 0)
		{
			group[parent[i]].push_back(i);
		}
	}

	int max = 0, firstMember = 0;
	for (int i = 1; i <= N; i++)
	{
		max = 0;
		for (int j = 0; j < group[i].size(); j++)
		{
			if (v[group[i][j]].size() == 0)
			{ //혼자 있는 그룹은 본인이 대표
				firstMember = group[i][j];
			}
			else if (max < v[group[i][j]].size())
			{ //그룹원들과 가장 많이 연결되어 있는 사람이 대표
				max = v[group[i][j]].size();
				firstMember = group[i][j];
			}
		}
		if (group[i].size() > 0)
		{ //해당 그룹의 대표를 res 벡터에 넣어줌
			res.push_back(firstMember);
		}
	}
	//대표들을 모아놓은 벡터를 오름차순으로 정렬
	sort(res.begin(), res.end());

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
	{
		printf("%d\n", res[i]);
	}
	
	return 0;
}