#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 51

using namespace std;
int res = 10000000;
int map[MAX][MAX];
int temp[MAX][MAX];
int n, m;
int v[11];
int zeros = 0;
vector<pair<int, int>> virus;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void move() {
	queue<pair<int, int>> q;
	memset(temp, -1, sizeof(temp));

	for (int i = 0; i < virus.size(); i++) {
		if (v[i]) {
			q.push({ virus[i].first, virus[i].second });
			temp[virus[i].first][virus[i].second] = 0;
		}
	}
	int c = 0;
	int time = 0;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n)  {
				if (temp[nx][ny] == -1 && map[nx][ny] != 1) {
					q.push({ nx,ny });
					temp[nx][ny] = temp[cur_x][cur_y] + 1;
					if (map[nx][ny] == 0) {
						c++;
						time = temp[nx][ny];
					}
				}
					
			}
		}
	}

	if (c == zeros) {
		res = min(res, time);
	}
}

void dfs(int cnt, int idx) {

	if (cnt == m) {
		move();
		return;
	}

	for (int i = idx; i != virus.size(); i++) {
		if (v[i] == 0) {
			v[i] = 1;
			dfs(cnt + 1, i+1);
			v[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0;i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				virus.push_back({ i, j });
			}
			else if (map[i][j] == 0) {
				zeros++;
			}
		}
	}

	dfs(0, 0);
	
	if (res != 10000000) cout << res;
	else cout << -1;
	
	return 0;
}