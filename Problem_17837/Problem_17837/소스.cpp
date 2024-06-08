#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 13

using namespace std;

// 1 -> right //2 -> left // 3-> up // 4 -> down
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
int N, K;
//0 is white -- 1 is red -- 2 is blud
int map[MAX][MAX];
int t;
int nx, ny;

class horse {
public:
	int num;
	int d;
	horse(int n, int q) {
		this->num = n;
		this->d = q;
	}
};
vector<horse>hm[MAX][MAX];

void changeDirection(horse& h) {
	if (h.d == 1) {
		h.d = 2;
	}
	else if (h.d == 2) {
		h.d = 1;
	}
	else if (h.d == 3) {
		h.d = 4;
	}
	else if (h.d == 4) {
		h.d = 3;
	}
}

void moveHorse(int it, int x, int y, int d, int ht) {
	nx = x + dx[d]; ny = y + dy[d];
	if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 2) {
		changeDirection(hm[x][y][ht]);
		int nd = hm[x][y][ht].d;
		int newx = x + dx[nd];
		int newy = y + dy[nd];
		if (newx < 0 || newy < 0 || newx >= N || newy >= N || map[newx][newy] == 2) return;
		moveHorse(it, x, y, hm[x][y][ht].d, ht);
	}
	else if (map[nx][ny] == 0) {
		if (nx == x and ny == y)return;
		for (int i = ht; i < hm[x][y].size(); i++) {
			hm[nx][ny].push_back(hm[x][y][i]);
		}
		hm[x][y].erase(hm[x][y].begin() + ht, hm[x][y].end());
	}
	else if (map[nx][ny] == 1) {
		for (int i = hm[x][y].size() - 1; i >= ht; i--) {
			hm[nx][ny].push_back(hm[x][y][i]);
		}
		hm[x][y].erase(hm[x][y].begin() + ht, hm[x][y].end());
	}

	if (hm[nx][ny].size() >= 4) {
		cout << t;
		exit(0);
	}
	return;
}

void findHorse(int it) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k != hm[i][j].size(); k++) {
				if (hm[i][j][k].num == it) {
					moveHorse(it, i, j, hm[i][j][k].d, k);
					return;
				}
			}
		}
	}
}


void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K;i++) {
		int q, w, e;
		cin >> q >> w >> e;
		q--; w--;
		hm[q][w].push_back(horse(i+1, e));
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	for (t = 1; t <= 1000; t++) {
		for (int i = 1; i <= K; i++) {
			findHorse(i);
		}
	}
	if (t == 1001) {
		cout << -1;
	}
	else {
		cout << t;
	}

	return 0;
}