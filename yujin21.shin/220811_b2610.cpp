#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 100000

int N, M;
vector<int> familyTree;

int findMyParent(vector<int>& v, int a) {
	if (v[a] == a) {
		return a;
	}
	else {
		return findMyParent(v, v[a]);
	}
}

void setFamily(vector<int>& v, int a, int b) {
	int pA = findMyParent(v, a);
	int pB = findMyParent(v, b);
	
		if (pA < pB) {
			v[pB] = pA;
		}
		else if (pA > pB) {
			v[pA] = pB;
		}
}

bool areWeFamily(vector<int>& v, int a, int b) {
	if (findMyParent(v, a) == findMyParent(v, b)) {
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	scanf("%d %d", &N, &M);

	familyTree.resize(N + 1);
	int arr[101][101];
	vector<pair<int, int>> Leader(N + 1);//{idx, Friends}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = INF;
			familyTree[i] = i;
			arr[i][i] = 0;
			Leader[i] = {  -1,INF };
		}
	}

	int a, b;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
		setFamily(familyTree, a, b);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j])arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	

	for (int i = 1; i <= N; i++) {
		int p1 = findMyParent(familyTree, i), max = -1;
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == INF)continue;
			if (max < arr[i][j])
				max = arr[i][j];
		}
		if (Leader[p1].second > max)
			Leader[p1].second = max, Leader[p1].first = i;
	}

	vector<int> answer;
	for (int i = 1; i <= N; i++) {
		if (Leader[i].first != -1) {
			answer.push_back(Leader[i].first);
		}
	}

	int answerSZ = answer.size();
	printf("%d\n", answerSZ);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		printf("%d\n", answer[i]);
}