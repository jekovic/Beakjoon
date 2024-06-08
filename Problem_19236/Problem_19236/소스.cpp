#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

class fish {
public:
	int x, y;
	bool alive;
	int num, d;
	fish() {}
	fish(int x_, int y_, int q, int w) {
		this->x = x_;
		this->y = y_;
		this->num = q;
		this->d = w;
		this->alive = true;
	}
};
fish f[17];
int f_map[4][4];

//12 -> 10 -> 9 -> ...
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int result;

void change_di(fish& f) {
	f.d++;
	if (f.d == 9) {
		f.d = 1;
	}
}

void dfs(int map[][4], fish v[], int shark_x, int shark_y, int size) {
	int copy_map[4][4];
	fish copy_f[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < 17; i++) {
		copy_f[i] = v[i];
	}

	//물고기 먹기 
	int f_size = copy_map[shark_x][shark_y];
	int shark_d = copy_f[f_size].d;
	copy_f[f_size].alive = false;
	copy_map[shark_x][shark_y] = -1;

	size += f_size;
	result = max(result, size);

	//물고기 위치 변경
	for (int i = 1; i <= 16; i++) {
		if (copy_f[i].alive == false)
			continue;
		int cx = copy_f[i].x;
		int cy = copy_f[i].y;
		int di = copy_f[i].d;
		while (1) {
			int nx = cx + dx[di];
			int ny = cy + dy[di];

			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) {
				change_di(copy_f[i]); // 벗어남
				di = copy_f[i].d;
			}
			else if (nx == shark_x and ny == shark_y) {
				change_di(copy_f[i]); // 상어
				di = copy_f[i].d;
			}
			else {
				if (copy_map[nx][ny] == -1) { //그냥 넣기
					copy_f[i].x = nx;
					copy_f[i].y = ny;
					copy_f[i].d = di;

					copy_map[nx][ny] = i;
					copy_map[cx][cy] = -1;
				}
				else { // 바꾸기
					int tnum = copy_map[nx][ny];
					copy_f[tnum].x = cx;
					copy_f[tnum].y = cy;

					copy_f[i].x = nx;
					copy_f[i].y = ny;
					copy_f[i].d = di;

					copy_map[nx][ny] = i;
					copy_map[cx][cy] = tnum;
				}
				break;
			}
		}
	}//end of for 

	//상어 위치 변경
	for (int step = 1; step <= 3; step++) {
		int nr = shark_x + dx[shark_d] * step;
		int nc = shark_y + dy[shark_d] * step;

		if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4) break;
		if (copy_map[nr][nc] != -1)
			dfs(copy_map, copy_f, nr, nc, size);
	}
}


void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int q, w;
			cin >> q >> w;
			fish tmp(i, j, q, w);
			f_map[i][j] = q;
			f[q] = tmp;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dfs(f_map, f, 0, 0, 0);

	cout << result;

	return 0;
}