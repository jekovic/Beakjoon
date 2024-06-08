#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 17

using namespace std;

int map[MAX][MAX];
int N;
int p_count = 1e9;
int result;
// right - 5 o'clock - down
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 1, 0 };

void input() {

	cin >> N; 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
		}
	}
	map[1][1] = 1;
	map[1][2] = 1;
}

//void bfs() {
//	queue<pair<int, int>> q;
//	q.push({ 1, 2 });
//
//	while (!q.empty()) {
//		int cx = q.front().first;
//		int cy = q.front().second;
//		q.pop();
//
//		if (cx == N and cy == N) {
//			result++;
//		}
//
//		for (int i = 0; i < 3; i++) {
//			int nx = cx + dx[i];
//			int ny = cy + dy[i];
//
//			if (nx <1 || ny<1 || nx >N || ny > N) continue;
//			//if (visited[nx][ny]) continue;
//			if (map[nx][ny] == -1) continue;
//			if (i == 2) {
//				int x1 = cx + dx[0];
//				int y1 = cy + dy[0];
//				int x2 = cx + dx[1];
//				int y2 = cy + dy[1];
//				if (map[x1][y1] == -1 || map[x2][y2] == -1) continue;
//			}
//			//visited[nx][ny] = true;
//			q.push({ nx, ny });
//		}
//	}
//}

void dfs(int x, int y,int d,int cnt) {
	if (x == N and y == N) {
		/*if (p_count > cnt) {
			p_count = cnt;
			result = 0;
			result++;
		}
		else if (p_count == cnt) {
			result++;
		}*/
		result++;
		return;
	}

	//action
	if (d == 0) { //가로방향이면 대각선이나 가로만 가능
		for (int i = 0; i < 3; i++) {
			if (i == 2) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <1 || ny<1 || nx >N || ny > N) continue;
			if (map[nx][ny] == -1) continue;
			if (i == 1) {
				int x1 = x + dx[0];
				int y1 = y + dy[0];
				int x2 = x + dx[2];
				int y2 = y + dy[2];
				if (map[x1][y1] == -1 || map[x2][y2] == -1) continue;
			}
			dfs(nx, ny, i, cnt + 1);
		}
	}
	else if (d == 1) { // 대각선 방향이면 모든 방향 가능
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <1 || ny<1 || nx >N || ny > N) continue;
			if (map[nx][ny] == -1) continue;
			if (i == 1) {
				int x1 = x + dx[0];
				int y1 = y + dy[0];
				int x2 = x + dx[2];
				int y2 = y + dy[2];
				if (map[x1][y1] == -1 || map[x2][y2] == -1) continue;
			}
			dfs(nx, ny,i, cnt + 1);
		}
	}
	else if (d == 2) { // 아래방향이면 대각선이나 아래만 가능
		for (int i = 0; i < 3; i++) {
			if (i == 0) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <1 || ny<1 || nx >N || ny > N) continue;
			if (map[nx][ny] == -1) continue;
			if (i == 1) {
				int x1 = x + dx[0];
				int y1 = y + dy[0];
				int x2 = x + dx[2];
				int y2 = y + dy[2];
				if (map[x1][y1] == -1 || map[x2][y2] == -1) continue;
			}
			dfs(nx, ny, i, cnt + 1);
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	/*bfs();*/
	dfs(1, 2, 0, 0);

	cout << result;

	return 0;
}