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
int start_x, start_y;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<vector<int>> v;

void input() {
	cin >> N >> M;

	map.assign(N, vector<int>(M, 0));
	v.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				start_x = i;
				start_y = j;
			}
			else if (map[i][j] == 0) {
				map[i][j] = -1;
			}
			else if (map[i][j] == 1) {
				map[i][j] = 0;
			}
		}
	}
}

void print_res() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] >= 1) {
				--v[i][j];
			}
			else if (v[i][j] == 0 and map[i][j] == 0) {
				v[i][j] = -1;
			}
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	v[start_x][start_y] = 1; 

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] == -1) continue;
			if (v[nx][ny] >= 1) continue;
			v[nx][ny] = v[cx][cy] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bfs();

	print_res();

	return 0;
}