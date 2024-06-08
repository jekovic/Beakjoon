#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

//가로와 세로 혼동하지 말기

int rad[31][11];
int n, m, h; 
int mincnt = 4;

/*
	시작점과 끝점이 같으면 true 다르면 false;	
*/
bool check() {
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 1; j <= h; j++) {
			if (rad[j][pos]) pos++;
			else if (rad[j][pos - 1]) pos--;
		}
		if (pos != i) return false;
	}
	return true;
}

void dfs(int t, int cnt) {
	if (cnt >= mincnt)
		return;
	if (check())
		mincnt = cnt;

	for (int i = t; i <= h;i++) {
		for (int j = 1; j < n; j++) {
			if (rad[i][j] || rad[i][j - 1] || rad[i][j + 1]) continue;

			rad[i][j] = true;
			dfs(i, cnt + 1);
			rad[i][j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;
		rad[q][w] = 1;
	}

	dfs(1, 0);

	if (mincnt > 3) cout << -1;
	else cout << mincnt;

	return 0;
}