#pragma warning(disable:4996)

#include <iostream>
#include<stdio.h>
#include<vector>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

bool isPossible(vector<int> houses, int dist, int channels) {
    int count = 1;
    int cur = *(houses.begin());

    for (auto it = houses.begin() + 1; it != houses.end(); it++) {
        if (((*it) - cur) >= dist) {
            count++;
            cur = *it;
        }

        if (count >= channels) {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;

    vector<int> houses;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }

    sort(houses.begin(), houses.end());
    int min = 1;
    int max = (*(houses.end() - 1)) - *(houses.begin());

    if (isPossible(houses, max, C)) {
        cout << max;
        return 0;
    }

    while (min + 1 < max) {
        int mid = (min + max) / 2;

        if (isPossible(houses, mid, C)) {
            min = mid;
        }
        else {
            max = mid;
        }
    }

    cout << min;

    return 0;
}