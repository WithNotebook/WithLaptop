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

const int MAX_N = 100000;
long long heights[MAX_N];
int segmentTree[MAX_N * 4];

int makeSegmentTree(int parent, int start, int end) {
    if (start == end) {
        return segmentTree[parent] = start;
    }

    int mid = (start + end) / 2;

    int left = makeSegmentTree(2 * parent, start, mid);
    int right = makeSegmentTree(2 * parent + 1, mid + 1, end);

    if (heights[left] <= heights[right]) {
        return segmentTree[parent] = left;
    }
    else {
        return segmentTree[parent] = right;
    }
}

int findMinIndex(int parent, int start, int end, int left, int right) {
    if (end < left || start > right) return -1;
    if (left <= start && right >= end) return segmentTree[parent];

    int mid = (start + end) / 2;

    int leftIndex = findMinIndex(2 * parent, start, mid, left, right);
    int rightIndex = findMinIndex(2 * parent + 1, mid + 1, end, left, right);

    if (leftIndex == -1) return rightIndex;
    else if (rightIndex == -1) return leftIndex;
    else return heights[leftIndex] <= heights[rightIndex] ? leftIndex : rightIndex;
}

long long getMaxArea(int N, long long lo, long long hi) {
    if (lo > hi) return -1;

    long long minIndex = findMinIndex(1, 0, N - 1, lo, hi);
    long long result = max(result, ((long long)heights[minIndex]) * (hi - lo + 1));

    result = max(result, getMaxArea(N, lo, minIndex - 1));
    result = max(result, getMaxArea(N, minIndex + 1, hi));

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    segmentTree[0] = -1;
    makeSegmentTree(1, 0, N - 1);
    long long result = getMaxArea(N, 0, (long long)N - 1);

    cout << result << "\n";

    return 0;
}