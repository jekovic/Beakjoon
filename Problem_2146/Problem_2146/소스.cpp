#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> vis;
int res = 1e9;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int idx = 0;

void input() {
	cin >> N;

	map.assign(N, vector<int>(N, 0));
	vis.assign(N, vector<bool>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	vis[x][y] = 1;
	map[x][y] = idx;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (vis[nx][ny]) continue;
			if (map[nx][ny] != -1) continue;
			vis[nx][ny] = 1;
			map[nx][ny] = idx;
			q.push({ nx, ny });
		}
	}
}

void make_island() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j]) continue;
			if (map[i][j] == -1) {
				idx++;
				bfs(i, j);
			}
		}
	}
}

void bfs_2(int x, int y, int cur) {
	vis.assign(N, vector<bool>(N, 0));
	vector<vector<int>> dis(N, vector<int>(N, 1e9));
	queue<pair<int, int>> q;
	vis[x][y] = 1;
	q.push({ x, y });
	dis[x][y] = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (vis[nx][ny]) continue;
			if (map[nx][ny] == cur) continue;
			if (map[nx][ny] == 0) {
				dis[nx][ny] = min(dis[cx][cy] + 1, dis[nx][ny]);
				q.push({ nx, ny });
			}
			else if (map[nx][ny] > 0 and map[nx][ny] != cur) {
				res = min(res, dis[cx][cy]);
				return;
			}
			vis[nx][ny] = 1;
		}
	}
}

void dfs(int x, int y, int cnt, int cur) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (vis[nx][ny]) continue;
		if (map[nx][ny] == cur) continue;
		if (map[nx][ny] == 0) {
			vis[nx][ny] = 1;
			dfs(nx, ny, cnt + 1, cur);
		}
		else if (map[nx][ny] > 0 and map[nx][ny] != cur) {
			res = min(res, cnt);
			return;
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0) {
				bfs_2(i, j, map[i][j]);
			}
		}
	}	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	make_island();

	solve();

	cout << res;

	return 0;
}