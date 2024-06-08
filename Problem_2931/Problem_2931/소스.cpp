/*
* reference
	https://please-amend.tistory.com/entry/%EB%B0%B1%EC%A4%80-2931%EB%B2%88-%EA%B0%80%EC%8A%A4%EA%B4%80-C-%ED%92%80%EC%9D%B4
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 26

using namespace std;

int R, C;
char map[MAX][MAX];
bool visited[MAX][MAX];
int start_x, start_y;

// up -> left -> down -> right
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
const int up = 0, left = 1, down = 2, right = 3;
char blocks[] = { '|', '-', '+', '1', '2', '3', '4' };
vector<bool> adj[7] = {
	{1, 0, 1, 0},
	{0, 1, 0, 1},
	{1, 1, 1, 1},
	{0, 0, 1, 1},
	{1, 0, 0, 1},
	{1, 1, 0, 0},
	{0, 1, 1, 0}
};

vector<bool> not_connected[MAX][MAX];

vector<bool> getAdjacent(int r, int c) {
	switch (map[r][c]) {
	case '|': return adj[0];
	case '-': return adj[1];
	case '+': return adj[2];
	case '1': return adj[3];
	case '2': return adj[4];
	case '3': return adj[5];
	case '4': return adj[6];
	}
	return {};
}

void checkConnect(int r, int c) {
	auto a = getAdjacent(r, c);

	for (int i = 0; i < 4; i++) {
		if (!a[i]) continue;

		int ar = r + dx[i];
		int ac = c + dy[i];
		if (ar < 1 || ac < 1 || ar > R || ac > C) continue;

		if (map[ar][ac] == '.') not_connected[ar][ac][(i + 2) % 4] = true;
	}
}

char calcBlock(int r, int c) {
	for (int i = 0; i < 7; i++) {
		if (not_connected[r][c] == adj[i]) return blocks[i];
	}
	return 't';
}

void solve() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == '.') continue;
			if (map[i][j] == 'M' || map[i][j] == 'Z') continue;
			checkConnect(i, j);
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k < 4; k++) {
				if (not_connected[i][j][k]) {
					cout << i << ' ' << j << ' ' << calcBlock(i, j);
					return;
				}
			}
		} 
	}
}

void input() {

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			not_connected[i][j].resize(4);
		}
	}

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') {
				start_x = i;
				start_y = j;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	return 0;
}