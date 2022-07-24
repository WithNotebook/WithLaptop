#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

struct seat
{
	int curSeat;
	int nextSeat;
	int distance;

	seat(int c, int n, int d)
	{
		curSeat = c;
		nextSeat = n;
		distance = d;
	}
};
vector<seat> v;
vector<int> moveSeat;
bool comp(seat a, seat b)
{
	if (a.distance == b.distance)
	{
		return a.nextSeat > b.nextSeat;
	}
	else
	{
		return a.distance < b.distance;
	}
}

int main()
{
	int T, N;
	long long candyCount = 0;

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		candyCount = 0;
		v.clear();
		moveSeat.clear();
		v.push_back(seat(200000, 200000, 0));
		int s;
		for (int i = 1; i <= N; i++)
		{
			cin >> s;
			v.push_back(seat(i, s, abs(i - s)));
		}

		sort(v.begin(), v.end(), comp); //이사갈 자리가 가까운 -> 먼 순서로 정렬

		//이사 가는 길에 자리에 앉아있는 사람이 있으면 사탕을 받는다.
		
		for (int i = 1; i <= N; i++)
		{
			if (moveSeat.empty())
			{
				//받는 사탕 없음
				//이사가기
				moveSeat.push_back(v[i].nextSeat);
			}
			else if (moveSeat[moveSeat.size() - 1] < v[i].nextSeat)
			{
				//맨 마지막으로 이사할 때
				int curSeatIndex = lower_bound(moveSeat.begin(), moveSeat.end(), v[i].curSeat) - moveSeat.begin();
				candyCount += abs((int)moveSeat.size() - curSeatIndex); 
				moveSeat.push_back(v[i].nextSeat);
			}
			else if (moveSeat[moveSeat.size() - 1] < v[i].curSeat)
			{
				//맨 마지막에서 이사할 때
				int nextSeatIndex = lower_bound(moveSeat.begin(), moveSeat.end(), v[i].nextSeat) - moveSeat.begin();
				candyCount += abs((int)moveSeat.size() - nextSeatIndex);
				moveSeat.insert(moveSeat.begin() + nextSeatIndex, v[i].nextSeat);
			}
			else
			{
				int curSeatIndex = lower_bound(moveSeat.begin(), moveSeat.end(), v[i].curSeat) - moveSeat.begin();
				int nextSeatIndex = upper_bound(moveSeat.begin(), moveSeat.end(), v[i].nextSeat) - moveSeat.begin();
				if ((curSeatIndex != 0) && (nextSeatIndex == 0))
				{
					candyCount += 1;
				}
				candyCount += abs(nextSeatIndex - curSeatIndex); //사탕수집
				moveSeat.insert(moveSeat.begin() + nextSeatIndex, v[i].nextSeat); //이사가기
			}
		}
		printf("#%d %lld\n", t, candyCount);
	}
	return 0;
}