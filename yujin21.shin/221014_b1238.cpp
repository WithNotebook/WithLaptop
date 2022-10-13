#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001
#define INF 987654321

int Length = 0;

int main() {
	int numStudent,road, meeting;
	cin >> numStudent >> road >> meeting;

	vector<vector<int>> arr(numStudent + 1, vector<int>(numStudent + 1, INF));
	for (int i = 1; i <= numStudent; i++)
		arr[i][i] = 0;
	int src,dst, weight;
	for (int i = 1; i <= road; i++) {
		cin >> src >> dst >> weight;
		arr[src][dst] = weight;
	}

	for (int k = 1; k <= numStudent; k++) {
		for (int i = 1; i <= numStudent; i++) {
			for (int j = 1; j <= numStudent; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= numStudent; i++) {
		if(answer < arr[i][meeting] + arr[meeting][i]){
			answer = arr[i][meeting] + arr[meeting][i];
		}
	}

	cout << answer;
}