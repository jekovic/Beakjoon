#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

bool visited[MAX];
vector<int> a[MAX];
int res[MAX];
int cnt = 1;
void bfs(int start) {
	if (visited[start]) return;

	queue<int> q;
	visited[start] = true;
	res[start] = cnt;
	//cout << start << '\n';
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (visited[y]) continue;
			visited[y] = true;
			cnt++;
			res[y] = cnt;
			q.push(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n;i++) {
		sort(a[i].begin(), a[i].end());
	}

	bfs(r);

	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}


	return 0;
}