#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 11

using namespace std;

int map[MAX][MAX];
int result = 1e9;
int p[6];

void input() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= 5; i++) {
		p[i] = 5;
	}
}

bool check(int r, int c, int len) {
	for (int i = r; i < r + len; i++) {
		for (int j = c; j < c + len; j++) {
			if (i > 10 || j > 10 || map[i][j] == 0)
				return false;
		}
	}
	return true;
}

void draw(int r, int c, int len, int b) {
	for (int i = r; i < r + len; i++) {
		for (int j = c; j < c + len; j++) {
			map[i][j] = b;
		}
	}
}

void solve(int r, int c, int cnt) {
	if (c == 11) {
		r++;
		c = 0;
	}
	if (r == 11) {
		result = min(result, cnt);
		return;
	}

	if (map[r][c] == 0) {
		solve(r, c + 1, cnt);
		return;
	}

	for (int i = 1; i <= 5; i++) {
		if (check(r, c, i) and p[i] > 0) {
			draw(r, c, i, 0);
			--p[i];
		
			solve(r, c + 1, cnt + 1);

			draw(r, c, i, 1);
			++p[i];
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	
	solve(1, 1, 0);

	if (result == 1e9) {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;
}