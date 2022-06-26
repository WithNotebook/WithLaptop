#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

struct road {
    int start;
    int end;
    int time;

    bool operator < (const road& other) const {
        if (start < other.start) {
            return true;
        }
        else if (start > other.start) {
            return false;
        }

        if (end < other.end) {
            return true;
        }
        else if (end > other.end) {
            return false;
        }

        return (time < other.time);
    }
};

vector<road> world[10001];
vector<road> isVisited;
set<road> maxRoads;

int startCity, endCity;
int curMaxTime = -1;

void findMaxMan(int cur, int maxTime) {
    if (cur == endCity) {
        if (maxTime > curMaxTime) {
            maxRoads.clear();
        }

        if (maxTime >= curMaxTime) {
            vector<road>::iterator it = isVisited.begin();

            for (it; it != isVisited.end(); it++) {
                maxRoads.insert(*it);
            }
            curMaxTime = maxTime;
        }

        return;
    }

    vector<road>::iterator it = world[cur].begin();
    int result = -1;

    for (it; it != world[cur].end(); it++) {
        isVisited.push_back(*it);
        
        findMaxMan((*it).end, maxTime + (*it).time);
        
        isVisited.pop_back();
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);       

    int N, M;
    cin >> N >> M;    

    isVisited.reserve(M);

    for (int m = 0; m < M; m++) {
        int start, end, time;
        cin >> start >> end >> time;

        world[start].push_back(road{ start, end, time});
    }
    
    cin >> startCity >> endCity;

    findMaxMan(startCity, 0);

    cout << curMaxTime << "\n";
    cout << maxRoads.size() << "\n";

    return 0;
}