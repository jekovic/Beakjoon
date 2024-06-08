#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 9

using namespace std;
int map[MAX][MAX];
int n, m;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int temp[MAX][MAX];
bool vis[64];

vector<pair<int, int>> virus;
vector<pair<int, int>> zero;
int res;

void copyarr(int x[MAX][MAX], int y[MAX][MAX]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = y[i][j];
		}
	}
}

void bfs() {
	int arr[MAX][MAX];
	queue<pair<int, int>> q;
	copyarr(arr, temp);

	for (int i = 0; i != virus.size(); i++) {
		int x = virus[i].first;
		int y = virus[i].second;
		q.push({ x,y });
	}

	while (!q.empty()) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = qx + dx[i];
			int ny = qy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = 2;
					q.push({ nx, ny });
				}
			}
			
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			if (arr[i][j] == 0) {
				cnt++;
			}
		}
	}
	res = max(res, cnt);
}

void wall(int cur, int idx) {
	if (cur == 3) {
		copyarr(temp, map);
		int cnt = 0;
		for (int i = 0; i != zero.size(); i++) {
			if (cnt == 3) break;
			if (vis[i]) {
				int x = zero[i].first;
				int y = zero[i].second;
				temp[x][y] = 1;
				cnt++;
			}
		}
		bfs();
		return;
	}

	for (int i = 0; i != zero.size(); i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		wall(cur + 1, i);
		vis[i] = 0;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(map[i][j] == 0) {
				zero.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}
	 
	wall(0, 0);

	cout << res;

	return 0;
}