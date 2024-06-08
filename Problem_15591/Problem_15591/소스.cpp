#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

#define MAX 5001

using namespace std;

int N, Q;
vector<pair<int, int>> map[MAX];

void input() {
	cin >> N >> Q;

	for (int i = 1; i <= N - 1; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		map[q].push_back({ w, e });
		map[w].push_back({ q, e });
	}
}

void bfs(int k, int v) {
	vector<int> visited(N+1, 0);
	visited[v] = true;
	int cnt = 0;

	queue<pair<int, int>> q;
	q.push({ v, k });

	while (!q.empty()) {
		int cur = q.front().first;
		int cur_val = q.front().second;
		q.pop();

		for (int i = 0; i != map[cur].size(); i++) {
			int next = map[cur][i].first;
			int next_dir = map[cur][i].second;

			if (!visited[next] and next_dir >= k)
			{
				visited[next] = true;
				cnt++;
				q.push({ next, next_dir });
			}
		}
	}
	cout << cnt << '\n';
	return;
}


void solve() {
	
	for (int i = 0; i < Q; i++) {
		int q, w;
		cin >> q >> w;
		bfs(q, w);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();
	
	return 0;
}