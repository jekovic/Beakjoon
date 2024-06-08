#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 50
using namespace std;

int a[MAX][MAX];
int dx[4] = { 0 , 0 , 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int cnt;
int n, m;
bool visited[MAX][MAX];
vector<int> res;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 0 && ty >= 0 && visited[tx][ty] == false && a[tx][ty] == 1 && tx < m && ty < n) {
			visited[tx][ty] = true;
			cnt++;
			dfs(tx, ty);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int k;
		cin >> m >> n >> k;
		vector<int> temp;
		// init
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
				visited[i][j] = false;
			}
		}
		//----------------------

		for (int i = 0; i < k; i++) {
			int q, w;
			cin >> q >> w;
			a[q][w] = 1;
		}

		for (int g = 0; g < m; g++) {
			for (int h = 0; h < n; h++) {
				if (visited[g][h] == false && a[g][h] == 1) {
					visited[g][h] = true;
					cnt = 1;
					dfs(g, h);
					temp.push_back(cnt);
				}
			}
		}
		res.push_back(temp.size());
	}

	for (int i = 0; i != res.size(); i++) {
		cout << res[i] << '\n';
	}

	return 0;
}