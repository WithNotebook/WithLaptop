#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int USING_TICKET = 1;
const int NOT_USING_TICKET = 0;
int N, M, K;
vector<pair<int, long long>> v[10001];
int dist[10001][21];

void dijkstra(int start)
{
	priority_queue<pair<long long, pair<int, int>>> pq;
	pq.push({ 0, {start, 0} });

	while (!pq.empty())
	{
		int cur = pq.top().second.first;
		long long curDist = -pq.top().first;
		int ticketCount = pq.top().second.second;

		pq.pop();
		if (dist[cur][ticketCount] < curDist) continue;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			long long nextDist = curDist + v[cur][i].second;

			if (ticketCount < K)
			{
				if (dist[next][ticketCount + 1] == -1 || 
					dist[next][ticketCount + 1] == curDist)
				{
					dist[next][ticketCount + 1] = curDist;
					pq.push({ -curDist, {next, ticketCount + 1} });
				}
			}

			if (dist[next][ticketCount] > nextDist || dist[next][ticketCount] == -1)
			{
				dist[next][ticketCount] = nextDist;
				pq.push({ -nextDist, {next, ticketCount} });
			}

			/*if (dist[next][j] > nextDist)
			{
				if (ticket != -1)
				{
					dist[next][1] = nextDistUsingTicket;
					pq.push({ -nextDistUsingTicket, {next, 0} });
				}
				pq.push({ -nextDist, {next, ticket} });
				dist[next][0] = nextDist;
			}*/
		}
		
	}
}

int main()
{

	cin >> N >> M >> K;

	int s, e, d;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e >> d;
		v[s].push_back({e, d });
		v[e].push_back({ s, d });
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			dist[i][j] = -1;
		}
	}

	dijkstra(1);

	long long minDist = dist[N][0];

	for (int i = 1; i <= K; i++)
	{
		if (minDist > dist[N][i] && dist[N][i] != -1)
		{
			minDist = dist[N][i];
		}
	}

	cout << minDist << "\n";
	return 0;

}
	