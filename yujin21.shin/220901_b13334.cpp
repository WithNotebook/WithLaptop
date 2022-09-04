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
		// 철로 길이보다 큰건 PASS
		if (infoList[i].end - infoList[i].start > L) continue;
		
		// 현재 start 지점 갱신
		if (infoList[i].start > start) {
			start = infoList[i].end - L;
			end = infoList[i].end;
		}
		
		// 철로 길이 안에 들어오는 건  PUSH
		if (infoList[i].end <= end)
			pq.push(infoList[i].start);
		
		// start 지점을 갱신했으므로 배열도 갱신
		while(pq.top() < start){
				pq.pop();
		}
		
		int answerVectorSize = pq.size();
		answer = max(answerVectorSize, answer);
	}
	cout << answer;
}