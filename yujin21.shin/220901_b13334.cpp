#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct INFO {
	int start;
	int end;
};

bool operator<(INFO a, INFO b) {
	if (a.start == b.start)
		a.end < b.end;
	return a.start < b.start;
}

long long distance(int start, int end) {
	return end - start;
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
	int start=0, end=0;
	long long answer = 0;
	long long cnt=0;
	vector<bool> visited(peopleNum);
	for (int i = 0; i < peopleNum; i++) {
		start = infoList[i].start;
		cnt = 0;

		if ((peopleNum - i + 1) <= answer)	break;
		else if (visited[peopleNum-1]) break;

		if(distance(infoList[i].start, infoList[i].end) <= L )	cnt++;
		for (int j = i+1; j < peopleNum; j++)
		{
			if (distance(start, infoList[j].start) >= L) {
				break;
			}
			else {
				if (distance(start, infoList[j].end) <= L) {
					cnt++;
					visited[j] = true;
				}
			}
		}
		answer = max(cnt, answer);
	}
	cout << answer;
}