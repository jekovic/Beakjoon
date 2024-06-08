#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 10001
#define INF 1e9

using namespace std;

int n, d, c;

vector<pair<int, int>> map[MAX];
int dis[MAX];

void input() {
	cin >> n >> d >> c;

	for (int i = 0; i < d; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		map[b].push_back({ s, a });
	}
	fill(dis, dis + n + 1, INF);
}

void init() {
	for (int i = 0; i <= n; i++) {
		map[i].clear();
	}
	fill(dis, dis + n + 1, 0);
}


void dj() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dis[c] = 0;
	pq.push({ 0, c });

	while (!pq.empty()) {
		int cur_dis = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		//if (dis[cur] < cur_dis) continue;

		for (int i = 0; i != map[cur].size(); i++) {
			int next = map[cur][i].second;
			int nextdis = map[cur][i].first + cur_dis;

			if (dis[next] > nextdis) {
				dis[next] = nextdis;
				pq.push({ nextdis, next });
			}
		}
	}

	int cnt = 0;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] != INF) {
			cnt++;
			ret = max(ret, dis[i]);
		}
	}

	cout << cnt << ' ' << ret << '\n';
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--) {
		input();
		dj();
		init();
	}

	return 0;
}