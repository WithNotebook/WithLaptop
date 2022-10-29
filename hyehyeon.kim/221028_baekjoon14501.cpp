#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 15;

int N;

int workingDays[MAX_N + 1];
int pays[MAX_N + 1];

int cache[MAX_N + 1][2];

int FindMaximumPay(int curDay, int isWorking) {

	if (isWorking == 1) {
		if (curDay + workingDays[curDay] - 1 > N) {
			return 0;
		}
	}
	else {
		if (curDay > N) {
			return 0;
		}
	}

	int& ret = cache[curDay][isWorking];

	if (ret != -1) {
		return ret;
	}

	int maximumPay = 0;
	int nextDay = 0;

	if (isWorking == 1) {
		nextDay = curDay + workingDays[curDay];
		maximumPay += pays[curDay];
	}
	else {
		nextDay = curDay + 1;
	}

	maximumPay += max(FindMaximumPay(nextDay, 0), FindMaximumPay(nextDay, 1));

	return (ret = maximumPay);
}

int main() {

	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int day, pay;

		scanf("%d %d", &day, &pay);

		workingDays[n] = day;
		pays[n] = pay;

		cache[n][0] = -1;
		cache[n][1] = -1;
	}

	int result = max(FindMaximumPay(1, 0), FindMaximumPay(1, 1));

	printf("%d\n", result);

	return 0;
}
