#pragma warning(disable:4996)

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int MAX_N = 1000000;
int A[MAX_N + 1];
int cache[MAX_N + 1];
int indexCache[MAX_N + 1];

int LIS(int length) {
    int count = 0;

    for (int i = 1; i <= length; i++) {
        if (cache[count] < A[i]) {
            cache[count + 1] = A[i];
            indexCache[i] = count + 1;
            count++;
        }
        else {
            int lo = 0;
            int hi = count;

            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;

                if (cache[mid] >= A[i]) {
                    hi = mid;
                }
                else {
                    lo = mid;
                }
            }

            cache[hi] = A[i];
            indexCache[i] = hi;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    memset(cache, INT32_MAX, sizeof(cache));
    cache[0] = INT32_MIN;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    A[0] = 0;
    int lisIndex = LIS(N);

    cout << lisIndex << "\n";

    vector<int> lisList;

    for (int i = N; i > 0; i--) {
        if (indexCache[i] != lisIndex) continue;

        lisList.push_back(A[i]);
        lisIndex--;

        if (lisIndex == 0) {
            break;
        }
    }

    for (auto it = lisList.rbegin(); it != lisList.rend(); it++) {
        cout << *it << " ";
    }

    return 0;
}