#include<iostream>
using namespace std;

int r[1000001];
int n, m;

int getParent(int num) {
	if (r[num] == num)
		return num;
	else{
		return r[num] = getParent(r[num]);
	}
}

void join(int a, int b) {
	r[getParent(a)] = getParent(b);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		r[i] = i;
	}

	while (m--) {
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 0) {
			join(a, b);
		}
		else {
			if (getParent(a) == getParent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
