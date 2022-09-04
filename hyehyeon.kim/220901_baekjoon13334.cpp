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

struct person {
    int start;
    int end;
};

struct compareEnd {
    bool operator() (const person& a, const person& b) {
        if (a.end == b.end) {
            return a.start > b.start;
        }

        return a.end > b.end;
    }
};

struct compareStart {
    bool operator() (const person& a, const person& b) {
        if (a.start == b.start) {
            return a.end > b.end;
        }

        return a.start > b.start;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int minStart = INT32_MAX;
    int maxEnd = INT32_MIN;

    priority_queue<person, vector<person>, compareEnd> pq;

    for (int i = 0; i < n; i++) {
        int h, o;

        cin >> h >> o;

        int start = min(h, o);
        int end = max(h, o);

        pq.push({ start, end });

        minStart = min(minStart, start);
        maxEnd = max(maxEnd, end);
    }

    int d;
    cin >> d;

    int curStart = minStart;
    int curEnd = minStart + d;

    int result = 0;

    priority_queue<person, vector<person>, compareStart> blessed;

    while (curEnd <= maxEnd) {
        while (!pq.empty()) {
            person cur = pq.top();
            
            if (cur.end > curEnd) {
                break;
            }

            if (cur.start >= curStart) {
                blessed.push(cur);
            }

            pq.pop();
        }

        while (!blessed.empty()) {
            person cur = blessed.top();

            if (cur.start >= curStart) {
                break;
            }

            blessed.pop();
        }

        if (result < blessed.size()) {
            result = blessed.size();
        }

        curStart++;
        curEnd++;
    }

    cout << result;

    return 0;
}