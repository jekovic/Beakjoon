#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 502

using namespace std;
int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int result = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void dfs(int y, int x, int cnt, int value) {
	if (cnt == 3) {
		result = max(result, value);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > M || ny > N) continue;
		if (!visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(ny, nx, cnt + 1, value + map[ny][nx]);
			visited[ny][nx] = 0;
		}
	}
}

void count_val() {
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int temp = map[i][j];
			int m = 1001;

			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];	
				temp += map[ny][nx];
				m = min(m, map[ny][nx]);
			}
			temp -= m;
			result = max(result, temp);
		}
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = 1;
			dfs(i, j, 0, map[i][j]);
			visited[i][j] = 0;
		}
	}

	count_val();

	cout << result;

	return 0;
}