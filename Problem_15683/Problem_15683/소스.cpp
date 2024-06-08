#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 9

using namespace std;

int map[MAX][MAX];
int n, m;
vector<pair<int, int>> cctv;
//down - right - up - left 
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int result = 987654321;

int zero_count() {
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				t++;
			}
		}
	}
	return t;
}

void check(int x, int y, int d) {
	d %= 4;

	while (1) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		x = nx;
		y = ny;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) return;
		if (map[nx][ny] == 6) return;
		if (map[nx][ny] != 0) continue;
		map[nx][ny] = -1;
	}
}

void dfs(int cnt) {
	if (cnt == cctv.size()) {
		int t = zero_count();
		result = min(result, t);
		return;
	}

	int x = cctv[cnt].first;
	int y = cctv[cnt].second;
	int temp[MAX][MAX];


	for (int dir = 0; dir < 4; dir++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = map[i][j];
			}
		}

		if (map[x][y] == 1) {
			check(x, y, dir);
		}
		else if (map[x][y] == 2) {
			check(x, y, dir);
			check(x, y, dir+2);
		}
		else if (map[x][y] == 3) {
			check(x, y, dir);
			check(x, y, dir+1);
		}
		else if (map[x][y] == 4) {
			check(x, y, dir);
			check(x, y, dir+1);
			check(x, y, dir+2);
		}
		else if (map[x][y] == 5) {
			check(x, y, dir);
			check(x, y, dir+1);
			check(x, y, dir+2);
			check(x, y, dir+3);
		}

		dfs(cnt + 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m;j++) {
				map[i][j] = temp[i][j];
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 and map[i][j] != 6) {
				cctv.push_back({ i,j });
			}
		}
	}

	dfs(0);

	cout << result;

	return 0;
}