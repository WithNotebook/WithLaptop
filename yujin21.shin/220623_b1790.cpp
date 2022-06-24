#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

int main() {
	int N, k;

	scanf("%d %d", &N, &k);
	int zarisu = 1;
	int zarisu10 = pow(10, zarisu);
	string lastString="";
	int answer = -1;

	for (int i = 1; i <= N; i++) {

		if (i % zarisu10 ==0) {
			zarisu++;
			zarisu10 = pow(10, zarisu);
		}
		if (k>0 && k <= zarisu) {
			k--;
			lastString = to_string(i);
			answer = lastString[k] - '0';
			break;
		}
		else {
			k -= zarisu;
		}

	}

	printf("%d", answer);
}