#include <iostream>
#include <algorithm>
#include <string>

#define MAX 987654321

using namespace std;

int lightNum;

void lightOn(string& temp,int cur) {
		if (cur > 0) temp[cur - 1] = (temp[cur - 1] == '0') ? '1' : '0';
		temp[cur] = (temp[cur] == '0') ? '1' : '0';
		if (cur < lightNum - 1) temp[cur + 1] = (temp[cur + 1] == '0') ? '1' : '0';
}

int main() {
	
	string curLight, wantedLight, temp;
	cin >> lightNum;
	cin >> curLight >> wantedLight;

	int cnt = 0, answer=MAX;
	for (int i = 1; i <= 2; i++) {
		temp = curLight;
		cnt = 0;
		if (i == 1) {
			temp[0] = (temp[0] == '0') ? '1' : '0';
			temp[1] = (temp[1] == '0') ? '1' : '0';
			cnt++;
		}
		for (int j = 1; j < lightNum; j++) {
			if (temp[j - 1] != wantedLight[j - 1]){
				lightOn(temp,j);
				cnt++;
			}
			if (temp == wantedLight) {
				answer = min(answer, cnt);
				break;
			}
		}
		
	}

	if (answer != MAX) cout << answer << "\n";
	else cout << -1 << "\n";
}