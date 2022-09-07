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

int N;
string cur, target, copiedCur;

bool compare(int i) {
    return cur.at(i) == target.at(i);
}

void changeCur(int i) {
    cur[i] = (cur.at(i) == '0') ? '1' : '0';
}

void putOnSwitch(int i) {
    if (i == 0) {
        changeCur(i);
        changeCur(i + 1);
    }
    else if (i == N - 1) {
        changeCur(i - 1);
        changeCur(i);
    }
    else {
        changeCur(i - 1);
        changeCur(i);
        changeCur(i + 1);
    }
}

int getCount() {
    int count = 0;

    for (int i = 1; i < N; i++) {
        if (!compare(i - 1)) {
            putOnSwitch(i);
            count++;
        }
    }

    return count;
}

bool isPossible() {
    for (int i = 0; i < N; i++) {
        if (!compare(i)) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;    
    cin >> cur >> target;
    copiedCur = cur;    

    int offCount = getCount();
    bool offPossible = isPossible();
    
    cur = copiedCur;
    putOnSwitch(0);
    int onCount = 1 + getCount();
    bool onPossible = isPossible();

    if ((!offPossible) && (!onPossible)) {
        cout << -1;
    }
    else if (!offPossible) {
        cout << onCount;
    }
    else if (!onPossible) {
        cout << offCount;
    }
    else {
        cout << min(offCount, onCount);
    }

    return 0;
}