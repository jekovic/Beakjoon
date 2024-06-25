#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<bool>> vis;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int cnt;
int res_cnt, res_amount;

void input() {
	cin >> N >> M;

	map.assign(N, vector<int>(M, 0));
	vis.assign(N, vector<bool>(M, 0));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}	
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	vis[x][y] = 1;
	q.push({ x, y });
	int count = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (vis[nx][ny]) continue;
			if (map[nx][ny] != -1) continue;
			vis[nx][ny] = true;
			map[nx][ny] = cnt;
			count++;
			q.push({ nx, ny });
		}
	}
	res_amount = max(res_amount, count);
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j]) continue;
			if (map[i][j] == -1) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	res_cnt = cnt;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	cout << res_cnt << '\n' << res_amount;

	return 0;
}