#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int T[6] = { 0, };
	int P[1001] = { 0, };

	cin >> N;
	int workTime, pay;
	int answer = -1;
	for (int i = 1; i <= N; i++) {
		cin >> workTime >> pay;
		
		if(i+workTime<=N+1)P[i] += pay;
		for(int j=i+workTime;j<=N+1;j++){
			P[j] = max(P[j], P[i]);
		}
		answer = max(answer, P[i]);
	}
	cout << answer;

}