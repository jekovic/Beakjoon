#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define MAX 51

using namespace std;

int R, C, T;
int map[MAX][MAX];
vector<pair<int, int>> air_con;
vector<pair<int, int>> dust;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void air_con_do() {
	int up_x = air_con[0].first;
	int up_y = air_con[0].second;

	// 반시계
	int next = 0;
	int cur = 0;

	next = map[up_x][C - 1];
	for (int i = C - 1; i != 1; i--) {
		map[up_x][i] = map[up_x][i - 1];
	}
	map[up_x][1] = 0;
	up_y = C - 1;
	
	for (int i = up_x-1; i != -1; i--) {
		cur = map[i][up_y];
		map[i][up_y] = next;
		next = cur;
	}
	up_x = 0;

	for (int i = up_y-1; i != -1; i--) {
		cur = map[up_x][i];
		map[up_x][i] = next;
		next = cur;
	}
	up_y = 0;

	for (int i = up_x+1; i != air_con[0].first; i++) {
		cur = map[i][up_y];
		map[i][up_y] = next;
		next = cur;
	}
	next = 0;
	cur = 0;

	int down_x = air_con[1].first;
	int down_y = air_con[1].second;

	// 시계
	next = map[down_x][C - 1];
	for (int i = C - 1; i != 1; i--) {
		map[down_x][i] = map[down_x][i - 1];
	}
	map[down_x][1] = 0;
	down_y = C - 1;

	for (int i = down_x+1; i < R; i++) {
		cur = map[i][down_y];
		map[i][down_y] = next;
		next = cur;
	}
	down_x = R-1;

	for (int i = down_y-1; i != -1; i--) {
		cur = map[down_x][i];
		map[down_x][i] = next;
		next = cur;
	}
	down_y = 0;

	for (int i = R - 2; i != air_con[1].first; i--) {
		cur = map[i][down_y];
		map[i][down_y] = next;
		next = cur;
	}
}

void dust_refresh() {
	dust.clear();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1 and map[i][j] != 0) {
				dust.push_back({ i, j });
			}
		}
	}
}

void dust_spread() {
	vector<pair<int, int >> q;
	vector<int> val;

	for (int i = 0; i != dust.size(); i++) {
		q.push_back({ dust[i].first, dust[i].second });
		val.push_back(map[dust[i].first][dust[i].second]);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1)
				map[i][j] = 0;
		}
	}

	for (int i = 0; i != q.size(); i++) {
		int cx = q[i].first;
		int cy = q[i].second;
		int d = val[i];
		int s_d = d;

		vector<pair<int, int>> v;
		int di = 0;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (map[nx][ny] == -1) continue;
			di++;
			v.push_back({ nx, ny });
		}

		s_d /= 5;
		d -= s_d * di;

		for (int i = 0; i != v.size(); i++) {
			map[v[i].first][v[i].second] += s_d;
		}
		map[cx][cy] += d;
	}
}

int count_dust() {
	int result = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != 0 and map[i][j] != -1) {
				result += map[i][j];
			}
		}
	}

	return result;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				air_con.push_back({ i, j });
			}
			else if (map[i][j] != 0) {
				dust.push_back({ i, j });
			}
		}
	}

	while (T--) {
		dust_spread();
		air_con_do();
		dust_refresh();
	}

	cout << count_dust();

	return 0;
}