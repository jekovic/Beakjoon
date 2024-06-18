#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <cmath>
#include <cstring>
#include <deque>

using namespace std;

const int NINF = -987654321;
int N, M;
vector<vector<int>> map;
vector<vector<vector<int>>> res;
int dx[] = { 0, 0, 1 };
int dy[] = { -1, 1, 0 };
vector<vector<int>> vis;

void input() {
	cin >> N >> M;

	map.assign(N + 2, vector<int>(M + 2, 0));
	res.assign(N + 2, vector<vector<int>>(M + 2, vector<int>(3, NINF)));
	vis.assign(N + 1, vector<int>(M + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}

int dfs(int x, int y, int d) {
	if (x == N and y == M)	//as soon as it starts to end
		return map[x][y];

	if (res[x][y][d] != NINF) { // already visit
		return res[x][y][d];
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx  < 1 || ny < 1 || nx > N || ny > M) continue;
		if (vis[nx][ny]) continue;
		vis[nx][ny] = true;
		res[x][y][d] = max(res[x][y][d], map[x][y] + dfs(nx, ny, i));
		vis[nx][ny] = false;
	}

	return res[x][y][d];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	
	vis[1][1] = true;
	cout << dfs(1, 1, 0);

	return 0;
}