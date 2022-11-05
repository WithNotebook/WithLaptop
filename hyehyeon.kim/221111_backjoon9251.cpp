#pragma warning(disable:4996)

#include <iostream>
#include<stdio.h>
#include<vector>
#include <cstring>

using namespace std;

int cache[1001][1001];
string A, B;
int ALength, BLength;

int findLCS(int a, int b) {
    int& ret = cache[a][b];

    if ((a == ALength) || (b == BLength)) {
        return 0;
    }

    if (ret != -1) {
        return ret;
    }

    int result = 0;

    if (A.at(a) == B.at(b)) {
        return (ret = 1 + findLCS(a + 1, b + 1));
    }

    result = max(findLCS(a + 1, b), findLCS(a, b + 1));

    return (ret = result);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    ALength = A.length();
    BLength = B.length();

    memset(cache, -1, sizeof(cache));

    cout << findLCS(0, 0);

    return 0;
}