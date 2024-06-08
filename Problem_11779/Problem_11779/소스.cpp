#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 1001
#define INF 1e9

using namespace std;

int n, m;
int st, des;

vector<pair<int, int>> map[MAX];
int d[MAX];
int visited[MAX];
int v[MAX];
int route[MAX];

void input() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		map[q].push_back({ e, w });
	}
	cin >> st >> des;

	fill(d, d + n + 1, INF);
}

void dj(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({ 0, start });
	v[start] = true;

	while (!pq.empty()) {
		int dis = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur == des) break;
		if (d[cur] < dis) continue;
		for (int i = 0; i != map[cur].size(); i++) {
			int nextdis = map[cur][i].first + dis;
			int next = map[cur][i].second;
			if (d[next] > nextdis) {
				route[next] = cur;
				d[next] = nextdis;
				pq.push({ nextdis, next });
			}
		}
	}
	cout << d[des] << '\n';
	vector<int> r;
	int t = des;
	r.push_back(des);
	while (1) {
		if (route[t] == 0)
			break;
		r.push_back(route[t]);
		t = route[t];
	}
	cout << r.size() << '\n';
	
	for (int i = r.size() - 1; i >= 0; i--) {
		cout << r[i] << ' ';
	}
}

void dfs(int cur, int cnt, int node)
{
	if (cur == des and cnt == d[des]) {
		cout << node << '\n';
		for (int i = 1; i <= n; i++) {
			if (visited[i]) {
				cout << i << ' ';
			}
		}
		cout << '\n';
		exit(1);
	}
	for (int i = 0; i != map[cur].size(); i++) {
		if (visited[map[cur][i].second]) continue;
		visited[map[cur][i].second] = true;
		dfs(map[cur][i].second, cnt + map[cur][i].first, node+1);
		visited[map[cur][i].second] = false;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dj(st);

	
	
	/*visited[st] = true;
	dfs(st, 0, 1);	
	*/
	/*
	cout << route.size() << '\n';
	for (const auto& r : route) {
		cout << r << ' ';
	}*/

	return 0;
}