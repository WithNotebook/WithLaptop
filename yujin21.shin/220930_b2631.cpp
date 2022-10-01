#include <iostream>
#include <vector>

using namespace std;

int Length = 0;

int main() {
	int Num;
	cin >> Num;

	vector<int> arr(Num+1);
	int idx;
	for (int i = 1; i <= Num; i++) {
		cin >> idx;
		arr[i] = idx;
	}

	vector<int> DP(Num+1);
	for (int i = 1; i <= Num; i++) {
		DP[i] = 1;
		
		for(int j  = 1; j  <= i; j++) { 
			if(arr[j] < arr[i] && DP[i] < DP[j] + 1) { 
				DP[i] = DP[j] + 1; 
			}
		}
		if(Length < DP[i])
			Length = DP[i];
	}
	cout << Num- Length << endl;
}