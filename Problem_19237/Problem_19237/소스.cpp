#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 21
using namespace std;

int n, m, k;

// 1 up ____ 2 down ____ 3 left ____ 4 right
int dx[] = {0, -1, 1, 0, 0 };
int dy[] = {0, 0, 0, -1, 1 };

struct shark {
	int x;
	int y;
	int dir;
	bool live;
	vector<int> pri[5];
};

struct MAP {
	vector<int> v;
	int smell_time;
	int smell_host;
};

MAP map[MAX][MAX];
shark s[410];

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			if (a != 0) {
				map[i][j].v.push_back(a);
				s[a].x = i;
				s[a].y = j;
			}
			map[i][j].smell_host = 0;
			map[i][j].smell_time = 0;
		}
	}

	for (int t = 1; t <= m; t++) {
		int k;
		cin >> k;
		s[t].dir = k;
		s[t].live = true;
	}

	for (int t = 1; t <= m; t++) {// 상어 갯수
		for (int i = 1; i <= 4; i++) {// 4줄
			for (int j = 1; j <= 4; j++) {// 4개
				int q;
				cin >> q;
				s[t].pri[i].push_back(q);
			}
		}
	}
}

void setting_smell(int time) {
	for (int i = 1; i <= m; i++) {
		if (s[i].live == false) continue;

		int x = s[i].x;
		int y = s[i].y;
		map[x][y].smell_time = time + k;
		map[x][y].smell_host = i;
	}
}

void move_shark(int time) {

	for (int i = 1; i <= m; i++) {
		if (s[i].live == false) continue;
		int x = s[i].x;
		int y = s[i].y;
		map[x][y].v.clear();
	}

	for (int i = 1; i <= m; i++) {
		if (s[i].live == false) continue;

		int x = s[i].x;
		int y = s[i].y;
		int dir = s[i].dir;
		int self_x, self_y, self_dir;
		self_x = self_y = self_dir = -1;
		bool flag = false;

		for (int j = 0; j < s[i].pri[dir].size(); j++) {
			int ndir = s[i].pri[dir][j];
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];
			if (nx >= 0 and ny >= 0 and nx < n and ny < n) {
				if (map[nx][ny].smell_time <= time) {
					flag = true;
					map[nx][ny].v.push_back(i);
					s[i].x = nx;
					s[i].y = ny;
					s[i].dir = ndir;
					break;
				}
				else {
					if (map[nx][ny].smell_host == i) { // 이미 있음
						if (self_x == -1) {
							self_x = nx;
							self_y = ny;
							self_dir = ndir;
						}
					}
				}
			}
		}

		if (flag == false) {
			map[self_x][self_y].v.push_back(i);
			s[i].x = self_x;
			s[i].y = self_y;
			s[i].dir = self_dir;
		}
	}
}

void killing_shark() {
	for (int i = 1; i <= m; i++) {
		if (s[i].live == false) {
			continue;
		}
		int x = s[i].x;
		int y = s[i].y;

		if (map[x][y].v.size() >= 2) {
			sort(map[x][y].v.begin(), map[x][y].v.end());
			int live_num = map[x][y].v[0]; // 작은 숫자 생존

			for (int j = 1; j < map[x][y].v.size(); j++) {
				int shark_num = map[x][y].v[j];
				s[shark_num].live = false;
			}
			map[x][y].v.clear();
			map[x][y].v.push_back(live_num);
			map[x][y].smell_host = live_num;
		}
	}
}
bool check() {
	for (int i = 2; i <= m; i++) {
		if (s[i].live == true) return false;
	}
	return true;
}


void action()
{
	for (int time = 0; time < 1001; time++) {
		if (check() == true) {
			cout << time;
			return;
		}
		setting_smell(time);
		move_shark(time);
		killing_shark();
	}
	cout << -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	action();

	return 0;
}