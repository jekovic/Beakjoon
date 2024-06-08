#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 21

using namespace std;
int n;
int map[MAX][MAX];
int res;

void move(int d) {
	queue<int> q;

	if (d == 0) {	// left
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[i][idx] == 0) {
					map[i][idx] = cur;
				}
				else if (map[i][idx] == cur) {
					map[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					map[i][idx] = cur;
				}
			}

		}
	}

	else if (d == 1) {	//right
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j] != 0) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}

			int idx = n - 1;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[i][idx] == 0) {
					map[i][idx] = cur;
				}
				else if (map[i][idx] == cur) {
					map[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					map[i][idx] = cur;
				}
			}
		}
	}
	else if (d == 2) {	// ¾Æ·¡
		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (map[i][j] != 0) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}

			int idx = n - 1;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[idx][j] == 0) {
					map[idx][j] = cur;
				}
				else if (map[idx][j] == cur) {
					map[idx][j] *= 2;
					idx--;
				}
				else {
					idx--;
					map[idx][j] = cur;
				}
			}
		}
	}
	else if (d == 3) {	//À§
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (map[i][j] != 0) {
					q.push(map[i][j]);
				}
				map[i][j] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int cur = q.front();
				q.pop();

				if (map[idx][j] == 0) {
					map[idx][j] = cur;
				}
				else if (map[idx][j] == cur) {
					map[idx][j] *= 2;
					idx++;
				}
				else {
					idx++;
					map[idx][j] = cur;
				}
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		return;
	}
	int b[MAX][MAX];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		move(i);

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n;k++) {
				res = max(res, map[j][k]);
			}
		}
		
		dfs(cnt + 1);

		for (int j = 0;j < n; j++) {
			for (int k = 0; k < n; k++) {
				map[j][k] = b[j][k];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0);

	cout << res;

	return 0;
}