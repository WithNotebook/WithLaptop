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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        if (maxQueue.empty()) {
            maxQueue.push(temp);
            cout << temp << "\n";
            continue;
        }

        int curMedian = maxQueue.top();

        if (temp > curMedian) {
            minQueue.push(temp);

            if (minQueue.size() > maxQueue.size()) {
                int t = minQueue.top();
                minQueue.pop();
                maxQueue.push(t);
            }
        }
        else {
            maxQueue.push(temp);

            if (maxQueue.size() > minQueue.size() + 1) {
                int t = maxQueue.top();
                maxQueue.pop();
                minQueue.push(t);
            }
        }

        int median = maxQueue.top();
        cout << median << "\n";
    }

    return 0;
}