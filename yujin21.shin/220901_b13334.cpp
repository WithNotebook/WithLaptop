#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

struct INFO {
	int start;
	int end;
};

bool operator<(INFO a, INFO b) {
	if (a.end == b.end)
		a.start < b.start;
	return a.end < b.end;
}

int main() {
	int peopleNum, homeX, officeX, L;

	cin >> peopleNum;

	//입력
	vector<INFO> infoList;
	for (int i = 0; i < peopleNum; i++) {
		cin >> homeX >> officeX;
		if (homeX > officeX) infoList.push_back({ officeX, homeX });
		else infoList.push_back({ homeX, officeX });
	}

	sort(infoList.begin(), infoList.end());
	cin >> L;

	//구현
	int start=-100000001;
	int end = -1;
	int answer = 0;
	long long cnt=0;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < peopleNum; i++) {
		if (infoList[i].end - infoList[i].start > L) continue;

		if (infoList[i].start > start) {
			start = infoList[i].end - L;
			end = infoList[i].end;
		}

		if (infoList[i].end <= end)
			pq.push(infoList[i].start);

		while(pq.top() < start){
				pq.pop();
		}
		
		int answerVectorSize = pq.size();
		answer = max(answerVectorSize, answer);
	}
	cout << answer;
}