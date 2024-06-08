#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 301

using namespace std;
int l;
bool visited[MAX][MAX];
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dist[MAX][MAX];
int cnt;
int start_x, start_y, des_x, des_y;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		int cost = dist[tx][ty];
		q.pop();

		if (tx == des_x && ty == des_y) {
			cout << dist[tx][ty] << '\n';
			return;
		}

		for (int j = 0; j < 8; j++) {
			int cx = tx + dx[j];
			int cy = ty + dy[j];
			if (cx >= 0 && cy >= 0 && visited[cx][cy] == false && cx < l && cy < l) {
				visited[cx][cy] = true;
				dist[cx][cy] = cost+1;
				q.push({ cx, cy });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		cin >> l;
		// 초기화 루틴
		for (int i = 0;i < l;i++) {
			for(int j = 0; j < l; j++){
				visited[i][j] = false;
				dist[i][j] = 0;
			}		
		}

		cin >> start_x >> start_y >> des_x >> des_y;

		cnt = 0;

		bfs(start_x, start_y);

	}

	return 0;
}