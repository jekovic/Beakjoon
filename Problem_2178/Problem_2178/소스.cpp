#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 101

using namespace std;
int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int a[MAX][MAX];
int visited[MAX][MAX];
int cnt;
int dist[MAX][MAX];

void bfs(int x, int y) {
	queue < pair<int, int> > q;
	q.push({ x, y });
	visited[x][y] = true;
	dist[x][y] = 1;
	//cnt++;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		int temp = 0;
		for (int i = 0; i < 4; i++) {
			int cx = tx + dx[i];
			int cy = ty + dy[i];
			if (cx > 0 && cy > 0 && visited[cx][cy] == false && a[cx][cy] == 1 && cx <= n && cy <= m) {
				visited[cx][cy] = true;
				//cnt++;
				dist[cx][cy] = dist[tx][ty] + 1;
				q.push({ cx,cy });
			}
		}
	}
}

void dj() {

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1] - 48;
		}
	}

	for (int f = 1; f <= n; f++) {
		for (int h = 1; h <= n; h++) {
			if (a[f][h] == 1 && visited[f][h] == false) {
				bfs(f, h);
			}
		}
	}
	cout << dist[n][m];

	return 0;
}