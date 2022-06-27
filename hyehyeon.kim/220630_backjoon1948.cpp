#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct road {
    int end;
    int time;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);       

    int N, M;
    int startCity, endCity;    
    vector<road> world[10001];
    vector<road> reverseWorld[10001];
    long long maxTimes[10001] = { 0, };
    queue<int> cityQueue;

    cin >> N >> M;    

    for (int m = 0; m < M; m++) {
        int start, end, time;
        cin >> start >> end >> time;

        world[start].push_back(road{ end, time});
        reverseWorld[end].push_back(road{ start, time });
    }
    
    cin >> startCity >> endCity;

    cityQueue.push(startCity);

    while (!cityQueue.empty()) {
        int curCity = cityQueue.front();
        cityQueue.pop();

        vector<road>::iterator it = world[curCity].begin();

        for (it; it != world[curCity].end(); it++) {
            int nextCity = (*it).end;
            int curTime = (*it).time;

            if (maxTimes[nextCity] < maxTimes[curCity] + curTime) {
                maxTimes[nextCity] = maxTimes[curCity] + curTime;
                cityQueue.push(nextCity);
            }
        }
    }

    cityQueue.push(endCity);
    int count = 0;

    vector<bool> isVisited(N + 1);

    while (!cityQueue.empty()) {
        int curCity = cityQueue.front();
        cityQueue.pop();        

        vector<road>::iterator it = reverseWorld[curCity].begin();

        for (it; it != reverseWorld[curCity].end(); it++) {
            int nextCity = (*it).end;
            int curTime = (*it).time;

            if (isVisited[curCity]) {
                continue;
            }
            
            if (maxTimes[nextCity] + curTime == maxTimes[curCity]) {
                count++;
                cityQueue.push(nextCity);
            }
        }

        isVisited[curCity] = true;
    }

    cout << maxTimes[endCity] << "\n";
    cout << count << "\n";

    return 0;
}