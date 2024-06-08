#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 50001
#define INF 1e9

using namespace std;

int N, M;
vector<pair<int, int>>  map[MAX];
int d[MAX];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		map[q].push_back({ e, w });
		map[w].push_back({ e, q });
	}
}

void dj() {
	fill(d, d + MAX, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	d[1] = 0;

	while (!pq.empty()) {
		int dis = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i != map[cur].size(); i++) {
			int nextdis = dis + map[cur][i].first;
			int next = map[cur][i].second;

			if (d[next] > nextdis) {
				d[next] = nextdis;
				pq.push({ nextdis, next });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dj();

	cout << d[N];

	return 0;
}