#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[101];
int visited[101];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1] = 1;

	while (!q.empty()) {
		int cur = q.front().first;
		int d_cnt = q.front().second;
		q.pop();

		if (cur == 100) {
			cout << d_cnt;
			return;
		}

		for (int i = 1; i <= 6; i++){
			int nx = cur + i;
			int n_dcnt = d_cnt + 1;
			if (nx > 100 || visited[nx]) continue;

			if (map[nx]) {
				nx = map[nx];
			}
			visited[nx] = 1;
			q.push({ nx, n_dcnt });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N+M; i++) {
		int q, w;
		cin >> q >> w;
		map[q] = w;
	}

	bfs();
	
	return 0;
}