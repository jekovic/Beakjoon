#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 11

using namespace std;

char map[MAX][MAX];
int n, m;

struct Info {
	int rx, ry, bx, by, count;
};
Info start;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0 ,0 };

int visited[MAX][MAX][MAX][MAX];

int bfs()
{
	queue<Info> q;
	q.push(start);
	visited[start.rx][start.ry][start.bx][start.by] = 1;

	int res = -1;

	while (!q.empty()) {
		Info cur = q.front();
		q.pop();

		if (cur.count > 10) break;
		
		if (map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
			res = cur.count;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int q_rx = cur.rx;
			int q_ry = cur.ry;
			int q_bx = cur.bx;
			int q_by = cur.by;

			while (1) {
				if (map[q_rx][q_ry] != '#' && map[q_rx][q_ry] != 'O') {
					q_rx += dx[i];
					q_ry += dy[i];
				}
				else {
					if (map[q_rx][q_ry] == '#') {
						q_rx -= dx[i];
						q_ry -= dy[i];
					}
					break;
				}
			}

			while (1) {
				if (map[q_bx][q_by] != '#' && map[q_bx][q_by] != 'O') {
					q_bx += dx[i];
					q_by += dy[i];
				}
				else {
					if (map[q_bx][q_by] == '#') {
						q_bx -= dx[i];
						q_by -= dy[i];
					}
					break;
				}
			}

			if (q_rx == q_bx && q_ry == q_by) {
				if (map[q_rx][q_ry] != 'O') {
					int red_dis = abs(q_rx - cur.rx) + abs(q_ry - cur.ry);
					int blue_dis = abs(q_bx - cur.bx) + abs(q_by - cur.by);

					if (blue_dis > red_dis) {
						q_bx -= dx[i];
						q_by -= dy[i];
					}
					else {
						q_rx -= dx[i];
						q_ry -= dy[i];
					}
				}
			}

			if (visited[q_rx][q_ry][q_bx][q_by] == 0) {
				visited[q_rx][q_ry][q_bx][q_by] = 1;
				Info next;
				next.rx = q_rx;
				next.ry = q_ry;
				next.bx = q_bx;
				next.by = q_by;

				next.count = cur.count + 1;	

				q.push(next);
			}

		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			else if (map[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
	}
	start.count = 0;

	int k = bfs();

	cout << k;

	return 0;
}